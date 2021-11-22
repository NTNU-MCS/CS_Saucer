import rospy
import numpy as np
import math
from lib import qualisys, tau, observer, gains
from math_tools import Rzyx, rad2pipi


### Write your code here ###

def ekf():
    return 0

def luenberger(eta, eta_hat, nu_hat, b_hat, tau, L1, L2, L3, dt):
"""---------------------------------------------------------------------------- 
# Name: luenberger                                                            #  
# Input: eta, eta_hat, tau, L1, L2, L3, dt                                    #
# Outputs: new_eta_hat, new_nu_hat, new_b_hat                                             #
#                                                                             #
# Implements a Luenberger observer for the CS-Saucer. It estimates position   #
# velocity and any potential bias.                                            #
#                                                                             #
#                                                                             #
#                                                                             #
# Authour: Mathias N. Solheim                                                 #
# Date: 15.09.2021                                                            #
----------------------------------------------------------------------------"""
    # Ship dynamics
    M = np.array([[9.51, 0.0, 0.0], [0.0, 9.51, 0], [0.0, 0.0, 0.116]])  # Inertia matrix
    D = np.diag(np.array([1.96, 1.96, 0.196])) # Symmetry :))
    M_inv = np.inv(M)

    # Observer gains
    L1 = np.diag(L1)
    L2 = np.diag(L2)
    L3 = np.diag(L3)

    # Compute our rotation matrices: 
    psi = rad2pipi(eta[2])
    R   = Rzyx([psi])
    R_T = R.T

    # Error computation between postion and previous estimate
    eta_bar     = eta - eta_hat
    eta_bar[2]  = rad2pipi(eta[2])

    # Dynamic equations
    eta_hat_dot = R@nu_hat + L1@eta_bar
    nu_dot_hat  = M_inv@(-D@nu_hat + R_T@b_hat + R_T@L2@eta_bar + tau)
    b_dot_hat   = L3@eta_bar

    # Euler integration
    new_eta_hat = eta_hat + dt*eta_dot_hat
    new_nu_hat  = nu_hat + dt*nu_dot_hat
    new_b_hat   = b_hat + dt*b_dot_hat
    return new_eta_hat, new_nu_hat, new_b_hat

### End of student code ###

def loop():
    """
    All calls to functions and methods should be handled inside here. loop() is called by the main-function in obs_node.py
    """
    # Extract data
    dt = 0.01
    eta = qualisys.get_data()
    eta_hat, nu_hat, b_hat = observer.get_observer_data()
    tau = tau.get_tau()
    L1, L2, L3 = gains.get_observer_gains()
    
    # Compute new estimations

    new_eta_hat, new_nu_hat, new_b_hat = luenberger(eta, eta_hat, nu_hat, b_hat, tau, L1, L2, L3, dt)

    #publish new estimates
    observer.publish(new_eta_hat, new_nu_hat, new_b_hat)
    return 0