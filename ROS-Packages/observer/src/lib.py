from math import tau
from math_tools import quat2eul, Rzyx
import rospy
from std_msgs.msg import Float64MultiArray
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Vector3
from messages.msg import observer_message
import numpy as np
import dynamic_reconfigure.client

class Qualisys():
    """
    Retrieves qualisys measurements by listening to the /qualisys/CSEI/odom topic
    """
    def __init__(self):
        self.odom = Odometry()
        self.eta = np.zeros(3)

    def updateQualisysOdometry(self, data):
        self.odom = data

    def getQualisysOdometry(self):
        w = self.odom.pose.pose.orientation.w
        x = self.odom.pose.pose.orientation.x
        y = self.odom.pose.pose.orientation.y
        z = self.odom.pose.pose.orientation.z

        self.eta[0] = self.odom.pose.pose.position.x
        self.eta[1] = self.odom.pose.pose.position.y
        self.eta[2] = quat2eul(w, x, y, z)[2]
        
        return self.eta


class UVector():
    Udata = [0.0, 0.0, 0.0, 0.0, 0.0]

    def updateU(self, message):
        self.Udata = message.data

    def getU(self):
        return self.Udata 


class Tau():
    def __init__(self):
        self.tau = np.array([0, 0, 0])

    def updateTau(self, msg):
        self.tau = msg.data
    
    def getTau(self):
        return self.tau

class Observer_Converser():
    def __init__(self):
        self.observer_msg = observer_message()
        self.pub = rospy.Publisher('CSEI/observer/', observer_message, queue_size=1)
        self.eta_hat = np.array([0, 0, 0])
        self.nu_hat = np.array([0, 0, 0])
        self.bias_hat = np.array([0, 0 ,0])

    def callback(self, msg):
        self.eta_hat = msg.eta
        self.nu_hat = msg.nu
        self.bias_hat = msg.bias

    # Publishes the to the CSEI/observer topic
    def publish(self, eta_hat, nu_hat, bias_hat):
        self.observer_msg.eta = eta_hat
        self.observer_msg.nu = nu_hat
        self.observer_msg.bias = bias_hat
        self.pub.publish(self.observer_msg)

    def get_observer_data(self):
        return self.eta_hat, self.nu_hat, self.bias_hat


class Observer_Gains():
    def __init__(self):
        self.L1 = np.zeros(3)
        self.L2 = np.zeros(3)
        self.L3 = np.zeros(3)
        

    def get_observer_gains(self):
        return self.L1, self.L2, self.L3

    def callback(self, config):
        self.L1 = self.string2array(config.L1)
        self.L2 = self.string2array(config.L2)
        self.L3 = self.string2array(config.L3)
       

    def string2array(self, string):
        return np.array(list(map(int, string.split(',')))) # Suuuuuuuuper scuffed

qualisys = Qualisys()
u-data = UVector()
observer = Observer_Converser()
gains = Observer_Gains()
tau  = Tau()

# Initialize observer node
def observerNodeInit():
    global pub, node
    node = rospy.init_node('Observer node')
    rospy.Subscriber("/qualisys/CSS/odom", Odometry, qualisys.updateQualisysOdometry)
    rospy.Subscriber("CSS/u", Float64MultiArray, Udata.updateU)
    rospy.Subscriber("CSS/observer", observer_message, observer.callback)
    rospy.Subscriber("CSS/tau", Float64MultiArray, Tau.updateTau)
    gain_client = dynamic_reconfigure.client.Client('gain_server', timeout=30, config_callback = Gains.callback)
    
   
# Destroy observer node
def nodeEnd():
    node.destroy_node()
