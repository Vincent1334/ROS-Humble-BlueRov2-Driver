#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs_py import point_cloud2
from sensor_msgs.msg import PointCloud2
from geometry_msgs.msg import Point, Vector3
from visualization_msgs.msg import Marker
import numpy as np
import random
from bluerov2_controller.tools import numpy_to_pointcloud, calculate_line_model, measurements_within_epsilon

class Controller(Node):

    def __init__(self):
        super().__init__("wall_detection")

        # Parameters of the algorithm
        self.i_max = 50 #maximum iteration
        self.epsilon = 0.3 #epsilon tunnel for inliners 

        # Create subscriber
        self.scan_sub           = self.create_subscription(PointCloud2, "tritech_micron/scan", self.callback_scan, 10)

        # Create publisher
        self.pub_inliers        = self.create_publisher(PointCloud2, '/ransac_output', 10)
        self.pub_line_vector    = self.create_publisher(Vector3, '/line_vector', 10)
        self.pub_marker         = self.create_publisher(Marker, '/line_marker', 10)

    def callback_scan(self, msg):
        self.ransac(msg)
    
    def ransac(self, pc2_msg):
        #conver pointcloud message to numpy array
        data = np.array(list(point_cloud2.read_points(pc2_msg, field_names=("x", "y", "z"), skip_nans=True)))
        M_result, S_result = None, []

        #loop over the number of iterations i_max
        for i in range(self.i_max):
            #sample two random points
            sample = random.sample(list(data), 2)
            M_i = calculate_line_model(sample)
            if M_i is None:
                continue
            S_i = measurements_within_epsilon(M_i, data, self.epsilon)
            if len(S_i) > len(S_result): # if better model found
                M_result, S_result = M_i, S_i

	    #publish inliners
        inliers_msg = numpy_to_pointcloud(np.array(S_result), pc2_msg.header.frame_id)
        self.pub_inliers.publish(inliers_msg)

        #calculate output vector for model
        if M_result is not None:
            line_vector = Vector3()
            if M_result[0] is None:
                line_vector.x = 0.0
                line_vector.y = 1.0
                line_vector.z = 0.0
            else:
                line_vector.x = 1.0
                line_vector.y = float(M_result[0])
                line_vector.z = 0.0
            self.pub_line_vector.publish(line_vector)
            self.publish_line_as_marker(M_result, pc2_msg.header.frame_id)

    #publish model as line
    def publish_line_as_marker(self, M_result, frame_id):
        marker = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = 'lines'
        marker.id = 0
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD
        marker.scale.x = 0.1
        marker.color.a = 1.0
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0

        if M_result[0] is None:
            marker.points.append(Point(x=float(M_result[1]), y=-100.0, z=0.0))
            marker.points.append(Point(x=float(M_result[1]), y=100.0, z=0.0))
        else:
            m, c = M_result
            marker.points.append(Point(x=-10.0, y=m * (-10.0) + c, z=0.0))
            marker.points.append(Point(x=10.0, y=m * (10.0) + c, z=0.0))
        
        self.pub_marker.publish(marker)


def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)        
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()