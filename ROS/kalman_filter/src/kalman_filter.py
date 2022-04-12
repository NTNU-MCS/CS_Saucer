#!/usr/bin/env python3
# ----------------------------------------------------------------------------
# This code is part of the Mathias Solheim's master thesis, and contains an
# implementation of a Linear Time Varying kalman filter in a ROS-node, to be
# used as part of a control-system for the CS Saucer.
#
# Created By: M. Solheim
# Created Date: 2022-04-08
# Version = '1.0'
# Revised: <date>	<developer> <description>
#          <date>	<developer> <description>
# Tested:  2022-04-08 M.Solheim
#
# Copyright (C) 202x: <organization>, <place>
# Licensed under GPL-3.0-or-later
# ---------------------------------------------------------------------------

import rospy
import numpy as np
import math
sys.path.insert(0,'')
from src.tools.lib import qualisys, tau, obs_gains, kalmanNodeInit
from src.tools.math_tools import Rzyx

class LTV_KF(object):
    """
    The LTV_KF obejct implements a Linear Time Varying Kalman Filter for the CS Saucer.
    Most of the class i generic, and can be recycled for other projects and vessels with
    the method updateA being the exception. This assumes a 3DOF DP-model, with no waves or
    currents acting which simplifies the the system to 9 states rather than a 15-state which
    is typical for a DP-system. A is therefore a 9x9 matrix.

    x = [eta^T, nu^T, b^t]^T
    """
    def __init__(self, A = None, B = None, H = None, Q = None, P = None, x0 = None, h = 0.01):
        """
        Initializes the Kalman Filter object.
        """
        if (A is None or H is None): # Check for valid system dynamics
            raise ValueError("Set proper system dynamics")

        # Get system dimensions
        self.n = A.shape[1]
        self.m = H.shape[1]
        # Initialize system dynamics and intial conditions
        self.A = A                                               # System matrix
        self.B = 0 if B is None else B
        self.H = H                                               # Observation Matrix
        self.Q = np.eye(self.n) if Q is None else Q
        self.R = np.eye(self.n) if R is None else R
        self.P_hat = np.eye(self.n) if P is None else
        self.x_hat = np.zeros((self.n, 1)) if x0 is None else x0 # state estimation
        self.h = h                                               # timestep

        # Initialization of predicted estimates
        self.x_p = np.zeros(self.n, 1)
        self.P_p = np.eye(self.n)

        # Discretized system Matrices
        self.Ad = self.A
        self.Bd = self.B


    def predict(self, u = 0):
        """
        Predicts the state estimate at a given time t based on the
        previous state estimate t-1 and the control input u
        """
        self.x_p = self.Ad @ self.x_hat + self.Bd@u
        self.P_p = (self.Ad@self.P_hat)@np.transpose(self.Ad) + self.Q
        return self.x_p

    def correct(self, z):
        K = (self.P_p@self.H.T)@np.inv((self.H@self.P_p)@self.H.T + self.R) # Kalman gains
        IKC = eye(self.n) - K@self.H                                        # Just a placeholder for prettier code
        y = z - self.H@self.x_p                                             # Should be som wrapping on angles here i think

        self.x_hat = self.x_p + K@y                                         # State estimation
        self.P_hat = (IKC@self.P_p)@IKC.T + (K@self.R)@K.T

    def discretize(self):
        """
        Discretizes the system matrices according to section 13.4.6
        in Fossen (2021)
        """
        self.Ad = eye(self.n) + self.h*self.A
        self.Bd = self.h*self.B

    def updateA(self, psi_t):
        "Updates the state matrix must be updated to account for the change in heading"
        M = np.diag(rospy.get_param('~kalman_filter/model/M'))  # Extract Intertia matrix
        D = np.diag(rospy.get_param('~kalman_filter/model/D'))  # Extract Damping matrix
        Rt = Rzyx(psi_t)                                        # Compute the rotation matrix at current timestep
        Rt_T = np.transpose(Rt)                                 # Transpose rotation

        M1 = np.inv(M)@Rt_T b

        self.A[0:3, 6:9] = Rt[:, :]
        self.A[3:6, 3:6] = M1[:, :]


if __name__ == '__main__':
    node = kalmanNodeInit()
    r = rospy.Rate(100) # Sets refresh-rate to 100 Hz

    # Initial states
    kf = LTV_KF()
    while not rospy.is_shutdown():


        r.sleep()

    nodeEnd(node)
