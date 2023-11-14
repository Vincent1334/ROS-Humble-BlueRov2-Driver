#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from pymavlink import mavutil
import pymavlink.dialects.v20.ardupilotmega as mavlink

from std_msgs.msg import UInt16, Bool
from sensor_msgs.msg import BatteryState
from bluerov2_interfaces.msg import Attitude, Bar30

class Controller(Node):
    
    def __init__(self):
        super().__init__("controller")              

        self.type               = mavlink.MAV_TYPE_GCS              # Operator control unit / ground control station.
        self.autopilot          = mavlink.MAV_AUTOPILOT_INVALID     # No valid autopilot, e.g. a GCS or other MAVLink component.
        self.base_mode          = mavlink.MAV_MODE_PREFLIGHT        # System is not ready to dive, booting, calibrating, etc. No flag is set.
        self.custom_mode        = 0                                 # The new autopilot-specific mode. This field can be ignored by an autopilot.
        self.mavlink_version    = 0                                 # MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version.
        self.heartbeat_period   = 0.02                              # Interval in s, in which a heartbeat message is to be sent.

        self.pitch              = 1500                              # The pitch channel (RC1) refers to the upward or downward tilt of the BlueRov2 HEAVY.            
        self.roll               = 1500                              # The roll channel (RC2) is responsible for the horizontal rotation of the BlueRov2 nose around its longitudinal axis.
        self.throttle           = 1500                              # The Throttle channel (RC3) controls the motor power for the diving characteristics of the BlueRov2.
        self.yaw                = 1500                              # The Yaw channel (RC4) is responsible for the rotation of the BlueRov2 nose around the vertical axis.
        self.forward            = 1500                              # The Forward channel (RC5) is responsible for the forward movement of the BlueRov2.
        self.lateral            = 1500                              # The lateral channel (RC6) concerns the lateral movement of the BlueRov2.
        self.camera_pan         = 1500                              # The Camera Pan channel (RC7) controls the horizontal panning movement of the camera.
        self.camera_tilt        = 1500                              # The Camera Tilt channel (RC8) controls the vertical tilt movement of the camera.
        self.lights             = 1100                              # The Lights Level channel (RC9) controls the intensity or brightness of the light source.

        self.data               = {}                                # Dictionary that stores all sensor data
        
        # Create subscriber
        self.rc_pitch_sub       = self.create_subscription(UInt16, "/bluerov2/rc/pitch", lambda msg: self.rc_callback(msg, 1), 10)
        self.rc_roll_sub        = self.create_subscription(UInt16, "/bluerov2/rc/roll", lambda msg: self.rc_callback(msg, 2), 10)
        self.rc_throttle_sub    = self.create_subscription(UInt16, "/bluerov2/rc/throttle", lambda msg:  self.rc_callback(msg, 3), 10)
        self.rc_yaw_sub         = self.create_subscription(UInt16, "/bluerov2/rc/yaw", lambda msg: self.rc_callback(msg, 4), 10)
        self.rc_forward_sub     = self.create_subscription(UInt16, "/bluerov2/rc/forward", lambda msg: self.rc_callback(msg, 5), 10)
        self.rc_lateral_sub     = self.create_subscription(UInt16, "/bluerov2/rc/lateral", lambda msg: self.rc_callback(msg, 6), 10)
        self.rc_camera_pan_sub  = self.create_subscription(UInt16, "/bluerov2/rc/camera_pan", lambda msg: self.rc_callback(msg, 7), 10)
        self.rc_camera_tilt_sub = self.create_subscription(UInt16, "/bluerov2/rc/camera_tilt", lambda msg: self.rc_callback(msg, 8), 10)
        self.rc_lights_sub      = self.create_subscription(UInt16, "/bluerov2/rc/lights", lambda msg: self.rc_callback(msg, 9), 10)

        self.arm_sub            = self.create_subscription(Bool, "/bluerov2/arm", self.arm_callback, 10)
        
        # Create publischer
        self.battery_pub        = self.create_publisher(BatteryState, "/bluerov2/battery", 10)
        self.arm_pub            = self.create_publisher(Bool, "/bluerov2/arm_status", 10)  
        self.attitude_pub       = self.create_publisher(Attitude, "/bluerov2/attitude", 10)   
        self.bar30_pub          = self.create_publisher(Bar30, "/bluerov2/bar30", 10)             
        
        # Setup connection parameters
        self.declare_parameter("ip", "0.0.0.0") 
        self.declare_parameter("port", 14550)
        self.declare_parameter("baudrate", 115200)         

        self.bluerov_ip = self.get_parameter("ip").value
        self.bluerov_port = self.get_parameter("port").value  
        self.bluerov_baudrate = self.get_parameter("baudrate").value

        self.get_logger().info("Controller for bluerov2 was started successfully!")

        # Create the connection to the bluerov2
        self.connection = mavutil.mavlink_connection("udpin:" + self.bluerov_ip + ":" + str(self.bluerov_port), baudrate=self.bluerov_baudrate)        
        
        self.get_logger().info("Connecting to BlueRov2...")
        self.connection.wait_heartbeat()
        self.get_logger().info("BlueRov2 connection successful!")       

        # convenience
        self.mav        = self.connection.mav
        self.recv_match = self.connection.recv_match
        self.target     = (self.connection.target_system,
                           self.connection.target_component)
        
        # Request data stream
        self.get_logger().info("Request data stream...") 
        self.mav.request_data_stream_send(self.connection.target_system, self.connection.target_component, mavutil.mavlink.MAV_DATA_STREAM_ALL,4, 1)
        
        # Now we are ready to dive :)     
        self.arm()
        #self.clear_motion()

        # Start update loop for bluerov2 commands. Update frequency are 2Hz
        self.get_logger().info("Start sending heartbeat messages...")
        self.create_timer(self.heartbeat_period, self.send_bluerov_commands)
        

    def send_bluerov_commands(self):
        # Send regular heartbeats, as a ground control station    
        self.connection.mav.heartbeat_send(self.type, 
                                           self.autopilot, 
                                           self.base_mode, 
                                           self.custom_mode, 
                                           self.mavlink_version)
        
        # Send RC channel updates
        rc_channel_values = (self.pitch,
                             self.roll,
                             self.throttle,
                             self.yaw,
                             self.forward,
                             self.lateral,
                             self.camera_pan,
                             self.camera_tilt,
                             self.lights,
                             65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535) # Unused RC channels are ignored        

        self.mav.rc_channels_override_send(*self.target, *rc_channel_values)

        # Request sensor data
        self.read_param()

        # Publish sensor data
        if len(self.data) != 0:
            self.decode_param()    

        # Publish arm status
        msg = Bool()
           

    def read_param(self):        
        msgs = []
        while True:
            msg = self.recv_match()
            if msg != None:
                msgs.append(msg)
            else:
                break

        for msg in msgs:
            self.data[msg.get_type()] = msg.to_dict()        

    def decode_param(self):
        def get_data(key):
            if key not in self.data:
                self.get_logger().info(f'no {key} data')
                return None
            return self.data[key]

        def publish_attitude():
            attitude_data = get_data('ATTITUDE')
            if attitude_data is not None:
                msg = Attitude()
                msg.time_boot_ms = attitude_data['time_boot_ms']
                msg.roll, msg.pitch, msg.yaw = attitude_data['roll'], attitude_data['pitch'], attitude_data['yaw']
                msg.rollspeed, msg.pitchspeed, msg.yawspeed = attitude_data['rollspeed'], attitude_data['pitchspeed'], attitude_data['yawspeed']
                self.attitude_pub.publish(msg)

        def publish_bar30():
            bar30_data = get_data('SCALED_PRESSURE2')
            if bar30_data is not None:
                msg = Bar30()
                msg.time_boot_ms = bar30_data['time_boot_ms']
                msg.press_abs, msg.press_diff, msg.temperature = bar30_data['press_abs'], bar30_data['press_diff'], bar30_data['temperature']
                self.bar30_pub.publish(msg)

        def publish_battery():
            sys_status = get_data('SYS_STATUS')
            battery_status = get_data('BATTERY_STATUS')

            if sys_status is not None and battery_status is not None:
                bat = BatteryState()
                bat.voltage = sys_status['voltage_battery'] / 1000
                bat.current = sys_status['current_battery'] / 100
                bat.percentage = battery_status['battery_remaining'] / 100
                self.battery_pub.publish(bat)

        publish_attitude()
        publish_bar30()
        publish_battery()

    
    def arm(self):
        self.connection.arducopter_arm()
        self.get_logger().info('Arm requested, waiting...')
        self.connection.motors_armed_wait()
        self.get_logger().info('Thrusters armed!')

    def disarm(self):
        self.connection.arducopter_disarm()
        self.get_logger().info('disarm requested, waiting...')
        self.connection.motors_disarmed_wait()
        self.get_logger().info('Thrusters disarmed')    

    def clear_motion(self):
        ''' Sets all 8 motion direction RC inputs to 'stopped_pwm'. '''
        self.get_logger().info('clear_motion...')

        self.pitch              = 1500
        self.roll               = 1500
        self.throttle           = 1500
        self.yaw                = 1500
        self.forward            = 1500
        self.lateral            = 1500
        self.camera_pan         = 1500
        self.camera_tilt        = 1500

        rc_channel_values = (self.pitch,
                             self.roll,
                             self.throttle,
                             self.yaw,
                             self.forward,
                             self.lateral,
                             self.camera_pan,
                             self.camera_tilt,
                             self.lights,
                             65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535) # Unused RC channels are ignored        

        self.mav.rc_channels_override_send(*self.target, *rc_channel_values)        

    def rc_callback(self, msg, topic):
        match topic:
            case 1: self.pitch          = msg.data
            case 2: self.roll           = msg.data
            case 3: self.throttle       = msg.data
            case 4: self.yaw            = msg.data
            case 5: self.forward        = msg.data
            case 6: self.lateral        = msg.data
            case 7: self.camera_pan     = msg.data
            case 8: self.camera_tilt    = msg.data
            case 9: self.lights         = msg.data

    def arm_callback(self, msg):
        if msg.data:
            self.arm()
        else:
            self.disarm()
        

def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)    

    node.clear_motion()
    node.disarm()
    node.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
