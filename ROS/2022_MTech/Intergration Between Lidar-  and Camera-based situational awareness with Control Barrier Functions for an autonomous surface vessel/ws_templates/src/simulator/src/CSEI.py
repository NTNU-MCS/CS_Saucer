#!/usr/bin/env python3
import math

import numpy as np
import rospy
import sys
sys.path.insert(0, '') 

from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
from src.tools.math_tools import *


# The C/S enterprise I object
class CSEI:
    """
    The CSEI object represents the C/S Enterprise and contains the necessary
    kinematics and dynamics of the ship, as well as the operations required to
    "move" the ship over one time-step
    """
    ### Main data of the C/S Enterprise. Do not touch ###
    _M = np.array([[16.11, 0.0, 0.0], [0.0, 24.11, 0.5291], [0.0, 0.5291, 2.7600]])  # Inertia matrix
    _X = np.array([-0.6555, 0.3545, -3.787, 0.0, -2.443, 0.0]) # Hydro surge [Xu, Xuu, Xuuu, Xv, Xvv, Xvvv]
    _Y = np.array([-1.3443, -2.776, -65.91, -7.25, -3.45, 0.0, -0.805, -0.845]) # Hydro sway [Yv, Yvv, Yvvv, Yr, Yrr, Yrrr, Yrv, Yvr]
    _N = np.array([0.0, -0.2088, 0.0, -1.9, -0.75, 0.0, 0.130, 0.080]) # Hydro yaw [Nv, Nvv, Nvvv, Nr, Nrr, Nrrr, Nrv, Nvr]
    _A = np.array([-2, -10, -0, -1]) # Added mass [Xu, Yv, Yr, Nr]
    _m = 14.11  # Rigid body mass
    _Iz = 1.7600  # Inertial moment
    _xg = 0.0375  # Center of gravity
    lx1 = 0.3875
    lx2 = -0.4574
    lx3 = -0.4574
    ly1 = 0
    ly2 = -0.055
    ly3 = 0.055
    
    _K = np.diag([2.629, 1.03, 1.03])  # K-matrix

    ### Initialization ###

    def __init__(self, eta0):
        self.D = np.array([np.zeros(3), np.zeros(3), np.zeros(3)])
        self.C = np.array([np.zeros(3), np.zeros(3), np.zeros(3)])
        self.eta = eta0
        self.nu = np.array([[0], [0], [0]])  # Assuming the vessel always starts stationary
        self.tau = np.array([[0], [0], [0]])  # Zero forces and moments at initialization
        self.nu_dot = np.array([[0], [0], [0]])
        self.eta_dot = np.array([[0], [0], [0]])
        self.odom = Odometry() #Msg to be published
        self.odom.header.frame_id = "odom"
        self.tauMsg = Float64MultiArray()
        self.pubOdom = rospy.Publisher('/qualisys/CSEI/odom', Odometry, queue_size=1)
        self.pubTau = rospy.Publisher('/CSEI/tau', Float64MultiArray, queue_size=1)
        self.subU = rospy.Subscriber('/CSEI/u', Float64MultiArray, self.callback)
        self.u = np.zeros(5)
        self.dt = 0.01
        

    ### Computation ###
    def set_D(self):
        u = self.nu[0]
        v = self.nu[1]
        r = self.nu[2]
        d11 = (-self._X[0] - self._X[1]*np.abs(u) - self._X[2]*(u**2))[0]
        d22 = (-self._Y[0] - self._Y[1]*np.abs(v) - self._Y[2]*(v**2))[0]
        d33 = (-self._N[3] - self._N[7]*np.abs(v) - self._N[5]*(r**2))[0]
        d23 = (-self._Y[3] - self._Y[7]*np.abs(v) - self._Y[4]*np.abs(r) - self._Y[5]*(r**2))[0]
        d32 = (-self._N[0] - self._N[2]*np.abs(v) - self._N[3]*(v**2) - self._N[6]*np.abs(r))[0]
        new_D = np.array([[d11, 0, 0], [0, d22, d23], [0, d32, d33]])
        self.D = new_D  # Designates the damping matrix

    def set_C(self):
        u = self.nu[0]
        v = self.nu[1]
        r = self.nu[2]
        c13 = ((-self._m*self._xg + self._A[2])*r + (-self._m + self._A[1])*v)[0]
        c23 = ((self._m - self._A[0])*u)[0]
        new_C = np.array([[0, 0, c13], [0, 0, c23], [-c13, -c23, 0]])
        self.C = new_C

    def set_tau(self, u):
        u_t = np.transpose(np.take(u, [0, 1, 2])[np.newaxis])
        alpha = np.take(u, [3, 4])
        c1 = 0
        c2 = math.cos(alpha[0])
        c3 = math.cos(alpha[1])
        s1 = 1
        s2 = math.sin(alpha[0])
        s3 = math.sin(alpha[1])
        B = np.array([[c1, c2, c3], [s1, s2, s3], [self.lx1*s1-self.ly1*c1, self.lx2*s2 - self.ly2*c2, self.lx3*s3-self.ly3*c3]])
        new_tau = (B @ self._K) @ u_t
        self.tau = new_tau

    def set_eta(self):
        psi = self.eta[2]
        R = Rzyx(psi)
        self.eta_dot = np.dot(R, self.nu)
        self.eta = self.eta + self.dt*self.eta_dot
        self.eta[2] = rad2pipi(self.eta[2]) # Wrap the angle

    def set_nu(self):
        A = self._M
        b = self.tau - np.dot((self.C + self.D), self.nu)
        self.nu_dot = np.linalg.solve(A, b)
        self.nu = self.nu + self.dt*self.nu_dot  # Integration, forward euler

    def get_tau(self):
        return self.tau

    def get_eta(self):
        return self.eta

    def get_nu(self):
        return self.nu

    ### Publishers and subscribers ###   

    def nav_msg(self):
        """
        Computes the Odometry message of the ship
        """
        quat = yaw2quat(self.eta[2][0])

        self.odom.pose.pose.position.x = self.eta[0]
        self.odom.pose.pose.position.y = self.eta[1]
        self.odom.pose.pose.position.z = 0
        self.odom.pose.pose.orientation.w = quat[0]
        self.odom.pose.pose.orientation.x = quat[1]
        self.odom.pose.pose.orientation.y = quat[2]
        self.odom.pose.pose.orientation.z = quat[3]

        self.odom.twist.twist.linear.x = self.nu[0]
        self.odom.twist.twist.linear.y = self.nu[1]
        self.odom.twist.twist.linear.z = 0
        self.odom.twist.twist.angular.x = 0
        self.odom.twist.twist.angular.y = 0
        self.odom.twist.twist.angular.z = self.nu[2]

    def get_odom(self):
        return self.odom

    def publishOdom(self):
        self.nav_msg()
        self.pubOdom.publish(self.odom)
    
    def publishTau(self):
        self.tauMsg.data = self.tau
        self.pubTau.publish(self.tauMsg)

    #Upon a new U, move the ship
    def callback(self, msg):
        self.u = msg.data
        #self.set_C()  # Coreolis matrix
        self.set_D()  # Compute damping matrix
        self.set_tau(self.u) # Compute the force vector
        self.publishTau()   # Publish the tau, this is needed for the Observer :)
        self.set_nu()   # Compute the velocity
        self.set_eta()  # Compute the position
        self.publishOdom() # Publish the new position


    ### End of publishers and subscribers ###

initial_conditions = np.array([[0],[0],[0]])
ship = CSEI(initial_conditions)

def main():

    rospy.init_node('HIL_simulation')
    rate = rospy.Rate(100)
    rospy.Subscriber("CSEI/u", Float64MultiArray, ship.callback)

    while not rospy.is_shutdown():
        ship.publishOdom()
        rate.sleep()

    rospy.spin()
    rospy.shutdown()

if __name__ == '__main__':
    main()

