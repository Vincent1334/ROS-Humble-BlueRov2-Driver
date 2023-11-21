#!/usr/bin/env python3
import rclpy
import pygame
import json
from pygame.locals import *
from rclpy.node import Node, Client

from std_msgs.msg import UInt16, Float64, Bool, String
from std_srvs.srv import Trigger

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
        self.declare_parameter("gain_yaw", 3)
        self.declare_parameter("arm_status", True)
        self.declare_parameter("debug", False)

        self.pwm_min                = self.get_parameter("pwm_min").value 
        self.pwm_max                = self.get_parameter("pwm_max").value
        self.pwm_neutral            = self.get_parameter("pwm_neutral").value        
        self.pwm_camera_max         = self.get_parameter("pwm_camera_max").value 
        self.pwm_camera_min         = self.get_parameter("pwm_camera_min").value 
        self.pwm_lights_max         = self.get_parameter("pwm_lights_max").value 
        self.pwm_lights_min         = self.get_parameter("pwm_lights_min").value 

        self.gain_depth             = self.get_parameter("gain_depth").value     
        self.gain_yaw               = self.get_parameter("gain_yaw").value          
        self.gain_pwm_cam           = self.get_parameter("gain_pwm_cam").value 
        self.gain_pwm_lights        = self.get_parameter("gain_pwm_lights").value 

        self.lights_value           = self.get_parameter("pwm_lights_min").value
        self.arm                    = self.get_parameter("arm_status").value    

        self.debug                  = self.get_parameter("debug").value   

        # Node status
        self.depth_status           = None
        self.yaw_status             = None

        # Create publisher
        self.lights_pub             = self.create_publisher(UInt16, "/bluerov2/rc/lights", 10)
        self.camera_tilt_pub        = self.create_publisher(UInt16, "/bluerov2/rc/camera_tilt", 10)
        self.forward_pub            = self.create_publisher(UInt16, "/bluerov2/rc/forward", 10)
        self.lateral_pub            = self.create_publisher(UInt16, "/bluerov2/rc/lateral", 10)        
        self.arm_pub                = self.create_publisher(Bool, "/bluerov2/arm", 10)
        self.depth_controller_pub   = self.create_publisher(Float64, "/settings/depth/set_depth", 10)
        self.yaw_controller_pub     = self.create_publisher(UInt16, "/settings/yaw/set_yaw", 10)              

        # Create subscriber
        self.depth_status_sub       = self.create_subscription(String, "/settings/depth/status", self.callback_node_status, 10)   
        self.yaw_status_sub         = self.create_subscription(String, "/settings/yaw/status", self.callback_node_status, 10)               

        # Clear BlueRov status
        lights = UInt16()
        lights.data = self.pwm_lights_min
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
        if (self.depth_status is None and self.yaw_status is not None) or self.debug:
            for event in pygame.event.get():            
                # Check if a joystick button was pressed
                if event.type == JOYBUTTONDOWN:
                    if event.button == 4:       # Left Bumper (LB)
                        self.adjust_lights("down")  
                    elif event.button == 5:     # Right Bumper (RB)
                        self.adjust_lights("up")  
                    elif event.button == 7:     # Start Button
                        self.arm_disarm()   
                    elif event.button == 3:     # Y Button
                        self.dive_up()  
                    elif event.button == 0:     # A Button
                        self.dive_down()  

                 # Check if a joystick axis motion event occurs
                elif event.type == JOYAXISMOTION:                     
                    if event.axis == 0 or event.axis == 1:    # Left Joystick motion
                        self.move_event(event)  

                # Check if a joystick hat motion event occurs
                elif event.type == JOYHATMOTION:
                    self.camera_tilt_event(event.value)         # D-Pad Up-Down motion

            # Update rotation event with right joystick motion data
            self.rotation_event(pygame.joystick.Joystick(0).get_axis(3))    
        else:
            self.get_logger().error("Attempt to establish a connection to the controllers failed.")     

    def adjust_lights(self, direction):
        msg = UInt16()
        
        if direction == "down":
            target_value = self.lights_value - self.gain_pwm_lights
            msg.data = max(target_value, self.pwm_lights_min)
        elif direction == "up":
            target_value = self.lights_value + self.gain_pwm_lights
            msg.data = min(target_value, self.pwm_lights_max)            
        
        self.lights_value = msg.data
        self.lights_pub.publish(msg)    

    def camera_tilt_event(self, value):
        msg = UInt16()
        value = value[1]

        if value == 1:
            msg.data = int(self.pwm_camera_max)
        elif value == -1:
            msg.data = int(self.pwm_camera_min)
        else:
            msg.data = int(self.pwm_neutral)
        
        self.camera_tilt_pub.publish(msg)

    def rotation_event(self, value):
        value = max(-1, min(1, round(value, 1) * self.gain_yaw))        
        new_yaw = (self.yaw_status["yaw_desired"] + value) % 360
        msg = UInt16()        
        msg.data = round(new_yaw) 
        self.yaw_controller_pub.publish(msg)    
        self.get_logger().info(f"Desired yaw is now {new_yaw}")    

    def move_event(self, event):
        u = event.value
        pwm = UInt16(data=self.calculate_pwm(u))        

        if event.axis == 0:
            self.forward_pub.publish(pwm)
        else:
           self.lateral_pub.publish(pwm)        

    def calculate_pwm(self, value):
        value = max(-1, min(1, value))
        return int(self.pwm_neutral + value * (self.pwm_max - self.pwm_neutral))
    
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
        new_depth = round(self.depth_status["depth_desired"] + self.gain_depth, 2)
        
        if new_depth <= 0:            
            msg = Float64()
            msg.data = new_depth
            self.depth_controller_pub.publish(msg)
            self.get_logger().info(f"Desired depth is now {new_depth}")


    def dive_down(self):
        new_depth = round(self.depth_status["depth_desired"] - self.gain_depth, 2)
        
        if new_depth > -200:            
            msg = Float64()
            msg.data = new_depth
            self.depth_controller_pub.publish(msg)
            self.get_logger().info(f"Desired depth is now {new_depth}")

    def callback_node_status(self, msg):        
        data = json.loads(msg.data)
        
        match data["type"]:
            case "depth_controller": self.depth_status = data   
            case "yaw_controller": self.yaw_status = data     
            
def main(args=None):
    rclpy.init(args=args)    
    node = Controller()    
    rclpy.spin(node)      
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
