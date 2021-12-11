import rospy
import numpy as np
import math
from lib import tau, u_data
from math_tools import *


def fixed_thrust_allocation(tau):
#---------------------------------------------#
# name: fixed_thrust_allocation               #  
# input: tau                                  #
# outputs: u                                  #
#                                             #
# A fixed angle thrust allocation for the C/S #
# Saucer. Based on the work of Einar Ueland.  #
#                                             #
#                                             #
# authour: Mathias N. Solheim                 #
# date: 11.09.2021                            #
#---------------------------------------------#
    
    r = 0.138 # Radius to vessels center of origin
    alpha =  np.array([np.pi, 2*np.pi/3, 4*np.pi/3])             # Fixed azimuth angles
    B = np.array([[0, np.sin(2*np.pi/3), np.sin(4*np.pi/3)],
                  [1, np.cos(2*np.pi/3), np.cos(4*np.pi/3)],
                  [r, r, r]])
    u_fix = np.linalg.inv(B)@tau     
    u = np.array([u_fix[0][0], u_fix[1][0], u_fix[2][0], alpha[0], alpha[1], alpha[2]])    
    return u

def loop():
    """
    All calls to functions and methods should be handled inside here. loop() is called by the main-function in obs_node.py
    """
    # Get parameters

    tau_forces = tau.get_tau()
    tau_forces = tau_forces[:, np.newaxis]
    # compute the thrust allocation 
    u = fixed_thrust_allocation(tau_forces)
    u_data.publish(u)
    return 0
