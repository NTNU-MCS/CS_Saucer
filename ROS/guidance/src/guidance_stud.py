import rospy
from lib import observer, reference, ctrl_gains, s_p
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
from math_tools import rad2pipi
import math
import numpy as np


### Write your code here ###

def waypoint_generations():
    return 0 

def decoupled_straight_line_path(s, p0, p1):
    # Initialize positional reference
    p_d = np.zeros(2)
    p_d_prime = np.zeros(2)
    p_d_prime2 = np.zeros(2)
    p_d_prime3 = np.zeros(3)

    # Compute desired reference p_d and its derivatives
    p_d = s*p1 + (1 - s)*p0 
    p_d_prime = p1 - p0

    return p_d, p_d_prime, p_d_prime2, p_d_prime3

def decoupled_figure8_path(s, p0, R):
    # Initialize
    p_d = np.zeros(2)
    p_d_prime = np.zeros(2)
    p_d_prime2 = np.zeros(2)

    p_d = p0 + R*np.array([math.sin(s)**3, 3*math.sin(s)**2 * math.cos(s)])
    p_d_prime2 = np.array([3*math.sin(s)**2 * math.cos(s), 6*math.sin(s)*math.cos(s) - 3*math.sin(s)**3])

    return p_d, p_d_prime, p_d_prime2

def decoupled_ellipsoidal_path(s, p0, rx, ry):
    p_d = np.zeros(2)
    p_d_prime = np.zeros(2)
    p_d_prime2 = np.zeros(2)
    p_d_prime3 = np.zeros(2)

    p_d = p0 + np.array([rx*math.cos(2*math.pi*s), ry*math.sin(2*math.pi*s)])
    p_d_prime = np.array([-2*math.pi*rx*math.sin(2*math.pi*s), 2*math.pi*ry*math.cos(2*math.pi*s)])
    p_d_prime2 = np.array([-4*math.pi**2*rx*math.cos(2*math.pi*s), -4*math.pi**2*ry*math.sin(2*math.pi*s)])
    p_d_prime3 = np.array([8*math.pi**3*rx*math.sin(2*math.pi*s), -8*math.pi**3*ry*math.cos(2*math.pi*s)])
    return p_d, p_d_prime, p_d_prime2, p_d_prime3
    
def heading_signals(p_d, p_d_prime, p_d_prime2, p_d_prime3):
    # Heading with respect to s
    psi_t = math.atan2(p_d_prime[1], p_d_prime[0])
    psi_t_prime = (p_d_prime[0]*p_d_prime2[1] - p_d_prime2[0]*p_d_prime[1])/(p_d_prime[0]**2 + p_d_prime[1]**2)
    psi_t_prime2 = (p_d_prime[0]*p_d_prime3[1] - p_d_prime3[0]*p_d_prime[1])/(p_d_prime[0]**2 + p_d_prime[1]**2) - 2*((p_d_prime[0]*p_d_prime2[1] - p_d_prime2[0]*p_d_prime[1])*(p_d_prime[0]*p_d_prime2[0] - p_d_prime[1]*p_d_prime2[1])/((p_d_prime[0]**2 + p_d_prime[1]**2)**2))
    return psi_t, psi_t_prime, psi_t_prime2
    
def utg_update_law(U_ref, p, p_d, p_d_prime, p_d_prime2, mu):
    eps = 0.0001
    rho1 =-np.transpose(p_d_prime)@(p - p_d) 
    vs = U_ref/(np.linalg.norm(p_d_prime) + eps)
    vss = - ((np.transpose(p_d_prime)@p_d_prime2)/(np.linalg.norm(p_d_prime)**3 + eps)) *U_ref
    w = - (mu/(np.linalg.norm(p_d_prime) + eps))*rho1
    s_dot = vs + w

    return s_dot, w, vs, vss

def fg_update_law(U_ref, p, p_d, p_d_prime, p_d_prime2, mu, lambd, w):
    rho1 =-np.transpose(p_d_prime)@(p - p_d) 
    vs = U_ref/np.linalg.norm(p_d_prime)
    vss = - ((np.transpose(p_d_prime)@p_d_prime2)/(np.linalg.norm(p_d_prime)**3)) *U_ref
    s_dot = vs + w
    w_dot = -lambd*(w + mu*rho1)
    return s_dot, w, w_dot, vs, vss

### End of custom code ###


def loop():
    # Parameters
    dt = 0.01
    p1 = np.array([10, 0]) # We want the ship to follow a straight line for x meters
    rx = 5
    ry = 5
    v_st = 0
    K1, K2, KI, mu, U_ref = ctrl_gains.get_data()

    p0 = np.take(observer.get_observer_data(), [0,1])
    s, s_dot = s_p.get_s()

    # Compute the desired position and heading
    #p_d, p_d_prime, p_d_prime2, p_d_prime3 = decoupled_straight_line_path(s, p0, p1)
    p_d, p_d_prime, p_d_prime2, p_d_prime3 = decoupled_ellipsoidal_path(s, np.array([0,0]), rx, ry)
    psi_t, psi_t_prime, psi_t_prime2 = heading_signals(p_d, p_d_prime, p_d_prime2, p_d_prime3)

    # Update law and speed assignment

    s_dot, w, v_s, v_ss = utg_update_law(U_ref, p0[:, np.newaxis], p_d[:, np.newaxis], p_d_prime[:, np.newaxis], p_d_prime2[:, np.newaxis], mu)

    # Generate desired heading
    psi_d = psi_t
    psi_d_dot = psi_t_prime*s_dot[0]
    psi_d_ddot = psi_t_prime2*s_dot[0]**2 

    eta_d = np.array([p_d[0], p_d[1], psi_d])
    eta_d_prime = np.array([p_d_prime[0], p_d_prime[1], psi_d_dot])
    eta_d_prime2 = np.array([p_d_prime2[0], p_d_prime2[1], psi_d_ddot])
    
    new_s = s + dt*s_dot

    # Publish the computed signals
    s_p.publish(new_s, s_dot)
    reference.publish(eta_d, eta_d_prime, eta_d_prime2, w, v_s, v_ss)
    

    """
    Handle all calls to self written functions and publishers in this function. It is called by the 
    script that creates the ROS node and will loop
    """
    
