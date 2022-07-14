import rospy
import numpy as np
import dynamic_reconfigure.client
from sensor_msgs.msg import Joy, LaserScan
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray, Float64
from messages.msg import state_estimation, observer_message, reference_message, s_message
from common_tools.math_tools import quat2eul, rad2pipi

class Qualisys():
    """
    Retrieves qualisys measurements by listening to the /qualisys/CSS/odom topic.
    It converts the quaternions to euler angles and publishes a 1x3 measurement vector
    to the topic /CSS/eta
    """
    def __init__(self):
        self.odom = Odometry()
        self.eta = np.zeros(3)
        self.message = Float64MultiArray()
        self.pub = rospy.Publisher('/CSS/eta', Float64MultiArray, queue_size=1)

    def callback(self, data):
        self.odom = data
        w = self.odom.pose.pose.orientation.w
        x = self.odom.pose.pose.orientation.x
        y = self.odom.pose.pose.orientation.y
        z = self.odom.pose.pose.orientation.z

        self.eta[0] = self.odom.pose.pose.position.x
        self.eta[1] = self.odom.pose.pose.position.y
        self.eta[2] = quat2eul(x, y, w, z)[2]
        self.eta[2] = rad2pipi(self.eta[2])
        self.message.data = self.eta
        self.pub.publish(self.message)

    def get_data(self):
        return self.eta

class DS4_Controller():
    """
    The controller listens to the /joy topic and maps all input signals from the DS4 to a variable that can be called
    """
    def __init__(self):
        self.x = self.square = self.circle = self.triangle = self.rightArrow = self.leftArrow = self.upArrow = self.DownArrow = self.L1 = self.R1 = self.L2 = self.R2 = self.L3 = self.R3 = self.share = self.options = self.PS = self.pad = 0
        self.lStickX = self.lStickY = self.rStickX = self.rStickY = self.L2A = self.R2A = 0.0

    def updateState(self, data):
        self.x = data.buttons[3]
        self.square = data.buttons[0]
        self.circle = data.buttons[2]
        self.triangle = data.buttons[1]
        self.rightArrow = data.buttons[16]
        self.leftArrow = data.buttons[14]
        self.upArrow = data.buttons[15]
        self.DownArrow = data.buttons[17]
        self.L1 = data.buttons[4]
        self.R1 = data.buttons[6]
        self.L2 = data.buttons[5]
        self.R2 = data.buttons[7]
        self.L3 = data.buttons[12]
        self.R3 = data.buttons[13]
        self.options = data.buttons[9]
        self.share = data.buttons[8]
        self.PS = data.buttons[10]
        self.pad = data.buttons[11]

        self.lStickX = -data.axes[0]
        self.lStickY = data.axes[1]
        self.rStickX = -data.axes[2]
        self.rStickY = data.axes[3]
        self.L2A = data.axes[4]
        self.R2A = data.axes[5]


class Obstacle():
    def __init__(self, x, y, z):
        self.p_o = np.array([[x], [y], [z]])


# Build the objects to be imported
ps4 = DS4_Controller()
qualisys = Qualisys()
