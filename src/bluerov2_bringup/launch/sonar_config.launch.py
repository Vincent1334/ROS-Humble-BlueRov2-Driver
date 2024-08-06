#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
import os

def generate_launch_description():

    ld = LaunchDescription()
    
    rviz_config_file = PathJoinSubstitution(
           [FindPackageShare("bluerov2_bringup"), "rviz", "bluerov2_dashboard.rviz"]
   )

    sonar_node = Node(
        package="tritech_micron",
        executable="scan",
    )

    rviz = Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            output="log",
            arguments=["-d", rviz_config_file],
    )
    
    ld.add_action(rviz)
    ld.add_action(sonar_node)

    return ld
