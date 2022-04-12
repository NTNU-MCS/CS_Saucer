import rospy
import numpy as np
import math
sys.path.insert(0,'')
from src.tools.lib import qualisys, tau, observer, obs_gains
from src.tools.math_tools import *


### Write your code here ###

def luenberger(eta, eta_hat, nu_hat, b_hat, tau, L1, L2, L3, dt):
    # Ship dynamics
    M = np.array([[9.51, 0.0, 0.0], [0.0, 9.51, 0], [0.0, 0.0, 0.116]])  # Inertia matrix
    D = np.diag(np.array([1.96, 1.96, 0.196])) # Symmetry :))
    M_inv = np.linalg.inv(M)

    # Observer gains
    L1 = np.diag(L1)
    L2 = np.diag(L2)
    L3 = np.diag(L3)
    # Compute our rotation matrices:
    psi = rad2pipi(eta[2])
    R   = Rzyx(psi)
    R_T = np.transpose(R)

    # Error computation between postion and previous estimate
    eta_bar = eta - eta_hat
    eta_bar[2] = rad2pipi(eta_bar[2])

    # Dynamic equations
    eta_dot_hat = R@nu_hat + L1@eta_bar
    nu_dot_hat  = M_inv@(-D@nu_hat + R_T@b_hat + R_T@L2@eta_bar + tau)
    b_dot_hat   = L3@eta_bar

    # Euler integration
    new_eta_hat = eta_hat + dt*eta_dot_hat
    new_nu_hat  = nu_hat + dt*nu_dot_hat
    new_b_hat   = b_hat + dt*b_dot_hat

    new_eta_hat[2] = rad2pipi(new_eta_hat[2])
    return new_eta_hat, new_nu_hat, new_b_hat

### End of student code ###

def loop():
    """
    All calls to functions and methods should be handled inside here. loop() is called by the main-function in obs_node.py
    """
    # Extract data
    dt = 0.01
    eta = qualisys.getQualisysOdometry()
    eta[2] = rad2pipi(eta[2])
    eta = eta[:, np.newaxis]
    eta_hat, nu_hat, b_hat = observer.get_observer_data()
    eta_hat = eta_hat[:, np.newaxis]
    nu_hat = nu_hat[:, np.newaxis]
    b_hat = b_hat[:, np.newaxis]
    tau_forces = tau.get_tau()
    tau_forces = tau_forces[:, np.newaxis]
    L1, L2, L3 = obs_gains.get_observer_gains()

    # Compute new estimations

    new_eta_hat, new_nu_hat, new_b_hat = luenberger(eta, eta_hat, nu_hat, b_hat, tau_forces, L1, L2, L3, dt)
    new_eta_hat = np.array([new_eta_hat[0], new_eta_hat[1], new_eta_hat[2]])
    new_nu_hat = np.array([new_nu_hat[0], new_nu_hat[1], new_nu_hat[2]])
    new_b_hat = np.array([new_b_hat[0], new_eta_hat[1], new_b_hat[2]])
    #publish new estimates
    observer.publish(new_eta_hat, new_nu_hat, new_b_hat)
    return 0
