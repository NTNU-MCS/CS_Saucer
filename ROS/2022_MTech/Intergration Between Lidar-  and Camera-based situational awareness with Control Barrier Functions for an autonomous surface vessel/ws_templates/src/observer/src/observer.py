#!/usr/bin/env python3
import rospy
import math
import numpy as np
from commom_tools.lib import ps4, tau, u_data, observer, observerNodeInit, nodeEnd
from common_tools.math_tools import * 
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
from messages import observer_message

# Write your code here


if __name__ == '__main__':
    node = observerNodeInit()
    r = rospy.Rate(100) # Usually set to 100 Hz
    while not rospy.is_shutdown():
        # Calls to any functions and methods should be handled inside this while-loop
        loop()
        r.sleep()
    
    nodeEnd(node)

