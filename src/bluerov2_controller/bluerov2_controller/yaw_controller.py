#!/usr/bin/env python3
import rclpy
import numpy as np
from rclpy.node import Node

from bluerov2_interfaces.msg import Attitude
from bluerov2_interfaces.msg import SetYaw

from std_msgs.msg import UInt16, Float64

class Contyawer(Node):

    def __init__(self):
        super().__init__("yaw_controller")

        # Setup default parameters
        self.declare_parameter("yaw_desired", 0) 
        self.declare_parameter("pwm_max", 1750) 
        self.declare_parameter("pwm_neutral", 1500)            
        self.declare_parameter("kp", 550)    
        self.declare_parameter("kd", 50)    
        self.declare_parameter("enable", True)  

        self.attitude           = [0, 0, 0, 0, 0, 0]                            #[yaw, PITCH, YAW, yawSPEED, PITCHSPEED, YAWSPEED]
        self.pwm_max            = self.get_parameter("pwm_max").value           # Maximum PWM value
        self.pwm_neutral        = self.get_parameter("pwm_neutral").value       # Neutral PWM value
        self.yaw_desired        = self.get_parameter("yaw_desired").value       # Desired pitch setpoint
        self.KP                 = self.get_parameter("kp").value                # Proportional gain constant        
        self.KD                 = self.get_parameter("kd").value                # Derivative gain constant

        self.enable             = self.get_parameter("enable").value   

        # Create subscriber
        self.attitude_sub       = self.create_subscription(Attitude, "/bluerov2/attitude", self.callback_att, 10) 
        self.setyaw_sub        = self.create_subscription(SetYaw, "/settings/yaw/set_yaw", self.callback_set_yaw, 10)
        self.setTarget_sub      = self.create_subscription(Float64, "/settings/yaw/set_target", self.callback_set_target, 10) 

        # Create publisher
        self.yaw_pub           = self.create_publisher(UInt16, "/bluerov2/rc/yaw", 10)

        # Start update loop
        self.create_timer(0.04, self.calculate_pwm)    

    def callback_att(self, msg):       
        self.attitude = [msg.roll,
                         msg.pitch,
                         msg.yaw,
                         msg.rollspeed,
                         msg.pitchspeed,
                         msg.yawspeed]

    def callback_set_yaw(self, msg):       
        if msg.pwm_max < 1500:
            self.pwm_max = 1500
        else:
            self.pwm_max = msg.pwm_max
        self.KP = msg.kp 
        self.KD = msg.kd

        self.enable = msg.enable_yaw_ctrl

    def callback_set_target(self, msg):       
        self.yaw_desired = self.deg2rad(msg.data)

    def deg2rad(self,deg):       
        if deg in range(0,181):
            return (deg * np.pi) / 180 
        if deg in range(181,361):
            return ((deg - 360) * np.pi) / 180

    def control(self, yaw, yawspeed):        
        return self.KP*self.sawtooth(yaw-self.yaw_desired) + self.KD*yawspeed
    
    def saturation(self, pwm):        
        pwm_min = self.pwm_neutral - (self.pwm_max - self.pwm_neutral)
        if pwm > self.pwm_max :
            pwm = self.pwm_max
        if pwm < pwm_min:
            pwm = pwm_min
        return int(pwm)
    
    def sawtooth (self, x):
        """Deal with 2*PI modulo
        
        Input:
        ------
        x: rad 
        """
        return (x+np.pi)%(2*np.pi)-np.pi      
    
    def calculate_pwm(self): 
        msg = UInt16()

        if self.enable:
            yaw = self.attitude[0]
            yawspeed = self.attitude[3]
            u = self.control(yaw, yawspeed)
            pwm = round(self.pwm_neutral - 30 * u)
            pwm = self.saturation(pwm)
            
            msg.data = pwm
        else:
            msg.data = self.pwm_neutral
            
        self.yaw_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)    
    node = Contyawer()
    rclpy.spin(node)        
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
