import numpy as np
import math
from math_tools import Rzyx, wrap2pi


def regulator(eta_hat, nu_hat, eta_d, nu_d, nu_d_dot, mu, Uref, Kp, Kd):    
    global s
    M = np.array([[16.11, 0.0, 0.0], [0.0, 24.11, 0.5291], [0.0, 0.5291, 2.7600]])
    D = np.array([[0.66, 0., 0.], [0., 1.3, 2.8], [0., 0., 1.9]])
    Kp = np.diag(Kp)
    Kd = np.diag(Kd)
    psi = eta_hat[2][0]
    r = nu_hat[2][0]
    eta_hat[2] = wrap2pi(psi)
    R = Rzyx(psi)
    S_dot = np.array([[0, -r, 0],[r, 0, 0],[0, 0, 0]])
    S = np.array([[0, -psi, 0],[psi, 0, 0],[0, 0, 0]])
    eps = 0.00001

    # Error 
    z1 = R.T @ (eta_d - eta_hat)
    z1[2] = wrap2pi(z1[2])
    
    V1_prime = ((-z1.T @ R.T)@nu_d) [0][0]

    # Speed assignment
    Us = np.abs(Uref)/math.sqrt(nu_d[0][0]**2 + nu_d[0][0]**2 + eps)
    Us_prime = Uref*(-nu_d[0][0]*nu_d_dot[0][0]+nu_d[1][0]*nu_d_dot[1][0])/math.sqrt((nu_d[0][0]**2 + nu_d[1][0]**2 + 0.00001)**3)

    s_dot = Us - (mu/np.linalg.norm(nu_d))*V1_prime
    z1_dot = (S_dot.T @ z1) + (R.T @ nu_d) + (nu_hat - R.T@nu_d*s_dot)
    d_dt = (S_dot.T @ R.T @ nu_d)*Us + (R.T*s_dot) @ (nu_d_dot*Us + nu_d*Us_prime)

    alpha1 = (-Kp @ z1) + (R.T @ nu_d)*Us

    z2 = nu_hat - alpha1

    alpha1_dot = (-Kp@z1_dot) + d_dt

    tau = -z1 - (Kd@z2) + (D@nu_hat) + (M@alpha1_dot)
    s = s + 0.01*s_dot
     
    return tau

def guidance_system():
    """
    guidance_system generates reference values for an ellipsoidal path
    """
    rx = 1.5
    ry = 1.5 
    psi_s = 0
    eta_d = np.zeros(3)
    nu_d = np.zeros(3)
    nu_d_dot = np.zeros(3)
    eps = 0.0001
    global s

    offset = np.array([2, 0])

    # Reference eta 
    eta_d[0] = offset[0] + rx*math.cos(2*math.pi*s+psi_s)
    eta_d[1] = offset[1] + ry*math.sin(2*math.pi*s+psi_s)
    eta_d[2] = math.atan2((ry*math.cos(psi_s + 2*math.pi*s)), -(rx*math.sin(psi_s + 2*math.pi*s + eps)))

    # Reference nu
    nu_d[0] = -2*math.pi*rx*math.sin(2*math.pi*s + psi_s)
    nu_d[1] = 2*math.pi*ry*math.cos(2*math.pi*s+psi_s)
    nu_d[2] = (2*rx*ry*math.pi)/(ry**2 + rx**2*math.sin(2*math.pi*s + psi_s)**2 - ry**2*math.cos(2*math.pi*s + psi_s)**2 + eps)

    # Reference eta
    nu_d_dot[0] = -4*math.pi**2*rx*math.cos(2*math.pi*s + psi_s)
    nu_d_dot[1] = -4*math.pi**2*ry*math.sin(2*math.pi*s + psi_s)
    nu_d_dot[2] = -(8*rx*ry*math.pi**2*math.cos(2*math.pi*s + psi_s)*math.sin(2*math.pi*s + psi_s)*(rx**2 + ry**2)*math.cos(2*math.pi*s + psi_s)**2 + math.sin(2*math.pi*s + psi_s)**2)/(ry**2*math.cos(2*math.pi*s + psi_s)**2 + rx**2*math.sin(2*math.pi*s + psi_s)**2 + eps)

    return eta_d, nu_d, nu_d_dot


eta_hat = np.zeros(3)[np.newaxis].T
nu_hat = np.zeros(3)[np.newaxis].T
mu = 0.01
Uref = 0.01
Kp = 0.0001*np.diag(np.array([1, 1, 1]))
Kd = np.diag(np.array([0.001, 0.001, 0.001]))
s = 0
eta_d, nu_d, nu_d_dot = guidance_system()
eta_d = eta_d[np.newaxis].T
nu_d = nu_d[np.newaxis].T
nu_d_dot = nu_d_dot[np.newaxis].T
tau = regulator(eta_hat, nu_hat, eta_d, nu_d, nu_d_dot, mu, Uref, Kp, Kd)
print(eta_d)
print(tau)