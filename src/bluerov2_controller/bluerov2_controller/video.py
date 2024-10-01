#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import cv2
import gi
import numpy as np
import json

from sensor_msgs.msg import BatteryState
from std_msgs.msg import String
from bluerov2_interfaces.msg import Bar30
from bluerov2_interfaces.msg import Attitude

gi.require_version('Gst', '1.0')
from gi.repository import Gst

class Controller(Node):
    """BlueRov video capture class constructor

    Attributes:
        port (int): Video UDP port
        video_codec (string): Source h264 parser
        video_decode (string): Transform YUV (12bits) to BGR (24bits)
        video_pipe (object): GStreamer top-level pipeline
        video_sink (object): Gstreamer sink element
        video_sink_conf (string): Sink configuration
        video_source (string): Udp source ip and port
    """

    g   = 9.81      # m.s^-2 gravitational acceleration 
    p0  = 103425    # Surface pressure in Pascal
    rho = 1000      # kg/m^3  water density

    def __init__(self):
        super().__init__("video")

        self.declare_parameter("port", 5600) 

        self.port               = self.get_parameter("port").value
        self._frame             = None
        self.video_source       = 'udpsrc port={}'.format(self.port)
        self.video_codec        = '! application/x-rtp, payload=96 ! rtph264depay ! h264parse ! avdec_h264'
        self.video_decode       = '! decodebin ! videoconvert ! video/x-raw,format=(string)BGR ! videoconvert'
        self.video_sink_conf    = '! appsink emit-signals=true sync=false max-buffers=2 drop=true'

        self.video_pipe         = None
        self.video_sink         = None

        self.voltage            = 0.0
        self.depth              = 0.0
        self.depth_desired      = 0.0
        self.pitch              = 0.0
        self.yaw                = 0.0
        self.roll               = 0.0

        # font
        self.font               = cv2.FONT_HERSHEY_PLAIN

        # create subscriber
        self.battery_sub        = self.create_subscription(BatteryState, "/bluerov2/battery", self.battery_callback, 10) 
        self.depth_desired_sub  = self.create_subscription(String, "/settings/depth/status", self.depth_desired_callback, 10)  
        self.bar30_sub          = self.create_subscription(Bar30, "/bluerov2/bar30", self.callback_bar30, 10)    
        self.attitude_sub       = self.create_subscription(Attitude, "/bluerov2/attitude", self.callback_att, 10) 

        Gst.init() 


        self.run()

        # Start update loop
        self.create_timer(0.01, self.update)    

    def start_gst(self, config=None):
        """ Start gstreamer pipeline and sink
        Pipeline description list e.g:
            [
                'videotestsrc ! decodebin', \
                '! videoconvert ! video/x-raw,format=(string)BGR ! videoconvert',
                '! appsink'
            ]

        Args:
            config (list, optional): Gstreamer pileline description list
        """

        if not config:
            config = \
                [
                    'videotestsrc ! decodebin',
                    '! videoconvert ! video/x-raw,format=(string)BGR ! videoconvert',
                    '! appsink'
                ]

        command = ' '.join(config)
        self.video_pipe = Gst.parse_launch(command)
        self.video_pipe.set_state(Gst.State.PLAYING)
        self.video_sink = self.video_pipe.get_by_name('appsink0')

    @staticmethod
    def gst_to_opencv(sample):
        """Transform byte array into np array

        Args:
            sample (TYPE): Description

        Returns:
            TYPE: Description
        """
        buf = sample.get_buffer()
        caps = sample.get_caps()
        array = np.ndarray(
            (
                caps.get_structure(0).get_value('height'),
                caps.get_structure(0).get_value('width'),
                3
            ),
            buffer=buf.extract_dup(0, buf.get_size()), dtype=np.uint8)
        return array

    def frame(self):
        """ Get Frame

        Returns:
            iterable: bool and image frame, cap.read() output
        """
        return self._frame

    def frame_available(self):
        """Check if frame is available

        Returns:
            bool: true if frame is available
        """
        return type(self._frame) != type(None)

    def run(self):
        """ Get frame to update _frame
        """

        self.start_gst(
            [
                self.video_source,
                self.video_codec,
                self.video_decode,
                self.video_sink_conf
            ])

        self.video_sink.connect('new-sample', self.callback)

    def callback(self, sink):
        sample = sink.emit('pull-sample')
        new_frame = self.gst_to_opencv(sample)
        self._frame = new_frame

        return Gst.FlowReturn.OK
    
    def battery_callback(self, msg):
        self.voltage = round(msg.voltage, 2)

    def depth_desired_callback(self, msg):
        data = json.loads(msg.data)
        self.depth_desired = abs(data['depth_desired'])

    def callback_bar30(self, msg):
        self.bar30_data = [ msg.time_boot_ms,
                            msg.press_abs,
                            msg.press_diff,
                            msg.temperature ]
        
        
        self.depth = round((self.bar30_data[1]*100-self.p0)/(self.rho*self.g), 2)

    def callback_att(self, msg):         
        self.roll   = round(msg.roll, 3)
        self.pitch  = round(msg.pitch, 3)
        self.yaw    = round(msg.yaw, 3)
    
    def update(self):        
        if not self.frame_available():
            return

        frame = self.frame()
        width = int(1920/1.5)
        height = int(1080/1.5)
        dim = (width, height)
        img = cv2.resize(frame, dim, interpolation = cv2.INTER_AREA)   

        self.draw_gui(img, width, height)        

        cv2.imshow('BlueROV2 Camera', img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            self.destroy_node()

    def draw_gui(self, img, width, height):        
        img = cv2.rectangle(img,(0, height-100),(520,height),(0,0,0),-1)
        
        img = cv2.putText(img, 'Voltage:', (10, height-70), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, 'Depth:', (10, height-45), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, 'Target depth:', (10, height-20), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)

        img = cv2.putText(img, f'{self.voltage}V', (205, height-70), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, f'{self.depth}m', (205, height-45), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, f'{self.depth_desired}m', (205, height-20), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)

        img = cv2.putText(img, 'Pitch:', (320, height-70), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, 'Roll:', (320, height-45), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, 'Yaw:', (320, height-20), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)

        img = cv2.putText(img, f'{self.pitch}', (430, height-70), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, f'{self.roll}', (430, height-45), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)
        img = cv2.putText(img, f'{self.yaw}', (430, height-20), self.font, 1.6, (255, 255, 250), 1, cv2.LINE_AA)

def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)        
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
