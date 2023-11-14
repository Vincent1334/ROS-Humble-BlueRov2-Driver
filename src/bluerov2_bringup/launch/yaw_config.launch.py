#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    controller_node = Node(
        package="bluerov2_controller",
        executable="controller",
    )   

    yaw_node = Node(
        package="bluerov2_controller",
        executable="yaw_controller",
    )    

    ld.add_action(controller_node)    
    ld.add_action(yaw_node)   

    return ld