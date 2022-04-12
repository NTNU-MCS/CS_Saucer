import rospy
import numpy as np
import math
from lib import tau, u_data
from math_tools import *


def fixed_thrust_allocation(tau):
    r = 0.138 # Radius to vessels center of origin
    alpha =  np.array([np.pi, 2*np.pi/3, 4*np.pi/3])             # Fixed azimuth angles
    B = np.array([[0, np.sin(alpha[1]), np.sin(alpha[2])],
                  [1, np.cos(alpha[1]), np.cos(alpha[2])],
                  [r, r, r]])
    u_fix = np.linalg.pinv(B)@tau
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
