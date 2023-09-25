#!/usr/bin/env python3
import rclpy
import pygame
from pygame.locals import *
from rclpy.node import Node

from std_msgs.msg import UInt16
from std_msgs.msg import Float64
from std_msgs.msg import Bool
from bluerov2_interfaces.msg import SetTarget

class Controller(Node):    
    
    def __init__(self):
        super().__init__("input_controller")  

        # Setup default parameters        
        self.declare_parameter("pwm_max", 1900)
        self.declare_parameter("pwm_min", 1100)
        self.declare_parameter("pwm_neutral", 1500)        
        self.declare_parameter("pwm_camera_max", 1900)
        self.declare_parameter("pwm_camera_min", 1100)
        self.declare_parameter("pwm_lights_max", 1900)
        self.declare_parameter("pwm_lights_min", 1100)
        self.declare_parameter("gain_pwm_cam", 400)     
        self.declare_parameter("gain_pwm_lights", 50)
        self.declare_parameter("gain_depth", 0.2)
        self.declare_parameter("arm_status", True)

        self.pwm_min                = self.get_parameter("pwm_min").value 
        self.pwm_max                = self.get_parameter("pwm_max").value
        self.pwm_neutral            = self.get_parameter("pwm_neutral").value        
        self.pwm_camera_max         = self.get_parameter("pwm_camera_max").value 
        self.pwm_camera_min         = self.get_parameter("pwm_camera_min").value 
        self.pwm_lights_max         = self.get_parameter("pwm_lights_max").value 
        self.pwm_lights_min         = self.get_parameter("pwm_lights_min").value 
        self.gain_depth             = self.get_parameter("gain_depth").value       
        
        self.gain_pwm_cam           = self.get_parameter("gain_pwm_cam").value 
        self.gain_pwm_lights        = self.get_parameter("gain_pwm_lights").value 

        self.lights_value           = self.get_parameter("pwm_lights_min").value
        self.arm                    = self.get_parameter("arm_status").value 
        self.target_depth           = 0             

        # Create publisher
        self.lights_pub             = self.create_publisher(UInt16, "/bluerov2/rc/lights", 10)
        self.camera_tilt_pub        = self.create_publisher(UInt16, "/bluerov2/rc/camera_tilt", 10)
        self.forward_pub            = self.create_publisher(UInt16, "/bluerov2/rc/forward", 10)
        self.lateral_pub            = self.create_publisher(UInt16, "/bluerov2/rc/lateral", 10)
        self.yaw_pub                = self.create_publisher(UInt16, "/bluerov2/rc/yaw", 10) 
        self.arm_pub                = self.create_publisher(Bool, "/bluerov2/arm", 10)
        self.depth_pub              = self.create_publisher(SetTarget, "/settings/set_target", 10)
               

        # Clear BlueRov status
        lights = UInt16()
        lights.data = self.pwm_camera_min
        self.lights_pub.publish(lights)

        arm_msg = Bool()
        arm_msg.data = self.arm
        self.arm_pub.publish(arm_msg)

        cam_pwm = UInt16()
        cam_pwm.data = self.pwm_neutral
        self.camera_tilt_pub.publish(cam_pwm)        

        # Init Gamepad
        pygame.init()        
        self.joysticks = []

        for i in range(0, pygame.joystick.get_count()):
            # create an Joystick object in our list
            self.joysticks.append(pygame.joystick.Joystick(i))
            # initialize the appended joystick (-1 means last array item)
            self.joysticks[-1].init()
            # print a statement telling what the name of the controller is
            self.get_logger().info("Detected joystick")

        # Start update loop
        self.create_timer(0.04, self.update_input)
        

    def update_input(self):
        for event in pygame.event.get():                   
            if event.type == JOYBUTTONDOWN:                
                if event.button == 4:       #LB
                    self.lights_down()
                if event.button == 5:       #RB
                    self.lights_up()   
                if event.button == 7:       #START
                    self.arm_disarm()
                if event.button == 3:        #Y
                    self.dive_up()
                if event.button == 0:        #A
                    self.dive_down()

            if event.type == JOYAXISMOTION:                
                if event.axis == 1:     #DPad Up-Down
                    self.camera_tilt_event(event.value)
                    pass
                if event.axis == 3:     # Right Joystick horizontal
                    self.rotation_event(event.value)
                    pass               

            if event.type == JOYHATMOTION:
                self.move_event(event.value)

    

    def lights_down(self):        
        msg = UInt16()
        if self.lights_value - self.gain_pwm_lights > self.pwm_lights_min:
            msg.data = self.lights_value - self.gain_pwm_lights
        else:
            msg.data = self.pwm_lights_min

        self.lights_value = msg.data
        self.lights_pub.publish(msg)

    def lights_up(self):       
        msg = UInt16()        
        if self.lights_value + self.gain_pwm_lights < self.pwm_lights_max:
            msg.data = self.lights_value + self.gain_pwm_lights
        else:
            msg.data = self.pwm_lights_max

        self.lights_value = msg.data
        self.lights_pub.publish(msg)        

    def camera_tilt_event(self, value):
        msg = UInt16()
        val = round(value)

        if val == -1:
            msg.data = int(self.pwm_camera_max)
        elif val == 1:
            msg.data = int(self.pwm_camera_min)
        elif val == 0:
            msg.data = int(self.pwm_neutral)
        
        self.camera_tilt_pub.publish(msg)    

    def rotation_event(self, value):
        msg = UInt16()        
        msg.data = self.calculate_pwm(value)     
        self.yaw_pub.publish(msg) 

    def move_event(self, value):
        forward_msg = UInt16() 
        lateral_msg = UInt16() 

        forward = value[1]
        lateral = value[0]  
    
        forward_msg.data = self.calculate_pwm_move(forward)     
        lateral_msg.data = self.calculate_pwm_move(lateral) 

        self.forward_pub.publish(forward_msg) 
        self.lateral_pub.publish(lateral_msg)     

    def calculate_pwm(self, value):   
        gain = self.pwm_max-self.pwm_neutral
        if value < 0.01 and value > -0.01:
            value = 0
        if value > 1 or value < -1:
            value = round(value)
        return int(self.pwm_neutral + value * gain)
    
    def calculate_pwm_move(self, value):
        if value == 0:
            return self.pwm_neutral
        if value == 1:
            return self.pwm_max
        if value == -1:
            return self.pwm_min
        return self.pwm_neutral        
    
    def arm_disarm(self):
        self.arm = not self.arm
        msg = Bool()
        msg.data = self.arm
        self.arm_pub.publish(msg)
        if self.arm:
            self.get_logger().info("The ROV ist now armed!")
        else:
            self.get_logger().info("The ROV ist now disarmed!")

    def dive_up(self):        
        if self.target_depth + self.gain_depth <= 0:
            self.target_depth = round(self.target_depth + self.gain_depth, 2)
            msg = SetTarget()
            msg.depth_desired = self.target_depth
            self.depth_pub.publish(msg)
            self.get_logger().info(f"Desired depth is now {self.target_depth}")

    def dive_down(self):
        if self.target_depth - self.gain_depth > -200:
            self.target_depth = round(self.target_depth - self.gain_depth, 2)          
            msg = SetTarget()            
            msg.depth_desired = self.target_depth
            self.depth_pub.publish(msg)
            self.get_logger().info(f"Desired depth is now {self.target_depth}")
            
def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)      
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()