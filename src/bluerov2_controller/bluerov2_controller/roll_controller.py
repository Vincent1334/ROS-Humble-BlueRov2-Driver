#!/usr/bin/env python3
import rclpy
import json
from rclpy.node import Node
import bluerov2_controller.pid as pid

from bluerov2_interfaces.msg import Attitude, PID
from std_msgs.msg import UInt16, Float64, Bool,String

class Controller(Node):

    def __init__(self):
        super().__init__("roll_controller")

        # Setup default parameters
        self.declare_parameter("roll_desired", 0) 
        self.declare_parameter("pwm_max", 1750) 
        self.declare_parameter("pwm_neutral", 1500)            
        self.declare_parameter("kp", 550)    
        self.declare_parameter("kd", 50)    
        self.declare_parameter("enable", True)  

        self.attitude           = [0, 0, 0, 0, 0, 0]                            #[ROLL, PITCH, YAW, ROLLSPEED, PITCHSPEED, YAWSPEED]
        self.pwm_max            = self.get_parameter("pwm_max").value           # Maximum PWM value
        self.pwm_neutral        = self.get_parameter("pwm_neutral").value       # Neutral PWM value
        self.roll_desired       = self.get_parameter("roll_desired").value      # Desired pitch setpoint
        self.KP                 = self.get_parameter("kp").value                # Proportional gain constant        
        self.KD                 = self.get_parameter("kd").value                # Derivative gain constant

        self.enable             = self.get_parameter("enable").value   

        # Create subscriber
        self.attitude_sub       = self.create_subscription(Attitude, "/bluerov2/attitude", self.callback_att, 10) 
        self.setRoll_sub        = self.create_subscription(Float64, "/settings/roll/set_roll", self.callback_set_roll, 10)
        self.setPID_sub         = self.create_subscription(PID, "/settings/roll/set_pid", self.callback_set_pid, 10) 
        self.setEnable_sub      = self.create_subscription(Bool, "/settings/roll/set_enable", self.callback_set_enable, 10) 

        # Create publisher
        self.roll_pub           = self.create_publisher(UInt16, "/bluerov2/rc/roll", 10)
        self.status_pub         = self.create_publisher(String, '/settings/roll/status', 10)      

        self.get_logger().info('controller has been successfully configured!')

        # Start update loop
        self.create_timer(0.04, self.calculate_pwm)    

    def callback_att(self, msg):       
        self.attitude = [msg.roll,
                         msg.pitch,
                         msg.yaw,
                         msg.rollspeed,
                         msg.pitchspeed,
                         msg.yawspeed]

    def callback_set_pid(self, msg):       
        """Read data from '/settings/roll/set_pid'

        ROS message:
        ------------        
        uint16 pwm_max 
        uint32 KI
        uint32 KP
        uint32 KD
        """
        if msg.pwm_max != 65535:
            if msg.pwm_max < 1500:
                self.pwm_max = 1500
            else:
                self.pwm_max = msg.pwm_max

        self.KP = msg.kp if not msg.kp == 65535 else self.KP          
        self.KD = msg.kd if not msg.kd == 65535 else self.KD

    def callback_set_roll(self, msg):
        """Read data from '/settings/roll/set_roll'

        ROS message:
        ------------        
        float64 data
        """       
        self.roll_desired = round(msg.data)         

    def callback_set_enable(self, msg):
        """Read data from '/settings/pitch/set_enable'

        ROS message:
        ------------        
        bool data
        """
        self.enable = msg.data  

    def update_status(self):
        msg = String()
        data = {}
        data["type"]            = "roll_controller"
        data["enable"]          = self.enable
        data["kp"]              = self.KP        
        data["kd"]              = self.KD
        data["pwm_max"]         = self.pwm_max
        data["pwm_neutral"]     = self.pwm_neutral
        data["roll_desired"]    = self.roll_desired

        msg.data = json.dumps(data)
        self.status_pub.publish(msg)        

    def control(self, roll, rollspeed):        
        return self.KP*pid.sawtooth(roll-pid.deg2rad(self.roll_desired)) + self.KD*rollspeed   
    
    def calculate_pwm(self): 
        msg = UInt16()

        if self.enable:
            roll = self.attitude[0]
            rollspeed = self.attitude[3]
            u = self.control(roll, rollspeed)
            pwm = self.pwm_neutral - u
            pwm = pid.saturation(pwm, self.pwm_neutral, self.pwm_max)
            
            msg.data = pwm
        else:
            msg.data = self.pwm_neutral
        
        self.roll_pub.publish(msg)
        self.update_status()

def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)        
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()