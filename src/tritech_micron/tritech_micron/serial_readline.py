#!/usr/bin/env python3

class SerialReadline:
    """
    A wrapper for pyserial object to read lines efficiently without high CPU usage.
    
    This class avoids the high CPU usage associated with pyserial's readline() 
    by manually managing the input buffer and checking for line endings.
    It starts reading from the hex value 0x40 and reads a line until hex value 0x0A.
    """

    def __init__(self, serial_obj, node):
        """
        Initialize the SerialReadline wrapper.

        Args:
            serial_obj (serial.Serial): An instance of a pyserial Serial object.
        """
        self.serial_obj = serial_obj
        self.buf = bytearray()
        self.reading_started = False
        self.node = node

    def readline(self):
        """
        Read a line from the serial port starting from 0x40 and ending at 0x0A.

        Returns:
            bytes: The line read from the serial port, including the newline character.
        """
        while True:
            try:
                # Read at least 1 byte but up to 2048 bytes
                data = self.serial_obj.read(max(1, min(2048, self.serial_obj.in_waiting)))
                if not data:
                    continue  # If no data is read, continue the loop

                # Start reading when 0x40 is encountered
                if not self.reading_started:
                    start_index = data.find(b'@')
                    if start_index != -1:
                        self.reading_started = True
                        self.buf.extend(data[start_index:])
                    continue

                # If already started reading, add data to buffer
                self.buf.extend(data)

                # Check for linefeed in the received data
                i = self.buf.find(b'\n')
                if i >= 0:
                    result = self.buf[:i + 1]
                    self.buf = self.buf[i + 1:]
                    self.reading_started = False  # Reset reading flag
                    print(result.hex())
                    return result
            except Exception as e:
                # Handle potential exceptions (e.g., serial port errors)
                self.node.get_logger().error(f"Error reading from serial port: {e}")
                return None


