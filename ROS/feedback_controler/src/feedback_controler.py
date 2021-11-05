import rospy
import numpy as np
import math
from lib import observer, reference, ps4, u_data, gains
from math_tools import *
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray

### Write your code here ###

def heading_control(psi, r, psi_d, psi_d_dot, psi_d_ddot, k1_psi):
    # Compute heading error
    z1_psi = psi - psi_d

    #Virtual control 
    alpha_r = -k1_psi*z1_psi + psi_d_dot

    # Compute heading rate error
    z2_r = r - alpha_r

    z1_dot_psi = -k1_psi*z1_psi + z2_r

    alpha_dot_psi = -k1_psi*z1_dot_psi + psi_d_ddots

    return alpha_r, alpha_dot_r, z2_r


def positional_control(psi, r, p, v, p_d, p_d_dot, p_d_ddot, s, s_dot, w, v_s, v_st, v_ss, K1):
    # Compute rotational matrix
    R = R2(psi)
    R_T = R.T
    S = np.array([[0, -1],[1, 0]])
    # Compute positonal error 
    z1_p = R_T@(p - p_d)
    alpha_v = -K1@z1_p +  R_T@p_d@v_s
    z2_v = v - alpha_v
    z1_p_dot = -K1@z1_p - r*S@z1_p + z2_v - R_T@p_d_dot@w
    alpha_dot_v = -K1@z1_p_dot + R_dot_T@p_d_dot@v_s + R_T@p_d_ddot@v_s*s_dot + R_T@p_d_dot*(v_ss*s_dot + v_st)
    return alpha_v, alpha_dot_v, z2_v
    #Virtual control 


def clf_control_law(alpha, alpha_dot, z2, K2, xi):
    M = #Define mass matrix for vessel here
    D = #Define damping matrix for vessel here
    xi_dot = z2
    tau = -K2@z2 - gamma@xi + D@alpha + M@alpha_dot
    return xi_dot, tau 

def fld_control_law(v, alpha_dot, z2, K2, xi):
    M = #Define mass matrix for vessel here
    D = #Define damping matrix for vessel here
    xi_dot = z2
    tau = D@v - M@(K2@z2 + gamma@xi - alpha_dot)
    return xi_dot, tau

def consecrate(alpha_r, alpha_dot_r, alpha_v, alpha_dot_v, z2_r, z2_r):
    z2 = np.array([[0][0][z2_r]])
    alpha = np.array([[0][0][alpha_r]])
    alpha_dot = np.array([[0][0][alpha_dot_r]])

    for i in range(1,2)
        z2[1][i] = z2_v[i]
        alpha[1][i] = alpha_v[i]
        alpha_dot[1][i] = alpha_dot_r[i]
    return z2, alpha, alpha_dot


### End of custom code
    
def loop():

    """
    All calls to functions and methods should be handled inside here. loop() is called by the main-function in ctrl_node.py
    """
  