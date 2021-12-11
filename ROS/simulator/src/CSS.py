#!/usr/bin/env python3
import math
import rospy
import numpy as np
from math_tools import *
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray

# The C/S enterprise I object
class CSS:
    """
    The CSS object represents the C/S Saucer and contains the necessary
    kinematics and dynamics of the ship, as well as the operations required to
    "move" the ship over one time-step
    """
    ### Main data of the C/S Saucer. Do not touch ###
    _M = np.array([[9.51, 0.0, 0.0], [0.0, 9.51, 0], [0.0, 0.0, 0.116]])  # Inertia matrix
    _D = np.diag(np.array([1.96, 1.96, 0.196]))
    _rt = 0.138 # Radius-distance to thrusters
    _alphat = np.array([np.pi/2, 4*np.pi/3, 2*np.pi/3]) # Angle of thrusters relative to x-axis of body frame
    _lx = np.array([_rt*np.cos(_alphat[0]), _rt*np.cos(_alphat[1]), _rt*np.cos(_alphat[2])])
    _ly = np.array([_rt*np.sin(_alphat[0]), _rt*np.sin(_alphat[1]), _rt*np.sin(_alphat[2])])
    ### Initialization ###

    def __init__(self, eta0):
        self.Dv = np.array([np.zeros(3), np.zeros(3), np.zeros(3)])
        self.C = np.array([np.zeros(3), np.zeros(3), np.zeros(3)])
        self.eta = eta0
        self.nu = np.array([[0], [0], [0]])  # Assuming the vessel always starts stationary
        self.tau = np.array([[0], [0], [0]])  # Zero forces and moments at initialization
        self.nu_dot = np.array([[0], [0], [0]])
        self.eta_dot = np.array([[0], [0], [0]])
        self.odom = Odometry() #Msg to be published
        self.odom.header.frame_id = "odom"
        self.tauMsg = Float64MultiArray()
        self.etaMsg = Float64MultiArray()
        self.pubOdom = rospy.Publisher('/qualisys/CSS/odom/', Odometry, queue_size=1)
        self.pubTau = rospy.Publisher('/CSS/tau/', Float64MultiArray, queue_size=1)
        self.pubEta = rospy.Publisher('/CSS/eta/', Float64MultiArray, queue_size=1)
        self.subU = rospy.Subscriber('/CSS/u/', Float64MultiArray, self.callback)
        self.u = np.zeros(6)
        self.dt = 0.01
    
    ### Computation ###
    def set_Dv(self):
        u = np.abs(self.nu[0][0])
        v = np.abs(self.nu[1][0])
        r = np.abs(self.nu[2][0])
        new_Dv = np.array([[7.095*u, 0, 0], [0, 7.095*v, 0], [0, 0, 7.095*r]])
        self.Dv = new_Dv  # Designates the damping matrix
        

    def set_C(self):
        r = self.nu[2][0]
        c12 = -9.51*r
        c21 = -c12 
        new_C = np.array([[0, c12, 0], [c21, 0, 0], [0, 0, 0]])
        self.C = new_C

    def set_tau(self, u):
        u_t = np.take(u, [0, 1, 2])
        u_t = u_t[:, np.newaxis]
        alpha = np.take(u, [3, 4, 5])
        c1 = math.cos(alpha[0])
        c2 = math.cos(alpha[1])
        c3 = math.cos(alpha[2])
        s1 = math.sin(alpha[0])
        s2 = math.sin(alpha[1])
        s3 = math.sin(alpha[2])
        #B = np.array([[c1, c2, c3], [s1, s2, s3], [self._lx[0]*s1-self._ly[0]*c1, self._lx[1]*s2 - self._ly[1]*c2, self._lx[2]*s3-self._ly[2]*c3]])
        B = np.array([[0, np.sin(2*np.pi/3), np.sin(4*np.pi/3)],
                 [1, np.cos(2*np.pi/3), np.cos(4*np.pi/3)],
                 [0.138, 0.138, 0.138]])
        new_tau = B @ u_t
        self.tau = new_tau

    def set_eta(self):
        psi = rad2pipi(self.eta[2])
        R = Rzyx(psi)
        self.eta_dot = np.dot(R, self.nu)
        self.eta = self.eta + self.dt*self.eta_dot
        self.eta[2] = rad2pipi(self.eta[2]) # Wrap the angle

    def set_nu(self):
        A = self._M
        b = self.tau - np.dot((self.C + self._D + self.Dv), self.nu)
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
        quat = yaw2quat(self.eta[2])

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

    def publishEta(self):
        self.etaMsg.data = self.eta
        self.pubEta.publish(self.etaMsg)


    #Upon a new U, move the ship
    def callback(self, msg):
        self.u = msg.data
        self.set_C()  # Coreolis matrix
        self.set_Dv()  # Compute damping matrix
        self.set_tau(self.u) # Compute the force vector
        self.set_nu()   # Compute the velocity
        self.set_eta()  # Compute the position
        self.publishOdom() # Publish the new position


    ### End of publishers and subscribers ###

initial_conditions = np.array([[0],[0],[0]])
ship = CSS(initial_conditions)

def main():
   
    rospy.init_node('HIL_simulation')
    rate = rospy.Rate(100)
    rospy.Subscriber("/CSS/u/", Float64MultiArray, ship.callback)
  
    while not rospy.is_shutdown():
        ship.publishOdom()
        rate.sleep()

    rospy.spin()
    rospy.shutdown()

if __name__ == '__main__':
    main()

