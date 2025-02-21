#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Wall detection sonar tools."""

from std_msgs.msg import Header
from sensor_msgs_py import point_cloud2

__author__ = "Vincent Schiller"


def numpy_to_pointcloud(self, np_points, frame_id):
        header = Header(frame_id=frame_id, stamp=self.get_clock().now().to_msg())
        point_cloud_msg = point_cloud2.create_cloud_xyz32(header, np_points.tolist())
        return point_cloud_msg

#Calc line model
def calculate_line_model(points):
    x1, y1, _ = points[0]
    x2, y2, _ = points[1]
    if x1 == x2:
        return None, float(x1)
    m = (y2 - y1) / (x2 - x1)
    c = y1 - m * x1
    return float(m), float(c)

#calculate inliners within epsilon distance from model
def measurements_within_epsilon(line, measurements, epsilon):
    m, c = line
    inliers = []
    for x, y, _ in measurements:
        perpendicular_distance = abs(m*x - y + c) / (m**2 + 1)**0.5
        if perpendicular_distance <= epsilon:
            inliers.append([x, y, 0.0])
    return inliers