import rospy
from lib import odometry, ps4, u_data
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
from math_tools import rad2pipi
import math
import numpy as np


### Write your code here ###

def waypoint_generations():
"""---------------------------------------------------------------------------- 
# Name: straight_line_path                                                    #  
# Input: Sensor data                                                          #
# Outputs: p0, p1                                                             #
#                                                                             #
# This function should generate waypoints based on the input of the lidar     #
# and the camera prayge                                                       #
#                                                                             #
#                                                                             #
#                                                                             #
# Authour: Mathias N. Solheim                                                 #
# Date: 10.09.2021                                                            #
----------------------------------------------------------------------------"""
return 0 

def decoupled_straight_line_path(U_ref, s, p0, p1):
"""---------------------------------------------------------------------------- 
# Name: straight_line_path                                                    #  
# Input: U_ref, s, p0, p1                                                     #
# Outputs: eta_d, eta_d_prime, eta_d_prime2                                   #
#                                                                             #
# Generates a straigt line reference for a decoupled controller in yaw        #
#                                                                             #
#                                                                             #
#                                                                             #
# Authour: Mathias N. Solheim                                                 #
# Date: 10.09.2021                                                            #
----------------------------------------------------------------------------"""

    # Initialize positional reference
    p_d = np.zeros(2)
    p_d_prime = np.zeros(2)
    p_d_prime2 = np.zeros(2)

    # Compute desired reference p_d and its derivatives
    p_d = (1 - s)*p0 - s*p1
    p_d_prime = p1 - p0
    
    # Compute desired heading psi_d and its derivatives
    psi_d = rad2pipi(math.atan2(p1[1] - p0[1], p1[0] - p0[0]))
    psi_d_prime = 0
    psi_d_prime2 = 0
    
    
    return eta_d, eta_d_prime, eta_d_prime2, psi_d, psi_d_prime, psi_d_prime2

def decoupled_figure8_path()
    return 
    

    


### End of custom code ###


def loop():
    """
    Handle all calls to self written functions and publishers in this function. It is called by the 
    script that creates the ROS node and will loop
    """
    
