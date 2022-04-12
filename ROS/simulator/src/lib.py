import rospy
from sensor_msgs.msg import Joy
from nav_msgs.msg import Odometry
import numpy as np
import dynamic_reconfigure.client
from std_msgs.msg import Float64MultiArray, Float64
from messages.msg import state_estimation, reference_message, s_message

class Qualisys():
    """
    Retrieves qualisys measurements by listening to the /qualisys/CSS/odom topic
    """
    def __init__(self):
        self.odom = Odometry()
        self.eta = np.zeros(3)
        self.message = Float64MultiArray()
        self.pub = rospy.Publisher('/CSS/eta', Float64MultiArray, queue_size=1)

    def callback(self, data):
        self.odom = data

    def publish(self):
        w = self.odom.pose.pose.orientation.w
        x = self.odom.pose.pose.orientation.x
        y = self.odom.pose.pose.orientation.y
        z = self.odom.pose.pose.orientation.z

        self.eta[0] = self.odom.pose.pose.position.x
        self.eta[1] = self.odom.pose.pose.position.y
        self.eta[2] = quat2eul(x, y, z, w)[2]
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

class UVector():
    """
    The UVector initializing and publishing the computed actuator commands
    """
    def __init__(self):
        self.Udata = np.zeros(5)
        self.pub = rospy.Publisher('CSEI/u', Float64MultiArray, queue_size = 1)
        self.message = Float64MultiArray()

    def publish(self, data):
        self.message.data = data
        self.pub.publish(self.message)

    def callback(self, udata):
        self.Udata = udata


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

class Reference_Converser():
    """
    The reference converser listens and publishes to the CSEI/reference topic
    """
    # Initialize the guidance parameters in [0; 0; 0]
    def __init__(self):
        self.ref_msg = reference_message()
        self.pub = rospy.Publisher('/CSEI/reference/', reference_message, queue_size=1)
        self.eta_d = np.array([0, 0, 0])
        self.eta_ds = np.array([0, 0, 0])
        self.eta_ds2 = np.array([0, 0, 0])

    # Callback function is called when the topic is updated
    def callback(self, msg):
        self.eta_d = np.array(msg.eta_d)
        self.eta_ds = np.array(msg.eta_ds)
        self.eta_ds2 = np.array(msg.eta_ds2)

    # Publishes new gains to the reference topic. These should be numpy arrays with n=3
    def publish(self, eta_d, eta_ds, eta_ds2):
        self.ref_msg.eta_d = eta_d
        self.ref_msg.eta_ds = eta_ds
        self.ref_msg.eta_ds2 = eta_ds2
        self.pub.publish(self.ref_msg)

    # Retrieve the references from the object
    def get_ref(self):
        return self.eta_d, self.eta_ds, self.eta_ds2


class Paramterization_Variable():
    """
    May need to be changed to account for a two variable paramterization
    """
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

class Controller_Gains():
    """
    Controller gains retrieves the parameters from the dynamic_reconfigure server.
    """
    # Initialize all gains to zero
    def __init__(self):
        self.Kp = np.zeros(3)
        self.Kd = np.zeros(3)
        self.Ki = np.zeros(3)
        self.mu = 0
        self.Uref = 0

    # Retrieves the gaines
    def get_data(self):
        return self.Kp, self.Kd, self.Ki, self.mu, self.Uref

    # Updates gains everytime the parameters are tuned
    def callback(self, config):
        self.Kp = self.string2array(config.Kp)
        self.Kd = self.string2array(config.Kd)
        self.Ki = self.string2array(config.Ki)
        self.mu = config.mu
        self.Uref = config.U_ref



    def string2array(self, string):
        """
        dynamic_reconfigure does not handle arrays, so gains like L1 or KP are strings on the form "x11,x12,x13"
        in the server to limit the number of variables. This function converts the string into a numpy array when
        they are retrieved. Very scuffed, but if it works, it works :^)
        """
        return np.array(list(map(float, string.split(','))))
        
# Build the objects to be imported
ps4 = DS4_Controller()
u_data = UVector()
qualisys = Qualisys()
observer = Observer_Converser()
gains = Controller_Gains()
reference = Reference_Converser()
s_p = Paramterization_Variable()

# Initialize controller node
def controllNodeInit():
    node = rospy.init_node('Controller')
    rospy.Subscriber("joy", Joy, ps4.updateState)
    rospy.Subscriber("CSS/u", Float64MultiArray, u_data.callback)
    rospy.Subscriber("CSS/observer", observer_message, observer.callback)
    rospy.Subscriber("CSS/reference", reference_message, reference.callback)
    gain_client = dynamic_reconfigure.client.Client('gain_server', timeout=30, config_callback = gains.callback)
    return node

def kalmanNodeInit():
    node = rospy.init_Node('Kalman_Filter')
    rospy.Subscriber("joy", Joy, ps4.updateState)
    rospy.Subscriber("CSS/u", Float64MultiArray, u_data.callback)
    rospy.Subscriber("CSS/observer", state_estimation, observer.callback)
    rospy.Subscriber("qualisys/CSS/odom", )
    gain_client = dynamic_reconfigure.client.Client('gains_server', timeout=30, confign_callback = gains.callback)
    return node

def thrustAllocationNodeInit():
    thrust_allocation_node = rospy.init_node('Thrust_allocation_node')
    rospy.Subscriber("/CSS/tau", Float64MultiArray, tau.callback)
    return thrust_allocation_node


def guidanceNodeInit():
    guidance_node = rospy.init_node('guidance_node')
    rospy.Subscriber("/CSS/observer", state_estimation, observer.callback)
    rospy.Subscriber("/CSS/reference", reference_message, reference.callback)
    rospy.Subscriber("/CSS/s", s_message, s_p.callback)
    rospy.Subscriber("/joy", Joy, ps4.updateState)
    #gain_client = dynamic_reconfigure.client.Client('gain_server', timeout=30, config_callback = gains.callback)
    return guidance_node

# Destroy node when prompted
def nodeEnd(node):
    node.destroy_node()
