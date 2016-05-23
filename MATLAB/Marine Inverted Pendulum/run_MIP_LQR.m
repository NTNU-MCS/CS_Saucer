% ********************************************************************
% This script initializes parameters needed to run LQR control. This is a
% version where the coupled equations are considered, but not the
% hydrodynamics.
% ********************************************************************
%
% ***********************************
% Author: Rotem Sharoni
% Last updated: 9th of May 2016
% ***********************************
%


g   = 9.81;   % gravitational accleration

%Vessel constants:
r = 0.548/2;  %Radius of te CS Saucer
h = 0.129;    %Total height of the CS Saucer
m_0 = 7.0;   % [kg],   vessel mass, including pendulum support
I_0 = (1/12)*m_0*(3*r^2+h^2); %Mass moment of inertia about y_b axis (solid cylinder)
l_0 = 0.25;    % [m],      joint distance from center of pitch 

%Pendulum:
m_1 = 0.4;   % [kg],     pendulum mass
l_1 = 1.6;     % [m],      pendulum length 
I_1 = (m_1*(l_1)^2)/3; %Pendulum inertia

%Linearization around zero:
theta_0  = 0;   theta_1  = 0;
theta_0d = 0; theta_1d = 0;

%MIP matrices:
D0 = [m_0+m_1              m_1*l_0*cos(theta_0)             m_1*l_1*cos(theta_1)
     m_1*l_0*cos(theta_0) I_0+m_1*l_0^2                    m_1*l_0*l_1*cos(theta_0-theta_1)
     m_1*l_1*cos(theta_1) m_1*l_0*l_1*cos(theta_0-theta_1) m_1*l_1^2+I_1                   ];                                     
dG0 = [0        0        0;
      0     -m_1*g*l_0    0;
      0        0     -m_1*g*l_1];
H = [1 l_0 0]';

%Linear state space system:
A = [zeros(3) eye(3);
    -D0\dG0 zeros(3)];
B = [zeros(3,1);D0\H];
Q = diag([1 1 800 1 1 100]); %Weight for the states, LQR
R = 100; %Weight for the input, LQR
[K_lqr,P,e] = lqr(A,B,Q,R,0);
K_lqr = K_lqr/4
ref = zeros(6,1); %Desired state, x, theta_0, theta_1, + derivatives

%Thrust allocation:
rt = 0.135; % Radius from CG to motor axis in m
Tr = [1 1 -1;
    0 0 0;
    0 rt rt]; %Thrust allocation matrix
pinvTr = pinv(Tr); % Pseudoinverse

%Heading controller gains:
Kp = 0.1;
Kd = 0.12;

