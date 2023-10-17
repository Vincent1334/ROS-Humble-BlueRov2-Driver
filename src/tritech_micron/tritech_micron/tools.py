#!/usr/bin/env python3
"""Tritech Micron sonar tools."""

import math
from tritech_micron_interfaces.msg import TritechMicronConfig
from tf.transformations import quaternion_from_euler
from sensor_msgs.msg import ChannelFloat32, PointCloud
from geometry_msgs.msg import Point32, Pose, PoseStamped, Quaternion

__author__ = "Anass Al-Wohoush"


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

    def __init__(self, heading, bins, config, timestamp):
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
        self.timestamp = timestamp

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
        channel.values = self.bins
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
        q = Quaternion(*quaternion_from_euler(0, 0, self.heading))

        # Make Pose message.
        pose = Pose(orientation=q)
        posestamped.pose = pose

        return posestamped