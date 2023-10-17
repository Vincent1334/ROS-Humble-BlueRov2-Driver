#!/usr/bin/env python3

"""Tritech Micron sonar scanner.

This publishes one PointCloud message per scan slice. In order to visualize in
rviz, play with the 'Decay Time' parameter. This node also provides parameters
that can be dynamically reconfigured.
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud
from sonar import Sonar
from geometry_msgs.msg import PoseStamped
from tritech_micron_interfaces.msg import TritechMicronConfig

__author__ = "Anass Al-Wohoush"

class Controller(Node):
    
    def __init__(self):
        super().__init__("tritech_micron")

        # Create publisher
        self.scan_pub        = self.create_publisher(PointCloud, "tritech_micron/scan", queue_size=800)
        self.heading_pub     = self.create_publisher(PoseStamped, "tritech_micron/heading", queue_size=800)
        self.conf_pub        = self.create_publisher(TritechMicronConfig, "tritech_micron/config", queue_size=800)
 
        # Get frame name and port.
        self.declare_parameter("frame", "sonar") 
        self.declare_parameter("port", "/dev/ttyUSB0")

        self.frame   = self.get_parameter("frame").value
        self.port    = self.get_parameter("port").value

        with Sonar(port=self.port, node=self) as sonar:
            try:
                # Scan.
                sonar.scan(callback=self.publish)
            except KeyboardInterrupt:
                sonar.preempt()


    def reconfigure(self, config, level):
        """Reconfigures sonar dynamically.

        Args:
            config: New configuration.
            level: Level bitmask.

        Returns:
            Configuration.
        """
        self.get_logger().info("Reconfiguring sonar")
        self.get_logger().debug("Configuration requested: %r, %r", config, level)

        # Remove additional keys.
        if "groups" in config:
            config.pop("groups")

        # Set parameters.
        sonar.set(**config)
        return config


    def publish(self, sonar, slice):
        """Publishes PointCloud, PoseStamped and TritechMicronConfig of current
        scan slice on callback.

        Args:
            sonar: Sonar instance.
            slice: Current scan slice.
        """

        # Publish heading as PoseStamped.
        posestamped = slice.to_posestamped(self.frame)
        heading_pub.publish(posestamped)

        # Publish data as PointCloud.
        cloud = slice.to_pointcloud(frame)
        scan_pub.publish(cloud)

        # Publish data as TritechMicronConfig.
        config = slice.to_config(frame)
        conf_pub.publish(config)

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