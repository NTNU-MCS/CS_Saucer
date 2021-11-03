import rospy
from lib import odometry, ps4, u_data
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
import math
import numpy as np

# Functions for manovering with the DS4 controller
def saturate(u):
    """
    Saturate ensures that the input to the actuator remains bounded to the interval [-1, 1]
    """
    if u > 1:
        u = 1
    elif u < -1:
        u = -1
    return u

def sixaxis2thruster(lStickX, lStickY, rStickX, rStickY, R2, L2):
    """
    sixaxis2thruster() directly maps the sixaxis playstation controller inputs
    to the vessel actuators.
    """
    ### Acutator commands ###
    u1 = -0.5*(L2 - R2)
    u2 = saturate(math.sqrt(lStickX ** 2  + lStickY ** 2))
    u3 = saturate(math.sqrt(rStickX ** 2 + rStickY ** 2))


    ### VSD angles as described in the handbook ###
    alpha1 = math.atan2(lStickX, lStickY)
    alpha2 = math.atan2(rStickX, rStickY)

    u = np.array([u1, u2, u3, alpha1, alpha2])
    return u

### Write your code here ###

### End of custom code ###


def loop():
    """
    Handle all calls to self written functions and publishers in this function. It is called by the 
    script that creates the ROS node and will loop
    """
    u = sixaxis2thruster(ps4.lStickX, ps4.lStickY, ps4.rStickX, ps4.rStickY, ps4.R2, ps4.L2)
    u_data.publish(u)
