#!/usr/bin/env python3
import rclpy
import json
from rclpy.node import Node
import bluerov2_controller.pid as pid
from bluerov2_interfaces.msg import Bar30, PID
from std_msgs.msg import UInt16, Float64, Bool, String

class Controller(Node):

    g   = 9.81      # m.s^-2 gravitational acceleration 
    p0  = 103425    # Surface pressure in Pascal
    rho = 1000      # kg/m^3  water density
    
    def __init__(self):
        super().__init__("depth_controller")

        # Setup default parameters
        self.declare_parameter("depth_desired", 0) 
        self.declare_parameter("pwm_max", 1900)
        self.declare_parameter("pwm_neutral", 1500)
        self.declare_parameter("ki", 100)      
        self.declare_parameter("kp", 600)    
        self.declare_parameter("kd", 50)    
        self.declare_parameter("enable", True)        

        self.depth_desired  = self.get_parameter("depth_desired").value     # Desired depth setpoint
        self.bar30_data     = [0, 0, 0, 0]                                  # List to store Bar30 sensor data: [time_boot_ms, press_abs, press_diff, temperature]
        self.pwm_max        = self.get_parameter("pwm_max").value           # Maximum PWM value
        self.pwm_neutral    = self.get_parameter("pwm_neutral").value       # Neutral PWM value
        self.KI             = self.get_parameter("ki").value                # Integral gain constant
        self.KP             = self.get_parameter("kp").value                # Proportional gain constant
        self.KD             = self.get_parameter("kd").value                # Derivative gain constant

        self.time           = 0
        self.depth          = 0
        self.I_depth        = 0

        self.enable         = self.get_parameter("enable").value

        # Create subscriber
        self.bar30_sub      = self.create_subscription(Bar30, "/bluerov2/bar30", self.callback_bar30, 10) 
        self.setDepth_sub   = self.create_subscription(Float64, "/settings/depth/set_depth", self.callback_set_depth, 10)
        self.setPID_sub     = self.create_subscription(PID, "/settings/depth/set_pid", self.callback_set_pid, 10) 
        self.setEnable_sub  = self.create_subscription(Bool, "/settings/depth/set_enable", self.callback_set_enable, 10) 

        # Create publisher
        self.throttle_pub   = self.create_publisher(UInt16, "/bluerov2/rc/throttle", 10)  
        self.status_pub     = self.create_publisher(String, '/settings/depth/status', 10)

        self.get_logger().info('controller has been successfully configured!')        

        # Start update loop
        self.create_timer(0.04, self.calculate_pwm)        

    def callback_bar30(self, msg):
        """Read data from '/BlueRov2/bar30'

        ROS message:
        Header header
        uint32 time_boot_ms
        float64 press_abs
        float64 press_diff
        int16 temperature
        """
        self.bar30_data = [ msg.time_boot_ms,
                            msg.press_abs,
                            msg.press_diff,
                            msg.temperature ]
        
    def callback_set_pid(self, msg):
        """Read data from '/settings/depth/set_pid'

        ROS message:
        ------------        
        uint16 pwm_max 
        uint32 KI
        uint32 KP
        uint32 KD
        """
        if msg.pwm_max != 65535:
            if msg.pwm_max < 1500:
                self.pwm_max = 1500
            else:
                self.pwm_max = msg.pwm_max

        self.KP = msg.kp if not msg.kp == 65535 else self.KP
        self.KI = msg.ki if not msg.ki == 65535 else self.KI       
        self.KD = msg.kd if not msg.kd == 65535 else self.KD

    def callback_set_depth(self, msg): 
        """Read data from '/settings/depth/set_depth'

        ROS message:
        ------------        
        float64 data
        """          
        
        self.depth_desired = msg.data

    def callback_set_enable(self, msg):
        """Read data from '/settings/depth/set_enable'

        ROS message:
        ------------        
        bool data
        """             
        self.enable = msg.data

    def update_status(self):         
        msg = String()
        data = {}
        data["type"]            = "depth_controller"
        data["enable"]          = self.enable
        data["kp"]              = self.KP
        data["ki"]              = self.KI
        data["kd"]              = self.KD
        data["pwm_max"]         = self.pwm_max
        data["pwm_neutral"]     = self.pwm_neutral
        data["depth_desired"]   = self.depth_desired
        
        msg.data = json.dumps(data)
        self.status_pub.publish(msg)
        

    def control_pid(self, p):
        """PID controller
        Transform pressure to depth value
        Calulate the integrate value with euler method

        Input:
        ------
        p: absolute presssure in Pa

        Return:
        -------
        command calculated to reach the depth desired

        """
        depth       = -(p-self.p0)/(self.rho*self.g)
        delta_depth = depth - self.depth
        self.depth  = depth #current depth
        delta_t     = (self.bar30_data[0] - self.time)/1000.
        self.time   = self.bar30_data[0]

        if delta_t == 0:
            D_depth = 0
        else:
            D_depth = delta_depth/delta_t #derivative term 

        self.I_depth = (self.depth_desired - depth) * delta_t
        u = self.KI*self.I_depth + self.KP*(self.depth_desired-depth) - self.KD*D_depth
        return u   

    def calculate_pwm(self):  
        msg = UInt16()

        if self.enable:
            mesured_pressure = self.bar30_data[1]*100 #to convert pressure from hPa to Pa
            u = self.control_pid(mesured_pressure)
            pwm = self.pwm_neutral + u
            pwm = pid.saturation(pwm, self.pwm_neutral, self.pwm_max)
            
            msg.data = pwm
        else:
            msg.data = self.pwm_neutral        
            
        self.throttle_pub.publish(msg)     
        self.update_status()   

def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)      
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()