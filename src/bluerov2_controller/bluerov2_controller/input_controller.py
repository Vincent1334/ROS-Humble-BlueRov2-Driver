#!/usr/bin/env python3
import rclpy
import pygame
import json
from pygame.locals import *
from rclpy.node import Node

from std_msgs.msg import UInt16, Float64, Bool
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

        # Create publisher
        self.lights_pub             = self.create_publisher(UInt16, "/bluerov2/rc/lights", 10)
        self.camera_tilt_pub        = self.create_publisher(UInt16, "/bluerov2/rc/camera_tilt", 10)
        self.forward_pub            = self.create_publisher(UInt16, "/bluerov2/rc/forward", 10)
        self.lateral_pub            = self.create_publisher(UInt16, "/bluerov2/rc/lateral", 10)
        self.yaw_pub                = self.create_publisher(UInt16, "/bluerov2/rc/yaw", 10) 
        self.arm_pub                = self.create_publisher(Bool, "/bluerov2/arm", 10)
        self.depth_pub              = self.create_publisher(Float64, "/settings/depth/set_target", 10)
        self.yaw_pub                = self.create_publisher(Float64, "/settings/yaw/set_target", 10)
        #self.yaw_conf_pub           = self.create_publisher(SetYaw, "/settings/yaw/set_yaw", 10)               

        # Create services
        self.depth_service          = self.create_client(Trigger, '/services/depth/status')

        while not self.depth_service.wait_for_service(timeout_sec=1.0):
            self.get_logger().warning('depth_controller service not available, waiting again...')

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
        for event in pygame.event.get():
            print(event)
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
                if event.axis == 3:                         # Right Joystick horizontal motion
                    self.rotation_event(event.value)  
                elif event.axis == 0 or event.axis == 1:    # Left Joystick motion
                    self.move_event(event)  

            # Check if a joystick hat motion event occurs
            elif event.type == JOYHATMOTION:
                self.camera_tilt_event(event.value)         # D-Pad Up-Down motion

    

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
        enable_controller = SetYaw()
        
        if self.calculate_pwm(value) == 0:
            self.yaw_enable = True
            yaw_target = Float64()
            yaw_target.data = self.attitude[2]
            self.yaw_pub.publish(yaw_target)

            enable_controller.enable_yaw_ctrl = True
        else:
            self.yaw_enable = False
            enable_controller.enable_yaw_ctrl = False

        self.yaw_conf_pub.publish(enable_controller)
        msg = UInt16()        
        msg.data = self.calculate_pwm(value)     
        self.yaw_pub.publish(msg) 

    def move_event(self, event):
        u = event.value
        pwm = UInt16(data=self.calculate_pwm(u))

        if self.yaw_enable:
            yaw_target = Float64()
            yaw_target.data = self.attitude[2]            
            self.yaw_pub.publish(yaw_target)

            enable_controller = SetYaw()
            enable_controller.enable_yaw_ctrl = True
            self.yaw_conf_pub.publish(enable_controller)

        if event.axis == 0:
            self.forward_pub.publish(pwm)
        else:
           self.lateral_pub.publish(pwm)        

    def calculate_pwm(self, value):
        gain = self.pwm_max - self.pwm_neutral
        if -0.01 < value < 0.01:
            value = 0
        elif value > 1:
            value = 1
        elif value < -1:
            value = -1
        return int(self.pwm_neutral + value * gain)    
    
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
        status = self.get_depth_status()
        self.get_logger().info(status)
       
        new_depth = round(self.target_depth + self.gain_depth, 2)
        
        if new_depth <= 0:
            self.target_depth = new_depth
            msg = Float64()
            msg.data = self.target_depth
            self.depth_pub.publish(msg)
            self.get_logger().info(f"Desired depth is now {self.target_depth}")


    def dive_down(self):
        new_depth = round(self.target_depth - self.gain_depth, 2)
        
        if new_depth > -200:
            self.target_depth = new_depth
            msg = Float64()
            msg.data = self.target_depth
            self.depth_pub.publish(msg)
            self.get_logger().info(f"Desired depth is now {self.target_depth}")

    def get_depth_status(self):
        self.get_logger().warning("Request!")
        future = self.depth_service.call_async(Trigger.Request())
        rclpy.spin_until_future_complete(self, future)
        self.get_logger().warning("Request complete!")
        return json.loads(future.result().message)
            
def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    node.get_depth_status()
    rclpy.spin(node)      
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
