#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Tritech Micron sonar tools."""

import math
import numpy as np
from tritech_micron_interfaces.msg import TritechMicronConfig
from sensor_msgs.msg import ChannelFloat32, PointCloud
from geometry_msgs.msg import Point32, Pose, PoseStamped, Quaternion

__author__ = "Anass Al-Wohoush, Vincent Schiller"


def to_sonar_angles(rad):
    """Converts radians to units of 1/16th of a gradian.

    Args:
        rad: Angle in radians.

    Returns:
        Integral angle in units of 1/16th of a gradian.
    """
    return int(rad * 3200 / math.pi) % 6400


def to_radians(angle):
    """Converts units of 1/16th of a gradian to radians.

    Args:
        angle: Angle in units of 1/16th of a gradian.

    Returns:
        Angle in radians.
    """
    return angle / 3200.0 * math.pi


def reconfigured(previous_slice, current_slice):
    """Determines whether the sonar has been reconfigured to the point that all
    upcoming data is incompatible with previous data and cannot be stitched
    together to form an image.

    Args:
        previous_slice: Previous slice.
        current_slice: Current slice.

    Returns:
        True if scan data should be reset due to reconfiguration, False
        otherwise.
    """
    for key in current_slice.config:
        if current_slice.config[key] != previous_slice.config[key]:
            return True

    return False


class ScanSlice(object):

    """Scan slice.

    Attributes:
        bins: Array of intensities of each return.
        config: Sonar configuration at time of this slice.
        heading: Heading of sonar in radians.
        range: Range of scan in meters.
        timestamp: ROS timestamp.
    """

    def __init__(self, heading, bins, config, node):
        """Constructs ScanSlice instance.

        Args:
            heading: Heading of sonar in radians.
            bins: Array of intensities of each return.
            config: Sonar configuration at time of this slice.
        """
        self.heading = heading
        self.bins = bins
        self.config = config
        self.range = config["range"]
        self.timestamp = node.get_clock().now().to_msg()

    def to_config(self, frame):
        """Returns a TritechMicronConfig message corresponding to slice
        configuration.

        Args:
            frame: Frame ID.

        Returns:
            TritechMicronConfig.
        """
        config = TritechMicronConfig(**self.config)
        config.header.frame_id = frame
        config.header.stamp = self.timestamp

        return config

    def to_pointcloud(self, frame):
        """Returns a PointCloud message corresponding to slice.

        Args:
            frame: Frame ID.

        Returns:
            A sensor_msgs.msg.PointCloud.
        """

        # Construct PointCloud message.
        cloud = PointCloud()
        cloud.header.frame_id = frame
        cloud.header.stamp = self.timestamp

        # Convert bins to list of Point32 messages.
        nbins = self.config["nbins"]
        r_step = self.range / nbins
        x_unit = math.cos(self.heading) * r_step
        y_unit = math.sin(self.heading) * r_step
        cloud.points = [
            Point32(x=x_unit * r, y=y_unit * r, z=0.00)
            for r in range(1, nbins + 1)
        ]  
               
        # Set intensity channel.
        channel = ChannelFloat32()
        channel.name = "intensity"
        channel.values = [float(val) for val in self.bins]
        cloud.channels = [channel]

        return cloud    

    def to_posestamped(self, frame):
        """Returns a PoseStamped message corresponding to slice heading.

        Args:
            frame: Frame ID.

        Returns:
            A geometry_msgs.msg.PoseStamped.
        """
        # Construct PoseStamped message.
        posestamped = PoseStamped()
        posestamped.header.frame_id = frame
        posestamped.header.stamp = self.timestamp

        # Convert to quaternion.     
        npQ = self.quaternion_from_euler(0, 0, self.heading)   
        q = Quaternion()
        q.x = npQ[0]
        q.y = npQ[1]
        q.z = npQ[2]
        q.w = npQ[3]        

        # Make Pose message.
        pose = Pose(orientation=q)
        posestamped.pose = pose

        return posestamped
    
    def quaternion_from_euler(self, ai, aj, ak):
        ai /= 2.0
        aj /= 2.0
        ak /= 2.0
        ci = math.cos(ai)
        si = math.sin(ai)
        cj = math.cos(aj)
        sj = math.sin(aj)
        ck = math.cos(ak)
        sk = math.sin(ak)
        cc = ci*ck
        cs = ci*sk
        sc = si*ck
        ss = si*sk

        q = np.empty((4, ))
        q[0] = cj*sc - sj*cs
        q[1] = cj*ss + sj*cc
        q[2] = cj*cs - sj*sc
        q[3] = cj*cc + sj*ss

        return q
