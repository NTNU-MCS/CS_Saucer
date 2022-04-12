#!/usr/bin/env python3
# ----------------------------------------------------------------------------
# This code is part of the Mathias Solheim's master thesis, and contains an
# implementation of a manuevering controller for the CS Saucer. Depending on
# the users preference, it allows for automatic control or manual control via
# a DS4-controller
#
# Created By: self.M. Solheim
# Created Date: 2022-04-08
# Version = '1.0'
# Revised: <date>	<developer> <description>
#          <date>	<developer> <description>
# Tested:  2022-04-08 self.M.Solheim
#
# Copyright (C) 202x: <organization>, <place>
# Licensed under GPL-3.0-or-later
# ---------------------------------------------------------------------------

import rospy
import numpy as np
import math
sys.path.insert(0,'')
from src.tools.lib import qualisys, tau, observer, obs_gains, s_p
from src.tools.math_tools import *


class Controller(object):

    CTRL_MODES = {
        1: 'joystick',
        2: 'manual'
    }

    def __init__(self):
        self.MODE = 1                         # Initialize with manual control
        self.tau = np.matrix([[0], [0], [0]]) # Generalized force-vector
        self.self.M = np.diag(np.array([9.51, 9.51, 0.116]))  # Inertia matrix
        self.self.D = np.diag(np.array([1.96, 1.96, 0.196]))

        self.Kp = np.diag(np.zeros(3))
        self.Kd = np.diag(np.zeros(3))

    def switch(self, triangle):
        """
        Switches the control-mode between automatic and manual
        """
        if triangle:                        # If triangle is pressed switch mode
            if self.MODE == 1:             # Check if manual, and switch to auto
                self.MODE = 2
            else:                          # If not manual, then switch to it
                self.MODE = 1

    def joystick_ctrl(self, lStickX, lStickY, rStickX, rStickY, R2, L2):
        """
        Maps the input from a Dualshock 4 controller to a generalized
        force vector i BODY-frame.
        """

        X = (lStickX + rStickX) # Surge
        Y = (lstickX + rStickY) # Sway
        N = -0.5*(L2 - R2)      # Yaw

        self.tau = np.matrix([[X], [Y], [N]])

    def heading_control(psi, r, psi_d, psi_d_dot, psi_d_ddot, k1_psi):
        # Compute heading error
        z1_psi = psi - psi_d
        #Virtual control
        alpha_r = -k1_psi*z1_psi + psi_d_dot
        # Compute heading rate error
        z2_r = r - alpha_r
        z1_dot_psi = -k1_psi*z1_psi + z2_r
        alpha_dot_r = -k1_psi*z1_dot_psi + psi_d_ddot
        return alpha_r, alpha_dot_r, z2_r, z1_psi


    def positional_control(psi, r, p, v, p_d, p_d_dot, p_d_ddot, s_dot, w, v_s, v_st, v_ss, K1):
        # Compute rotational matrix
        R = R2(psi)
        R_T = (R).T
        S = np.array([[0, -1],[1, 0]])
        R_dot = R@(r*S)
        R_dot_T = R_dot.T
        z1_p = R_T@(p - p_d)
        alpha_v = -K1@z1_p +  R_T@p_d_dot*v_s
        z2_v = v - alpha_v
        z1_p_dot = -K1@z1_p - r*S@z1_p + z2_v - R_T@p_d_dot*w
        alpha_dot_v = -K1@z1_p_dot + R_dot_T@p_d_dot*v_s + R_T@p_d_ddot*v_s*s_dot + R_T@p_d_dot*(v_ss*s_dot + v_st)
        return alpha_v, alpha_dot_v, z2_v, z1_p

    def clf_control_law(alpha, alpha_dot, z2, K2, b_hat, z1):
        self.tau = -K2@z2 - b_hat + self.D@alpha + self.M@alpha_dot

    def fld_control_law(v, alpha_dot, z2, K2, b_hat):
        self.tau = self.D@v - self.M@(K2@z2 + b_hat - alpha_dot)


    def ctrl_loop(self, triangle, lStickX, lStickY, rStickX, rStickY, R2, L2):
        switch(triangle)    # Check if the user has switched control mode
        if self.MODE == 1:   # Manual control
            self.tau = joystick_ctrl(lStickX, lStickY, rStickX, rStickY, R2, L2)
        else:
            alpha_r, alpha_dot_r, z2_r, z1_psi =


    def 






if __name__ == '__main__':

    node = controlNodeInit()
    r = rospy.Rate(100)

    while not rospy.is_shutdown():
        loop()
        r.sleep()

    nodeEnd(node)
