% ********************************************************************
% This script initializes parameters needed to run LQR control. This
% is a simple LQR for the inverted pendulum without any pitch coupling. The
% system also has a heading controller for the vessel.
% ********************************************************************
%
% ***********************************
% Author: Rotem Sharoni
% Last updated: 21th of April 2016
% ***********************************
%

Nu_init=[0 0 0]; %initial velocities
InitialPos=[0 ;0 ;0]; %initial position
NoiseGain=0.1; %Noise gain on positions
ReferenceModel=1; %Lowpass filter on reference 

%Thrust allocation:
rt = 0.135; % Radius from CG to motor axis in m
Tr = [1 1 -1;
    0 0 0;
    0 rt rt]; %Thrust allocation matrix
pinvTr = pinv(Tr); % Pseudoinverse

%Heading controller gains:
Kp = 0.1;
Kd = 0.12;

% Hydrodynamic Constants
m=6.34;
Xudot=-3.5;
Yvdot=-3.5;
Nr=0;
Xu=-1.9599;
Xuu=-7.0948;
Yv=-1.9599;
Yvv=-7.0948;
Iz=0.116;
%%%%%%%%%%%

%%%Creating matrices for hydrodynamic equations.
M=[1.5*m 0 0;0 1.5*m 0;0 0 (Iz)]; 
invM=inv(M);
D=[-Xu 0 0;0 -Yv 0;0 0 0.1*-Xu];
%Parameters for nonlinear damping and corealis
D_nuParams=[-Xuu 0 0;0 -Yvv 0;0 0 -0.1*Xuu];
C_nuParams=[0 -1.5*m 0;1.5*m 0 -0;0 0 0];
pathMatrix=[[1;1;0.2] -[1;1;0.2]];

%Setting gains for Nonlinear Passive Observer
K2=0.250 *diag([1 1 1]);
K3=0.1*diag([2 2 2]);
K4=5*diag([1 1 0.1]);
T=1*diag([0.1 0.1 0.1]);
invT=inv(T);

%Pendulum constants:
m_p = 0.24; %mass in kg
l_1 = 1.5; %Lenght of pendulum in m
k = 0.05; %Some restoring
b = 0.05; %Some damping
g = 9.81; %Gravitational constant

%LQR for the pendulum:
ref = zeros(4,1); %Desired state, x, theta_1, x_d, theta_1d
Q = diag([1 1100 1 50]); %Cost for the states
R = 100; %Cost of the control input
A = [0 0 1 0;
    0 0 0 1;
    -k -(m_p*g)/m -b 0;
    k ((m+m_p)*g)/(m*l_1) -b 0]; %State matrix
B = [0 0 1/m -1/(m*l_1)]'; %Input Matrix
[K_lqr,P,e] = lqr(A,B,Q,R,0); %Find the lqr gain
K_lqr = K_lqr/10;