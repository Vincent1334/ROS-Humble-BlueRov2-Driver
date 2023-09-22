#!/usr/bin/env python3
import rclpy
import pygame
from pygame.locals import *
from rclpy.node import Node

from bluerov2_interfaces.msg import Status
from std_msgs.msg import UInt16

class Controller(Node):    
    
    def __init__(self):
        super().__init__("input_controller")  

        # Setup default parameters        
        self.declare_parameter("pwm_max", 1900)
        self.declare_parameter("pwm_min", 1100)
        self.declare_parameter("gain_pwm_cam", 400)     
        self.declare_parameter("gain_pwm_lights", 50)

        self.pwm_max                = self.get_parameter("pwm_max").value 
        self.pwm_min                = self.get_parameter("pwm_min").value 
        self.gain_pwm_cam           = self.get_parameter("gain_pwm_cam").value 
        self.gain_pwm_lights        = self.get_parameter("gain_pwm_lights").value 

        # Create subscriber
        self.status_sub             = self.create_subscription(Status, "/bluerov2/status", self.callback_status, 10) 

        # Create publisher
        self.lights_pub             = self.create_publisher(UInt16, "/bluerov2/rc/lights", 10)
        self.camera_tilt_pub             = self.create_publisher(UInt16, "/bluerov2/rc/camera_tilt", 10)

        self.pitch              = 1500                              # The pitch channel (RC1) refers to the upward or downward tilt of the BlueRov2.            
        self.roll               = 1500                              # The roll channel (RC2) is responsible for the horizontal rotation of the BlueRov2 nose around its longitudinal axis.
        self.throttle           = 1500                              # The Throttle channel (RC3) controls the motor power for the diving characteristics of the BlueRov2.
        self.yaw                = 1500                              # The Yaw channel (RC4) is responsible for the rotation of the BlueRov2 nose around the vertical axis.
        self.forward            = 1500                              # The Forward channel (RC5) is responsible for the forward movement of the BlueRov2.
        self.lateral            = 1500                              # The lateral channel (RC6) concerns the lateral movement of the BlueRov2.
        self.camera_pan         = 1500                              # The Camera Pan channel (RC7) controls the horizontal panning movement of the camera.
        self.camera_tilt        = 1500                              # The Camera Tilt channel (RC8) controls the vertical tilt movement of the camera.
        self.lights             = 1100                              # The Lights Level channel (RC9) controls the intensity or brightness of the light source.

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
            # The 0 button is the 'a' button, 1 is the 'b' button, 2 is the 'x' button, 3 is the 'y' button
            if event.type == JOYBUTTONDOWN:
                print(event.button)
                if event.button == 4:   #LB
                    self.lights_down()
                if event.button == 5:   #RB
                    self.lights_up()      

            if event.type == JOYAXISMOTION:
                if event.axis == 1:     #DPad Up-Down
                    self.camera_tilt_event(event.value)

    

    def lights_down(self):        
        msg = UInt16()
        if self.lights - self.gain_pwm_lights > 1100:
            msg.data = self.lights - self.gain_pwm_lights
        else:
            msg.data = 1100
        self.lights_pub.publish(msg)

    def lights_up(self):       
        msg = UInt16()
        if self.lights + self.gain_pwm_lights < 1900:
            msg.data = self.lights + self.gain_pwm_lights
        else:
            msg.data = 1900
        self.lights_pub.publish(msg)

    def camera_tilt_event(self, value):
        msg = UInt16()
        val = round(value)

        if val == -1:
            msg.data = self.pwm_max
        elif val == 1:
            msg.data = self.pwm_min
        elif val == 0:
            msg.data = 1500

        print(msg.data)
        self.camera_tilt_pub.publish(msg)

        

    def callback_status(self, msg):
        self.pitch              = msg.pitch                              
        self.roll               = msg.roll                              
        self.throttle           = msg.throttle                       
        self.yaw                = msg.yaw                             
        self.forward            = msg.forward                            
        self.lateral            = msg.lateral                             
        self.camera_pan         = msg.camera_pan                              
        self.camera_tilt        = msg.camera_tilt                              
        self.lights             = msg.lights

def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)      
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()