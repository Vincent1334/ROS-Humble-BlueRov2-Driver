#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from bluerov2_interfaces.msg import Bar30
from bluerov2_interfaces.msg import SetDepth
from bluerov2_interfaces.msg import SetTarget
from std_msgs.msg import UInt16

class Controller(Node):

    g   = 9.81      # m.s^-2 gravitational acceleration 
    p0  = 101325    # Surface pressure in Pascal
    rho = 1000      # kg/m^3  water density
    
    def __init__(self):
        super().__init__("depth_controller")       

        self.depth_desired  = 0             # Desired depth setpoint
        self.bar30_data     = [0, 0, 0, 0]  # List to store Bar30 sensor data: [time_boot_ms, press_abs, press_diff, temperature]
        self.pwm_max        = 1900          # Maximum PWM value
        self.pwm_neutral    = 1500          # Neutral PWM value
        self.KI             = 100           # Integral gain constant
        self.KP             = 600           # Proportional gain constant
        self.KD             = 50            # Derivative gain constant

        self.time           = 0
        self.depth          = 0
        self.I_depth        = 0

        # Create subscriber
        self.bar30_sub      = self.create_subscription(Bar30, "/bluerov2/bar30", self.callback_bar30, 10) 
        self.setDepth_sub   = self.create_subscription(SetDepth, "/settings/set_depth", self.callback_set_depth, 10)
        self.setTarget_sub  = self.create_subscription(SetTarget, "/settings/set_target", self.callback_set_target, 10) 

        # Create publisher
        self.throttle_pub   = self.create_publisher(UInt16, "/bluerov2/rc/throttle", 10)  

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
        
    def callback_set_depth(self, msg):
        """Read data from '/Settings/set_depth'

        ROS message:
        ------------
        bool enable_depth_ctrl
        uint16 pwm_max 
        uint32 KI
        uint32 KP
        uint32 KD
        """
        if msg.pwm_max < 1500:
            self.pwm_max = 1500
        else:
            self.pwm_max = msg.pwm_max
        self.KI = msg.ki
        self.KP = msg.kp 
        self.KD = msg.kd 

    def callback_set_target(self, msg):
        """Read data from '/Settings/set_target'

        ROS message:
        -------------
        float64 depth_desired
        float64 heading_desired
        float64 velocity_desired
        """
        self.depth_desired = msg.depth_desired

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

        self.I_depth = (self.depth_desired-depth)*delta_t #integrate term
        u = self.KI*self.I_depth + self.KP*(self.depth_desired-depth) - self.KD*D_depth
        return u
	
    def saturation(self, pwm):
        """Saturate command
        
        Input:
        ------
        pwm: pwm from self.control 
        
        Return:
        -------
        pwm: int, published on '/Command/depth'
        """
        pwm_min = self.pwm_neutral - (self.pwm_max - self.pwm_neutral)
        if pwm > self.pwm_max :
                pwm = self.pwm_max
        if pwm < pwm_min:
                pwm = pwm_min
        return int(pwm)

    def calculate_pwm(self):  
        mesured_pressure = self.bar30_data[1]*100 #to convert pressure from hPa to Pa
        u = self.control_pid(mesured_pressure)
        pwm = 1500 + u
        pwm = self.saturation(pwm)

        msg = UInt16()
        msg.data = pwm
        self.throttle_pub.publish(msg)        

def main(args=None):
    rclpy.init(args=args)    
    node = Controller()
    rclpy.spin(node)      
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()