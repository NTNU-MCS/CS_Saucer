#!/usr/bin/env python3
import rospy
import numpy as np
from common_tools.tools.lib import tau, u_data, thrustAllocationNodeInit, nodeEnd
from common_tools.math_tools import *
from std_msgs import Float64MultiArray



if __name__ == '__main__':

    node = thrustAllocationNodeInit()
    r = rospy.Rate(100) # Usually set to 100 Hz

    while not rospy.is_shutdown():
        
        
        r.sleep()
    
    nodeEnd(node)
