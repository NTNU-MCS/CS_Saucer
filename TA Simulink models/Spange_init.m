%% Startup file for Spange_Thrust_simulation
clc
clear all
addpath(genpath('D:\NTNU\5. år Marin\11. semester - MASTER\Code\MATLAB\RealTime_Pacer\RealTime_Pacer'));
%% Modifiable controls:
td = [1;0;0];         % Control thrust into thrust allocation
Thruster_control = 1;   % Chooses Controller: 1 = Speed , 2 = Torque , 3 = Power , 4 = Power & torque
mode = 4;               % Turust allocation mode 1 - 4 4: highest actuated, 1: very underactuated
%% Parameters

%Thruster coefficients. Found from Bollard pull

K_T1f = 0.3763;
K_T2f = 0.3901;
K_T3f = 0.3776;

K_T1r = K_T1f;
K_T2r = K_T2f;
K_T3r = K_T3f;

K_q1f = 0.0113;
K_q2f = 0.0117;
K_q3f = 0.0113;

K_q1r = K_q1f;
K_q2r = K_q2f;
K_q3r = K_q3f;

lambda = 90;        % Scaling parameter
eps = 1E-5;         % Constant for avoiding singularities

%% Model vessel parameters
Rho_m = 1000;     % Water density tank [Kg/m^3]
D = 3.0/100;      % Propeller diameter model vessel  [m] %TODO: measure
n_max = 64.6;     % Maximum propeller speed model [RPM]               
T_max = 1.5034;   % Max produced thrust [N]
I_s = 0.05;       % Moment of inertia [kg*m^2]
Rho = Rho_m;
Max_rotation = 12*sqrt(lambda); % Max rotation of thrusters [1/s]
Max_thrust = 1.5034;  % maximum force for each thruster
Min_thrust = -0.85; % maximum negative thrust for each thruster
Max_Acceleration = 2; % Max propeller accelleration [1/s^2]
Max_thrust_rate = 0.0285;

% Thruster.T1 = [ 96.1/90  0        180 2];    %[m,m,Deg,Deg/s]
% Thruster.T2 = [ 84.1/90  9.9/90  -135 2];    %[m,m,Deg,Deg/s] 
% Thruster.T3 = [ 84.1/90 -9.9/90   90  2];    %[m,m,Deg,Deg/s] 
% Thruster.T4 = [-104.8/90 0        0   2];    %[m,m,Deg,Deg/s] 
% Thruster.T5 = [-89.2/90 -14.9/90  45  2];    %[m,m,Deg,Deg/s] 
% Thruster.T6 = [-89.2/90  14.9/90 -90  2];    %[m,m,Deg,Deg/s] 

rt = 0.138;                                  %mounting radius of 
Thruster.T1 = [ rt*cosd(240)  rt*sind(240)        5 5];    %[m,m,Deg,Deg/s]
Thruster.T2 = [ rt*cosd(120)  rt*sind(120)        8 5];    %[m,m,Deg,Deg/s]
Thruster.T3 = [ rt*cosd(0)  rt*sind(0)        -90 0];    %[m,m,Deg,Deg/s]

% Extended thrust configurations (12.234)
ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1)];%[x(1),x(2),x(3)]';
ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2)];%[x(4),x(5),x(6))]';
switch mode,
    case 1,
        u_e = [1 0
            0 1
             0 ThrusterPosX(1)];                                                                %B3x2 (4.2.6) - thrust configuration TODO! Check signes!
    case 2,
        u_e = [1 0 0
            0 1 1
             0 ThrusterPosX(1) ThrusterPosX(3)];                                                %B3x3 (4.2.6) - thrust configuration TODO! Check signes!
    case 3,
        u_e = [1 0 1 0
            0 1 0 1
             ThrusterPosY(1) ThrusterPosX(1) ThrusterPosY(2) ThrusterPosX(2)];                %B3x4 (4.2.6) - thrust configuration TODO! Check signes!
    case 4
        u_e = [1 0 1 0 0
               0 1 0 1 1
               ThrusterPosY(1) ThrusterPosX(1) ThrusterPosY(2) ThrusterPosX(2) ThrusterPosX(3)]; %B3x5 (4.2.6) - thrust configuration TODO! Check signes!
    otherwise
        error(['Unhandled mode = ',num2str(mode)]);
end


% Thruster control
eps_c = 5;        % Constant for switching between positive and negative thrust
n_c = 5;          % Switching width between K_tc and K_tcr
omega_r0 = 0.90;  % Natural frequency [1/s] 
zeta_r = .78;     % Damping ratio [-]
H1 = tf(omega_r0^2,[1 2*zeta_r*omega_r0 omega_r0^2]);
hd = c2d(H1,0.1,'foh');

% Transfer function for Engine
H2 = tf(1,[0.02 1]);
hd2 = c2d(H2,0.01,'zoh');

Kp = 0.3;         % Core controller gain [-]
nd_slew = 0.5*90; % Max RPS rate [1/s^2]
K_omega = 0.3;    % Linear friction coefficient [-] 0.3
epsilon = 0.5;    % Constant for friction component
Q_f0 = 0.3;       % Friction constant

% Core thruster parameters for combined torque and power
k_cc = 1;
p_cc = 0.5;
r_cc = 4;

% Constraints for stern thruster
forbiddenzone = 45;
switch mode
    case 1,
        C = forbiddenzone*[1 0];
    case 2,
        C1 = forbiddenzone*[1 0];
        C3 = [89, 91];
        C = [C1;C3];            % All constraints for Thruster-Thruster Interaction       
    case 3,
        C1 = forbiddenzone*[1 0];
        C2 = forbiddenzone*[1 0];
        C = [C1;C2];            % All constraints for Thruster-Thruster Interaction
    case 4,
        C1 = forbiddenzone*[1 0];
        C2 = forbiddenzone*[1 0];
        C3 = [89, 91];
        C = [C1;C2;C3];         % All constraints for Thruster-Thruster Interaction
    otherwise,
        error('Wrong Mode!')
end


