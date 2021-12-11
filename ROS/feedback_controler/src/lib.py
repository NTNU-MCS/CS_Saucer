import rospy
from sensor_msgs.msg import Joy
from nav_msgs.msg import Odometry
import numpy as np
import dynamic_reconfigure.client
from std_msgs.msg import Float64MultiArray, Float64
from messages.msg import observer_message, reference_message, s_message
from math_tools import *

class Qualisys():
    """
    Retrieves qualisys measurements by listening to the /qualisys/CSS/odom topic
    """
    def __init__(self):
        self.odom = Odometry()
        self.eta = np.zeros(3)
        self.message = Float64MultiArray()
        self.pub = rospy.Publisher('/CSS/eta', Float64MultiArray, queue_size=1)
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
        self.eta[2] = rad2pipi(self.eta[2])
        self.message.data = self.eta
        self.pub.publish(self.message)
        return self.eta

class controller():
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
    
class UVector():
    """
    The UVector initializing and publishing the computed actuator commands
    """
    def __init__(self):
        self.message = Float64MultiArray()
        self.pub = rospy.Publisher('/CSS/u', Float64MultiArray, queue_size = 1)
        self.Udata = np.zeros(6)
        
    def publish(self, u):
        self.message.data = u
        self.pub.publish(self.message)
        
    def callback(self, msg):
        self.Udata = np.array(msg.data)

class Forces():
    def __init__(self):
        self.msg = Float64MultiArray()
        self.pub = rospy.Publisher('/CSS/tau', Float64MultiArray, queue_size=1)
        self.tau = np.zeros(3)

    def get_tau(self):
        return self.tau
    
    def callback(self, msg):
        self.tau = np.array(msg.data)

    def publish(self, tau):
        self.msg.data = tau
        self.pub.publish(self.msg)

class Observer_Converser():
    def __init__(self):
        self.observer_msg = observer_message()
        self.pub = rospy.Publisher('/CSS/observer', observer_message, queue_size=1)
        self.eta_hat = np.zeros(3)
        self.nu_hat = np.zeros(3)
        self.bias_hat = np.zeros(3)

    def callback(self, msg):
        self.eta_hat = np.array(msg.eta)
        self.nu_hat = np.array(msg.nu)
        self.bias_hat = np.array(msg.bias)

    # Publishes the to the CSEI/observer topic
    def publish(self, eta_hat, nu_hat, bias_hat):
        self.observer_msg.eta = eta_hat
        self.observer_msg.nu = nu_hat
        self.observer_msg.bias = bias_hat
        self.pub.publish(self.observer_msg)

    def get_observer_data(self):
        return self.eta_hat, self.nu_hat, self.bias_hat

class Reference_Converser():

    # Initialize the guidance parameters in [0; 0; 0]
    def __init__(self):
        self.ref_msg = reference_message()
        self.pub = rospy.Publisher('/CSS/reference', reference_message, queue_size=1)
        self.eta_d = np.array([0, 0, 0])
        self.eta_ds = np.array([0, 0, 0])
        self.eta_ds2 = np.array([0, 0, 0])
        self.w = 0.0
        self.v_s = 0.0
        self.v_ss = 0.0
    # Callback function is called when the topic is updated

    def callback(self, msg):
        self.eta_d = np.array(msg.eta_d)
        self.eta_ds = np.array(msg.eta_ds)
        self.eta_ds2 = np.array(msg.eta_ds2)
        self.w = msg.w
        self.v_s = msg.v_s
        self.v_ss = msg.v_ss

    # Publishes new gains to the reference topic. These should be numpy arrays with n=3
    def publish(self, eta_d, eta_ds, eta_ds2, w, v_s, v_ss):
        self.ref_msg.eta_d = eta_d
        self.ref_msg.eta_ds = eta_ds
        self.ref_msg.eta_ds2 = eta_ds2
        self.ref_msg.w = w
        self.ref_msg.v_s = v_s
        self.ref_msg.v_ss = v_ss
        self.pub.publish(self.ref_msg)

    # Retrieve the references from the object 
    def get_ref(self):
        return self.eta_d, self.eta_ds, self.eta_ds2

    def get_speed_assignemt(self):
        return self.v_s, self.v_ss, self.w
    
class Controller_Gains():
    """
    Controller gains retrieves the parameters from the dynamic_reconfigure server.
    """
    # Initialize all gains to zero
    def __init__(self):
        self.K1 = np.zeros(3)
        self.K2 = np.zeros(3)
        self.Ki = np.zeros(3)
        self.mu = 0
        self.Uref = 0

    # Retrieves the gaines 
    def get_data(self):
        return self.K1, self.K2, self.Ki, self.mu, self.Uref

    # Updates gains everytime the parameters are tuned
    def callback(self, config):
        self.K1 = self.string2array(config.K1)
        self.K2 = self.string2array(config.K2)
        self.Ki = self.string2array(config.Ki)
        self.mu = config.mu
        self.Uref = config.U_ref

    # dynamic_reconfigure does not handle arrays, so gains like L1 or KP are strings on the form "x11,x12,x13"
    # the server to limit the number of variables. This function converts 
    # the string into a numpy array when they are retrieved. Very scuffed :^)

    def string2array(self, string): 
        return np.array(list(map(float, string.split(',')))) 


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
        return np.array(list(map(float, string.split(',')))) # Suuuuuuuuper scuffed


class Paramterization_Variable():
    def __init__(self):
        self.msg = s_message()
        self.pub = rospy.Publisher('/CSS/s', s_message, queue_size=1)
        self.s = 0.0
        self.s_dot = 0.0

    def get_s(self):
        return self.s, self.s_dot

    def publish(self, s, s_dot):
        self.msg.s = s
        self.msg.s_dot = s_dot
        self.pub.publish(self.msg)

    def callback(self, msg):
        self.s = msg.s
        self.s_dot = msg.s_dot

# Build the objects to be imported
qualisys = Qualisys()
ps4 = controller()
u_data = UVector()
odometry = Odometry()
observer = Observer_Converser()
ctrl_gains = Controller_Gains()
obs_gains = Observer_Gains()
reference = Reference_Converser()
tau = Forces()
s_p = Paramterization_Variable()


# Initialization-functions for ROS-nodes 

def guidanceNodeInit():
    guidance_node = rospy.init_node('guidance_node')
    rospy.Subscriber("/joy", Joy, ps4.updateState)
    rospy.Subscriber("/CSS/u", Float64MultiArray, u_data.callback)
    rospy.Subscriber("/CSS/s", s_message, s_p.callback)
    rospy.Subscriber("/CSS/observer", observer_message, observer.callback)
    rospy.Subscriber("/CSS/reference", reference_message, reference.callback)
    gain_client = dynamic_reconfigure.client.Client('gain_server', timeout=30, config_callback = ctrl_gains.callback)
    return guidance_node


def controlNodeInit():
    control_node = rospy.init_node('control_node')
    rospy.Subscriber("/joy", Joy, ps4.updateState)
    rospy.Subscriber("/s", s_message, s_p.callback)
    rospy.Subscriber("/CSS/u", Float64MultiArray, u_data.callback)
    rospy.Subscriber("/CSS/observer", observer_message, observer.callback)
    rospy.Subscriber("/CSS/reference", reference_message, reference.callback)
    gain_client = dynamic_reconfigure.client.Client('gain_server', timeout=30, config_callback = ctrl_gains.callback)
    return control_node


def observerNodeInit():
    observer_node = rospy.init_node('Observer_node')
    rospy.Subscriber("/qualisys/CSS/odom", Odometry, qualisys.updateQualisysOdometry)
    rospy.Subscriber("/CSS/u", Float64MultiArray, u_data.callback)
    rospy.Subscriber("/CSS/observer", observer_message, observer.callback)
    rospy.Subscriber("/CSS/tau", Float64MultiArray, tau.callback)
    gain_client = dynamic_reconfigure.client.Client('gain_server', timeout=30, config_callback = obs_gains.callback)
    return observer_node

def thrustAllocationNodeInit():
    thrust_allocation_node = rospy.init_node('Thrust_allocation_node')
    rospy.Subscriber("/CSS/tau", Float64MultiArray, tau.callback)
    return thrust_allocation_node


# Destroy node when prompted
def nodeEnd(node):
    node.destroy_node()

