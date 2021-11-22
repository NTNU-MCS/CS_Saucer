import rospy
import numpy as np
import math
from lib import qualisys, tau, observer, gains, u_data
from math_tools import Rzyx, rad2pipi


### Write your code here ###
def extended_thrust_allocation(tau)
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

    return u
### End of student code ###

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
    B = np.array([[0, np.sin(2*np.pi/3), np.sin(4*np.pi/3)]
                  [1, np.cos(2*np.pi/3), np.cos(4*np.pi/3)]
                  [r, r, r]])
    u = np.inv(B)@tau             
    return u

def saturation(tau):
"""---------------------------------------------------------------------------- 
# name: saturation                                                            #  
# input: tau                                                                  #
# outputs: sat_tau                                                            #
#                                                                             #
# Saturates the thruster forces acting on the                                 #
# vessel body evenly.                                                         #
#                                                                             #
#                                                                             #
# authour: Mathias N. Solheim                                                 #
# date: 11.09.2021                                                            #
----------------------------------------------------------------------------"""
    F_max = 1                                   # [N]
    T_max = 0.3                                 # [Nm]
    ck = F_max/math.sqrt(tau[0]**2 + tau[1]**2) # [-]

    #Initialize output-array
    tau_sat = np.array([[0],[0],[0]])     

    # Saturate surge and sway
    if ck < 1:
         tau_sat[0][0] = ck*tau[0]
         tau_sat[1][0] = ck*tau[1]
    else 
         tau_sat[0][0] = tau[0]
         tau_sat[1][0] = tau[1]
    
    # Saturate yaw
    if  np.abs(tau[2]) >= T_max
        sat_tau[2] = np.sign(tau[2])*T_max
    else 
        sat_tau[2] = tau[2]
    
    return sat_tau


def loop():
    """
    All calls to functions and methods should be handled inside here. loop() is called by the main-function in obs_node.py
    """
    # Get parameters

    tau = get_tau()
    tau = saturation(tau)

    # compute the thrust allocation 
    u = fixed_thrust_allocation(tau)
    u_data.publish(u)
    return 0
