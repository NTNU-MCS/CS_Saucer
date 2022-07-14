#!/usr/bin/env python3
import rospy
import numpy as np
import math
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
from common_tools.lib import ps4, tau, u_data, controllNodeInit, nodeEnd
from common_tools.math_tools import * 

### Write your code here ###

# Example functions for manuevering with the DS4 controller
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



if __name__ == '__main__':

    node = controllNodeInit()
    r = rospy.Rate(100)

    while not rospy.is_shutdown():
    	# Handle calls to methods or functions as below
        u = sixaxis2thruster(ps4.lStickX, ps4.lStickY, ps4.rStickX, ps4.rStickY, ps4.R2, ps4.L2) # Computes the acutator command
        u_data.publish(u) 									    # Publishes computed value to CSE1/u
        r.sleep()
    
    nodeEnd(node)
