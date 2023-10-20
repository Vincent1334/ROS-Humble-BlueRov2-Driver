#!/usr/bin/env python3
"""Tritech Micron sonar."""

from rclpy.node import Node
import serial
import datetime
import bitstring
import tritech_micron.exceptions
from tritech_micron.socket import Socket
from tritech_micron.messages import Message
from tritech_micron.tools import ScanSlice, to_radians, to_sonar_angles

__author__ = "Anass Al-Wohoush"


class TritechMicron(object):

    """Tritech Micron sonar.

    In order for attribute changes to immediately be reflected on the device,
    use the set() method with the appropriate keyword.

    For example, to setup a 20 m sector scan:

        with TritechMicron() as sonar:
            sonar.set(continuous=False, range=20)

    All angles are in radians and headings are relative to the blue LED. So, if
    the sonar were not inverted, 0 radians would be facing forward.

    Attributes:
        ad_high: Amplitude in db to be mapped to max intensity (0-80 db).
        ad_low: Amplitude in dB to be mapped to 0 intensity (0-80 db).
        adc8on: True if 8-bit resolution ADC, otherwise 4-bit.
        centred: Whether the sonar motor is centred.
        clock: Sonar time of the day.
        conn: Serial connection.
        continuous: True if continuous scan, otherwise sector scan.
        gain: Initial gain percentage (0.00-1.00).
        has_cfg: Whether the sonar has acknowledged with mtBBUserData.
        heading: Current sonar heading in radians.
        initialized: Whether the sonar has been initialized with parameters.
        inverted: Whether the sonar is mounted upside down.
        left_limit: Left limit of sector scan in radians.
        mo_time: High speed limit of the motor in units of 10 microseconds.
        motoring: Whether the sonar motor is moving.
        motor_on: Whether device is powered and motor is primed.
        nbins: Number of bins per scan line.
        no_params: Whether the sonar needs parameters before it can scan.
        up_time: Sonar up time.
        port: Serial port.
        range: Scan range in meters.
        recentering: Whether the sonar is recentering its motor.
        right_limit: Right limit of sector scans in radians.
        scanning: Whether the sonar is scanning.
        scanright: Whether the sonar scanning direction is clockwise.
        speed: Speed of sound in medium.
        step: Mechanical resolution (Resolution enumeration).
    """

    def __init__(self, port="/dev/sonar", node=Node, **kwargs):
        """Constructs Sonar object.

        Args:
            port: Serial port (default: /dev/sonar).
            kwargs: Key-word arguments to pass to set() on initialization.
        """

        # ROS node
        self.node = node
        # Parameter defaults.
        self.ad_high = 80.0
        self.ad_low = 0.00
        self.adc8on = True
        self.continuous = True
        self.gain = 0.50
        self.inverted = False
        self.left_limit = to_radians(2400)
        self.mo_time = 250
        self.nbins = 400
        self.range = 10.00
        self.right_limit = to_radians(4000)
        self.scanright = True
        self.speed = 1500.0
        self.step = Resolution.LOW        

        # Connection properties.
        self.port = port
        self.conn = None
        self.initialized = False

        # Head info.
        self.centred = False
        self.has_cfg = False
        self.heading = None
        self.motor_on = False
        self.motoring = False
        self.no_params = True
        self.up_time = datetime.timedelta(0)
        self.recentering = False
        self.scanning = False

        # Additional properties.
        self.clock = datetime.timedelta(0)
        self._time_offset = datetime.timedelta(0)
        self.preempted = False

    def __enter__(self):
        """Initializes sonar for first use.

        Raises:
            SonarNotFound: Sonar port could not be opened.
        """
        self.open()
        return self

    def __exit__(self, type, value, traceback):
        """Cleans up."""
        self.close()

    def open(self):
        """Initializes sonar connection and sets default properties.

        Raises:
            SonarNotFound: Sonar port could not be opened.
        """
        if not self.conn:
            try:
                self.conn = Socket(self.port)
            except OSError as e:
                raise tritech_micron.exceptions.SonarNotFound(self.port, e)

        # Update properties.
        self.node.get_logger().info(f"Initializing sonar on {self.port}")
        self.initialized = True

        # Reboot to make sure the sonar is clean.
        self.send(Message.REBOOT)
        self.update()

        # Set default properties.
        self.set(force=True)

        self.node.get_logger().info("Reboot to make sure the sonar is clean.")

        # Wait for settings to go through.
        while not self.has_cfg or self.no_params:
            self.node.get_logger().info(f"Waiting for configuration: (HAS CFG: {self.has_cfg}, NO PARAMS: {self.no_params})")
            self.update()

        self.node.get_logger().info("Sonar is ready for use")

    def close(self):
        """Closes sonar connection."""
        # Reboot first to clear sonar of all parameters.
        self.send(Message.REBOOT)
        self.conn.close()
        self.initialized = False
        self.node.get_logger().info("Closed sonar socket")

    def get(self, message=None, wait=2):
        """Sends command and returns reply.

        Args:
            message: Message to expect (default: first to come in).
            wait: Seconds to wait until received if a specific message is
                required (default: 2).

        Returns:
            Reply.

        Raises:
            SonarNotInitialized: Attempt reading serial without opening port.
            TimeoutError: Process timed out while waiting for specific message.
        """
        # Verify sonar is initialized.
        if not self.initialized:
            raise tritech_micron.exceptions.SonarNotInitialized()

        expected_name = None
        if message:
            expected_name = Message.to_string(message)
            self.node.get_logger().debug(f"Waiting for {expected_name} message")

        # Determine end time.
        end = datetime.datetime.now() + datetime.timedelta(seconds=wait)

        # Wait until received if a specific message ID is requested, otherwise
        # wait forever.
        while message is None or datetime.datetime.now() < end:
            try:
                reply = self.conn.get_reply()

                # Update state if mtAlive.
                if reply.id == Message.ALIVE:
                    self.__update_state(reply)

                # If first was asked, respond immediately.
                if message is None:
                    return reply

                # Otherwise, verify reply ID.
                if reply.id == message:
                    self.node.get_logger().debug(f"Found {expected_name} message")
                    return reply
                elif reply.id != Message.ALIVE:
                    self.node.get_logger().warning(f"Received unexpected {reply.name} message")
            except tritech_micron.exceptions.PacketCorrupted:
                # Keep trying.
                continue

        # Timeout.
        self.node.get_logger().error(f"Timed out before receiving message: {expected_name}")
        raise tritech_micron.exceptions.TimeoutError()

    def send(self, command, payload=None):
        """Sends command and returns reply.

        Args:
            command: Command to send.

        Raises:
            SonarNotInitialized: Attempt sending command without opening port.
        """
        if not self.initialized:
            raise tritech_micron.exceptions.SonarNotInitialized(command, payload)

        self.conn.send(command, payload)

    def set(self,
            adc8on=None,
            continuous=None,
            scanright=None,
            step=None,
            ad_low=None,
            ad_high=None,
            left_limit=None,
            right_limit=None,
            mo_time=None,
            range=None,
            nbins=None,
            gain=None,
            speed=None,
            inverted=None,
            force=False):
        """Sends Sonar head command with new properties if needed.

        Only the parameters specified will be modified.

        If initialized, arguments are compared to current properties in order
        to see if sending the command is necessary.

        Args:
            ad_low: Amplitude in dB to be mapped to 0 intensity (0-80 db).
            ad_high: Amplitude in db to be mapped to max intensity (0-80 db).
            adc8on: True if 8-bit resolution ADC, otherwise 4-bit.
            continuous: True if continuous scan, otherwise sector scan.
            gain: Initial gain percentage (0.00-1.00).
            inverted: Whether the sonar is mounted upside down.
            left_limit: Left limit of sector scan in radians.
            mo_time: High speed limit of the motor in units of 10 microseconds.
            nbins: Number of bins per scan line.
            range: Scan range in meters.
            right_limit: Right limit of sector scans in radians.
            scanright: Whether the sonar scanning direction is clockwise.
            speed: Speed of sound in medium.
            step: Mechanical resolution (Resolution enumeration).
            force: Whether to force setting the parameters or not.

        Raises:
            SonarNotInitialized: Sonar is not initialized.
        """
        if not self.initialized:
            raise tritech_micron.exceptions.SonarNotInitialized()

        self.__set_parameters(
            adc8on=adc8on,
            continuous=continuous,
            scanright=scanright,
            step=step,
            ad_low=ad_low,
            ad_high=ad_high,
            left_limit=left_limit,
            right_limit=right_limit,
            mo_time=mo_time,
            range=range,
            nbins=nbins,
            gain=gain,
            speed=speed,
            inverted=inverted,
            force=force)

    def __set_parameters(self, force, **kwargs):
        """Sends Sonar head command to set sonar properties.

        Only the parameters specified will be modified.

        If initialized, arguments are compared to current properties in order
        to see if sending the command is necessary.

        Args:
            force: Whether to force set parameters.
            See set().
        """
        self.node.get_logger().warning("Setting parameters...")

        # Set and compare sonar properties.
        necessary = not self.has_cfg or self.no_params or force
        only_reverse = not necessary
        for key, value in kwargs.iteritems():
            if value is not None:
                if hasattr(self, key) and self.__getattribute__(key) != value:
                    self.__setattr__(key, value)
                    necessary = True
                    if key != "scanright":
                        only_reverse = False

        # Return if unnecessary.
        if not necessary:
            self.node.get_logger().warning("Parameters are already set")
            return

        # Return if only switching the motor's direction is necessary.
        if only_reverse:
            self.node.get_logger().warning("Only reversing direction")
            self.scanright = not self.scanright
            return self.reverse()

        # Log properties.
        self.node.get_logger().info(f"CONTINUOUS:  {self.continuous}")
        self.node.get_logger().info(f"LEFT LIMIT:  {self.left_limit} rad")
        self.node.get_logger().info(f"RIGHT LIMIT: {self.right_limit} rad")
        self.node.get_logger().info(f"STEP SIZE:   {self.step} rad")
        self.node.get_logger().info(f"N BINS:      {self.nbins}")
        self.node.get_logger().info(f"RANGE:       {self.range} m")
        self.node.get_logger().info(f"INVERTED:    {self.inverted}")
        self.node.get_logger().info(f"AD HIGH:     {self.ad_high} dB")
        self.node.get_logger().info(f"AD LOW:      {self.ad_low} dB")
        self.node.get_logger().info(f"ADC 8 ON:    {self.adc8on}")
        self.node.get_logger().info(f"GAIN:        {self.gain * 100}%%")
        self.node.get_logger().info(f"MOTOR TIME:  {self.mo_time} us")
        self.node.get_logger().info(f"CLOCKWISE:   {self.scanright}")
        self.node.get_logger().info(f"SPEED:       {self.speed} m/s")

        # This device is not Dual Channel so skip the “V3B” Gain Parameter
        # block: 0x01 for normal, 0x1D for extended V3B Gain Parameters.
        v3b = bitstring.pack("0x01")

        # Construct the HdCtrl bytes to control operation:
        #   Bit 0:  adc8on          0: 4-bit        1: 8-bit
        #   Bit 1:  cont            0: sector-scan  1: continuous
        #   Bit 2:  scanright       0: left         1: right
        #   Bit 3:  invert          0: upright      1: inverted
        #   Bit 4:  motoff          0: on           1: off
        #   Bit 5:  txoff           0: on           1: off (for testing)
        #   Bit 6:  spare           0: default      1: N/A
        #   Bit 7:  chan2           0: default      1: N/A
        #   Bit 8:  raw             0: N/A          1: default
        #   Bit 9:  hasmot          0: lol          1: has a motor (always)
        #   Bit 10: applyoffset     0: default      1: heading offset
        #   Bit 11: pingpong        0: default      1: side-scanning sonar
        #   Bit 12: stareLLim       0: default      1: N/A
        #   Bit 13: ReplyASL        0: N/A          1: default
        #   Bit 14: ReplyThr        0: default      1: N/A
        #   Bit 15: IgnoreSensor    0: default      1: emergencies
        hd_ctrl = bitstring.pack("0b001000110000, bool, bool, bool, bool",
                                 self.inverted, self.scanright, self.continuous,
                                 self.adc8on)
        hd_ctrl.byteswap()  # Little endian please.

        # Set the sonar type: 0x11 for DST.
        hd_type = bitstring.pack("0x11")

        # TX/RX transmitter constants: N/A to DST so fill with 15 zero bytes.
        # TX pulse length: N/A to DST so fill with 2 zero bytes.
        tx_rx = bitstring.BitStream(144)

        # Range scale does not control the sonar, only provides a way to note
        # the current settings in a human readable format.
        # The lower 14 bits are the range scale * 10 units and the higher 2
        # bits are coded units:
        #   0: meters
        #   1: feet
        #   2: fathoms
        #   3: yards
        # Only the metric system is implemented for now, because it is better.
        range_scale = bitstring.pack("uintle:16", int(self.range * 10))

        # Left/right angles limits are in 1/16th of a gradian.
        _left_angle = to_sonar_angles(self.left_limit)
        _right_angle = to_sonar_angles(self.right_limit)
        left_limit = bitstring.pack("uintle:16", _left_angle)
        right_limit = bitstring.pack("uintle:16", _right_angle)

        # Set the mapping of the received sonar echo amplitudes.
        # If the ADC is set to 8-bit, MAX = 255 else MAX = 15.
        # ADLow = MAX * low / 80 where low is the desired minimum amplitude.
        # ADSpan = MAX * range / 80 where range is the desired amplitude range.
        # The full range is between ADLow and ADLow + ADSpan.
        MAX_SIZE = 255 if self.adc8on else 15
        ad_low = bitstring.pack("uint:8", int(MAX_SIZE * self.ad_low / 80))
        _ad_diff = self.ad_high - self.ad_low
        ad_span = bitstring.pack("uint:8", int(MAX_SIZE * _ad_diff / 80))

        # Set the initial gain of each channel of the sonar receiver.
        # The gain ranges from 0 to 210.
        _mapped_gain = int(self.gain * 210)
        gain = bitstring.pack("uint:8, uint:8", _mapped_gain, _mapped_gain)

        # Slope setting is N/A to DST: fill 4 bytes with zeroes.
        slope = bitstring.BitStream(32)

        # Set the high speed limit of the motor in units of 10 microseconds.
        mo_time = bitstring.pack("uint:8", int(self.mo_time / 10))

        # Set the step angle size in 1/16th of a gradian.
        #   32: low resolution
        #   16: medium resolution
        #   8:  high resolution
        #   4:  ultimate resolution
        _step_size = to_sonar_angles(self.step)
        step = bitstring.pack("uint:8", _step_size)

        # ADInterval defines the sampling interval of each bin and is in units
        # of 640 nanoseconds.
        nbins = bitstring.pack("uintle:16", self.nbins)
        _interval = 2 * self.range / self.speed / self.nbins / 640e-9
        _interval = _interval + 1 if _interval % 2 else _interval
        ad_interval = bitstring.pack("uintle:16", int(_interval))

        # Factory defaults. Don't ask.
        max_ad_buf = bitstring.pack("uintle:16", 500)
        lockout = bitstring.pack("uintle:16", 100)
        minor_axis = bitstring.pack("uintle:16", 1600)
        major_axis = bitstring.pack("uint:8", 1)

        # Ctl2 is for testing.
        ctl2 = bitstring.pack("uint:8", 0)

        # Special devices setting. Should be left blank.
        scanz = bitstring.pack("uint:8, uint:8", 0, 0)

        # Order and construct bitstream.
        bitstream = (v3b, hd_ctrl, hd_type, tx_rx, range_scale, left_limit,
                     right_limit, ad_span, ad_low, gain, slope, mo_time, step,
                     ad_interval, nbins, max_ad_buf, lockout, minor_axis,
                     major_axis, ctl2, scanz)
        payload = bitstring.BitStream()
        for chunk in bitstream:
            payload.append(chunk)

        self.send(Message.HEAD_COMMAND, payload)
        self.node.get_logger().warning("Parameters are sent")

    def reverse(self):
        """Instantaneously reverses scan direction."""
        payload = bitstring.pack("0x0F")
        self.send(Message.HEAD_COMMAND, payload)
        self.scanright = not self.scanright

    def _ping(self):
        """Commands the sonar to ping once."""
        # Get current time in milliseconds.
        now = datetime.datetime.now()
        current_time = datetime.timedelta(
            hours=now.hour,
            minutes=now.minute,
            seconds=now.second,
            microseconds=0)
        payload = bitstring.pack("uintle:32",
                                 current_time.total_seconds() * 1000)

        # Reset offset for up time.
        self._time_offset = current_time - self.up_time

        # Send command.
        self.send(Message.SEND_DATA, payload)

    def __parse_head_data(self, data):
        """Parses mtHeadData payload and returns parsed bins.

        Args:
            data: mtHeadData bitstring.

        Returns:
            Bins.

        Raise:
            ValueError: If data could not be parsed.
        """
        # Any number of exceptions could occur here if the packet is corrupted,
        # so a catch-all approach is used for safety.
        try:
            # Get the total number of bytes.
            count = data.read(16).uintle
            self.node.get_logger().debug(f"Byte count is {count}")

            # The device type should be 0x11 for a DST Sonar.
            device_type = data.read(8)
            if device_type.uint != 0x11:
                # Packet is likely corrupted, try again.
                raise ValueError("Unexpected device type: {}".format(
                    device_type.hex))

            # Get the head status byte:
            #   Bit 0:  'HdPwrLoss'. Head is in Reset Condition.
            #   Bit 1:  'MotErr'. Motor has lost sync, re-send Parameters.
            #   Bit 2:  'PrfSyncErr'. Always 0.
            #   Bit 3:  'PrfPingErr'. Always 0.
            #   Bit 4:  Whether adc8on is enabled.
            #   Bit 5:  RESERVED (ignore).
            #   Bit 6:  RESERVED (ignore).
            #   Bit 7:  Message appended after last packet data reply.
            _head_status = data.read(8)
            self.node.get_logger().debug(f"Head status byte is {_head_status}")
            if _head_status[-1]:
                self.node.get_logger().error("Head power loss detected")
            if _head_status[-2]:
                self.node.get_logger().error("Motor lost sync")
                self.set(force=True)

            # Get the sweep code. Its value should correspond to:
            #   0: Scanning normal.
            #   1: Scan at left limit.
            #   2: Scan at right limit.
            #   3: RESERVED (ignore).
            #   4: RESERVED (ignore)
            #   5: Scan at center position.
            sweep = data.read(8).uint
            self.node.get_logger().debug(f"Sweep code is {sweep}")
            if sweep == 1:
                self.node.get_logger().info("Reached left limit")
            elif sweep == 2:
                self.node.get_logger().info("Reached right limit")

            # Get the HdCtrl bytes to control operation:
            #   Bit 0:  adc8on          0: 4-bit        1: 8-bit
            #   Bit 1:  cont            0: sector-scan  1: continuous
            #   Bit 2:  scanright       0: left         1: right
            #   Bit 3:  invert          0: upright      1: inverted
            #   Bit 4:  motoff          0: on           1: off
            #   Bit 5:  txoff           0: on           1: off (for testing)
            #   Bit 6:  spare           0: default      1: N/A
            #   Bit 7:  chan2           0: default      1: N/A
            #   Bit 8:  raw             0: N/A          1: default
            #   Bit 9:  hasmot          0: lol          1: has a motor (always)
            #   Bit 10: applyoffset     0: default      1: heading offset
            #   Bit 11: pingpong        0: default      1: side-scanning sonar
            #   Bit 12: stareLLim       0: default      1: N/A
            #   Bit 13: ReplyASL        0: N/A          1: default
            #   Bit 14: ReplyThr        0: default      1: N/A
            #   Bit 15: IgnoreSensor    0: default      1: emergencies
            # Should be the same as what was sent.
            hd_ctrl = data.read(16)
            hd_ctrl.byteswap()  # Little endian please.
            self.inverted, self.scanright, self.continuous, self.adc8on = (
                hd_ctrl.unpack("pad:12, bool, bool, bool, bool"))
            self.node.get_logger().debug(f"Head control bytes are {hd_ctrl.bin}")
            self.node.get_logger().debug(f"ADC8 mode {self.adc8on}")
            self.node.get_logger().debug(f"Continuous mode {self.continuous}")
            self.node.get_logger().debug(f"Scanning right {self.scanright}")

            # Range scale.
            # The lower 14 bits are the range scale * 10 units and the higher 2
            # bits are coded units:
            #   0: meters
            #   1: feet
            #   2: fathoms
            #   3: yards
            # Only the metric system is implemented for now, because it is
            # better.
            self.range = data.read(16).uintle / 10.0
            self.node.get_logger().debug(f"Range scale is {self.range}")

            # TX/RX transmitter constants: N/A to DST.
            data.read(32)

            # The gain ranges from 0 to 210.
            self.gain = data.read(8).uintle / 210.0
            self.node.get_logger().debug(f"Gain is {self.gain}")

            # Slope setting is N/A to DST.
            data.read(16)

            # If the ADC is set to 8-bit, MAX = 255 else MAX = 15.
            # ADLow = MAX * low / 80 where low is the desired minimum
            #   amplitude.
            # ADSpan = MAX * span / 80 where span is the desired amplitude
            #   span.
            # The full range is between ADLow and ADLow + ADSpan.
            MAX_SIZE = 255 if self.adc8on else 15
            ad_span = data.read(8).uintle
            ad_low = data.read(8).uintle
            self.ad_low = ad_low * 80.0 / MAX_SIZE
            span_intensity = ad_span * 80.0 / MAX_SIZE
            self.ad_high = self.ad_low + span_intensity
            self.node.get_logger().debug(f"AD range is {self.ad_low} to {self.ad_high}")

            # Heading offset is ignored.
            heading_offset = to_radians(data.read(16).uint)
            self.node.get_logger().debug(f"Heading offset is {heading_offset}")

            # ADInterval defines the sampling interval of each bin and is in
            # units of 640 nanoseconds.
            ad_interval = data.read(16).uintle
            self.node.get_logger().debug(f"AD interval is {ad_interval}")

            # Left/right angles limits are in 1/16th of a gradian.
            self.left_limit = to_radians(data.read(16).uintle)
            self.right_limit = to_radians(data.read(16).uintle)
            self.node.get_logger().debug(f"Limits are {self.left_limit} to {self.right_limit}")

            # Step angle size.
            self.step = to_radians(data.read(8).uint)
            self.node.get_logger().debug(f"Step size is {self.step}")

            # Heading is in units of 1/16th of a gradian.
            self.heading = to_radians(data.read(16).uintle)
            self.node.get_logger().info(f"Heading is now {self.heading}")

            # Dbytes is the number of bytes with data to follow.
            dbytes = data.read(16).uintle
            if self.adc8on:
                self.nbins = dbytes
                bin_size = 8
            else:
                self.nbins = dbytes * 2
                bin_size = 4
            self.node.get_logger().debug(f"DBytes is {dbytes}")

            # Get bins.
            bins = [data.read(bin_size).uint for i in range(self.nbins)]
        except Exception as e:
            # Damn.
            raise ValueError(e)

        return bins

    def scan(self, callback):
        """Sends scan command.

        This method is blocking but calls callback at every reply with the
        heading and a new dataset.

        To stop a scan, simply call the preempt() method. Otherwise, the scan
        will run forever.

        The intensity at every bin is an integer value ranging between 0 and
        255.

        Args:
            callback: Callback for feedback.
                Called with args=(sonar, slice)
                where sonar is this sonar instance and slice is a SonarSlice
                instance.

        Raises:
            SonarNotInitialized: Sonar is not initialized.
            SonarNotConfigured: Sonar is not configured for scanning.
        """
        # Verify sonar is ready to scan.
        self.update()
        if self.no_params or not self.has_cfg:
            raise tritech_micron.exceptions.SonarNotConfigured(self.no_params, self.has_cfg)

        # Timeout count to keep track of how many failures in a row occured.
        # This will then try to recover by resetting the sonar parameters.
        timeout_count = 0
        MAX_TIMEOUT_COUNT = 5

        # Scan until stopped.
        self.preempted = False
        while not self.preempted:
            # Preempt on ROS shutdown.
            #if rospy.is_shutdown():
            #    self.preempt()
            #    return

            # Ping the sonar.
            self._ping()

            # Get the scan data.
            try:
                data = self.get(Message.HEAD_DATA, wait=1).payload
                timeout_count = 0
            except tritech_micron.exceptions.TimeoutError:
                timeout_count += 1
                self.node.get_logger().debug(f"Timeout count: {timeout_count}")
                if timeout_count >= MAX_TIMEOUT_COUNT:
                    # Try to resend parameters.
                    self.set(force=True)
                    timeout_count = 0
                # Try again.
                continue

            try:
                bins = self.__parse_head_data(data)
            except ValueError as e:
                # Try again.
                self.node.get_logger().error(f"Failed to parse head data: {e}")
                continue

            # Generate configuration.
            config = {
                key: self.__getattribute__(key)
                for key in ("inverted", "continuous", "scanright", "adc8on",
                            "gain", "ad_low", "ad_high", "left_limit",
                            "right_limit", "range", "nbins", "step")
            }

            # Run callback.
            slice = ScanSlice(self.heading, bins, config)
            callback(self, slice)

    def preempt(self):
        """Preempts a scan in progress."""
        self.node.get_logger().warning("Preempting scan...")
        self.preempted = True

    def reboot(self):
        """Reboots Sonar.

        Raises:
            SonarNotInitialized: Sonar is not initialized.
        """
        self.node.get_logger().warning("Rebooting sonar...")
        self.send(Message.REBOOT)
        self.open()

    def update(self):
        """Updates Sonar states from mtAlive message.

        Note: This is a blocking function.

        Raises:
            SonarNotInitialized: Sonar is not initialized.
        """
        # Wait until successful no matter what.
        while True:
            try:
                self.get(Message.ALIVE)
                return
            except tritech_micron.exceptions.TimeoutError:
                continue

    def __update_state(self, alive):
        """Updates Sonar states from mtAlive message.

        Args:
            alive: mtAlive reply.
        """
        payload = alive.payload
        payload.bytepos = 1

        # Get current time and compute up time.
        micros = payload.read(32).uintle * 1000
        self.clock = datetime.timedelta(microseconds=micros)
        if self._time_offset > self.clock:
            self._time_offset = datetime.timedelta(0)
        self.up_time = self.clock - self._time_offset

        # Get heading.
        self.heading = to_radians(payload.read(16).uintle)

        # Decode HeadInf byte.
        head_inf = payload.read(8)
        self.recentering = head_inf[0]
        self.centred = head_inf[1]
        self.motoring = head_inf[2]
        self.motor_on = head_inf[3]
        self.scanright = head_inf[4]
        self.scanning = head_inf[5]
        self.no_params = head_inf[6]
        self.has_cfg = head_inf[7]

        self.node.get_logger().info(f"UP TIME:     {self.up_time}")
        self.node.get_logger().debug(f"RECENTERING: {self.recentering}")
        self.node.get_logger().debug(f"CENTRED:     {self.centred}")
        self.node.get_logger().debug(f"MOTORING:    {self.motoring}")
        self.node.get_logger().debug(f"MOTOR ON:    {self.motor_on}")
        self.node.get_logger().debug(f"CLOCKWISE:   {self.scanright}")
        self.node.get_logger().debug(f"SCANNING:    {self.scanning}")
        self.node.get_logger().debug(f"NO PARAMS:   {self.no_params}")
        self.node.get_logger().debug(f"HAS CFG:     {self.has_cfg}")


class Resolution(object):

    """Sonar mechanical resolution enumeration.

    The mechanical resolution is the angle the step motor rotates per scan line
    in radians. A higher resolution slows down the scan.

    Set as such:

        with TritechMicron() as sonar:
            sonar.set(step=Resolution.LOW)

    Other resolutions can also be used, but these are the ones documented by
    Tritech.
    """
    LOWEST = to_radians(255)  # Not recommended.
    LOWER = to_radians(128)  # Not recommended.
    LOWERISH = to_radians(64)  # Not recommended.
    LOW = to_radians(32)
    MEDIUM = to_radians(16)
    HIGH = to_radians(8)
    ULTIMATE = to_radians(4)