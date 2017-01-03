function [sys,ThrusterPos,str,ts] = Spange_thrustallocationQuadratic_mode3(t,x,u,flag,u_e,Thruster,C) 
% Function for finding optimal thrust and angle
% Author: Preben Frederich
% 12/12-2015

% Version 1.0 : Pseudo inverse optimalization created
%               12/12-2015 Preben Frederich
% Version 1.1 : Desired angle implemented
%               02/03-2016 Preben Frederich
% Version 1.2 : Individual & coupled constrained thrust allocation implemented
%               07/04-2016 Preben Frederih
% Version 1.3 : Quadratic control allocation implemented with optimal
%               angles found by pseudoinverse allocation
%               15/04-2016 Preben Frederich
% Version 1.4 : Quadratic control allocation modified to optimize around
%               the different thrusters when they are in forbidden zones
%               20/04-2016 Preben Frederich
% Version 1.5 : Implemented constraints at forbidden zones varying depending 
%               on length between each thruster. Retrived from Initfile as [C].
%               22/04-2016 Preben Frederich
% Version 1.6 : Implemented possibilities for using real model values for
%               the quadratic regulator
%               25/04-2016 Preben Frederich
% Version 1.7 : Initial conditions for Quadratic regulator is updated with
%               the optimal solution from last time step. Makes the next
%               timestep solution run much faster
%               03/05-2016 Preben Frederich
% Version 1.8 : Cleanup and minor changes in name definitions to coincide
%               with ROV Control Modes by Skjetne 2015. Explanation of the 
%               different parts of system updated. 
%               04/07-2016 Preben Frederich

switch flag,

  % Initialization
  case 0,
    [sys,ThrusterPos,str,ts]=mdlInitializeSizes(Thruster);

  % Output
  case 3,
    sys=mdlOutputs(t,x,u);

  % Update  
  case 2,
    sys=mdlUpdate(t,x,u,u_e,C); 
    
  case {1,4,}
    sys=[];

  % Case 9 used for terminate signal if errors where to occure.
  case 9,
      sys=mdlTerminate(t,x,u);

  % Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);

end

function [sys,x0,str,ts]=mdlInitializeSizes(Thruster)
% Only used when starting the system

% Maps out the different states
sizes = simsizes;  
sizes.NumContStates  = 0;   % Number of continuous states in the system, 
sizes.NumDiscStates  = 4;   % Number of discrete states in the system 
sizes.NumOutputs     = 4;   % Number of outputs (Output of each angle of each thruster and desired thrust of each thruster)
sizes.NumInputs      = 7;  % Number of inputs (Input: Desired angle and Desired thrust vector)
sizes.DirFeedthrough = 0;   % No element which is sent directly through the system
sizes.NumSampleTimes = 1;   % Number of sample times each itteration
sys = simsizes(sizes); 


%% Determines initial angles on thrusters + initial thrust at start.
x0 = [Thruster.T1(3) Thruster.T2(3) 0 0]';

str = [];  

ts  = [-1 0];


function sys=mdlUpdate(t,x,u,u_e,C)
%% Input definitions used through the system
% ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1)];%[x(1),x(2),x(3)]';
% ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2)];%[x(4),x(5),x(6))]';

tc =  [u(1),u(2),u(3)]'; 
alpha = [u(4),u(5)]';


%% Thrust allocation algorithm

[n_t, ~] = size(C); % number of thrusters

% Constraints for Thruster-Thruster interaction. Can be seen in "Initfile"
C1 = C(1,:);    % Angle constraints Thruster 1
C2 = C(2,:);    % Angle constraints Thruster 2

K = ones(1,4); % Resets K For each time iteration

% Thruster 1 on/off
if abs(alpha(1)) > C1
    K(1) = 0;         %x-component 0
    K(2) = 0;         %y-component 0
end
% Thruster 2 on/off
if abs(alpha(2)) > C2
    K(3) = 0;
    K(4) = 0;
end

%% Finding Optimal angle and tau through quadratic optimization

W = eye(4);
Q = diag([100 1000 10000]);  %s'Qs penelises error between commanded and achived generalized force.
zero2H = zeros(4,3);
H = [W zero2H; zero2H' Q];
f = zeros(7,1);
%Aeq = [u_e -eye(3)];
Aeq = [u_e*diag(K) -eye(3)];
Beq = tc; 
ub =  [1.5 1.5 1.5 1.5 0.01 0.01 0.01]'; %[Max_thrust max_slack]
lb = -[1.2 1.2 1.2 1.2 0.01 0.01 0.01]';
X0 = [u(6),u(7)]';
options = optimoptions('quadprog',...
    'Algorithm','interior-point-convex','Display','off');
X = quadprog(H,f,[],[],Aeq,Beq,lb,ub,X0,options);       %MSS - See Fossen 12.3.4

% If no solution exist:
if numel(X) <= 3 
    X = [0 0 0 0 0 0 0];
    disp('No Solution')
end

u_d = [sqrt(X(1)^2+X(2)^2) sqrt(X(3)^2+X(4)^2)] ;      % Optimized Thrust
alpha1 = [atan2d(X(2),X(1)) atan2d(X(4),X(3))];
% Ensuring the angles are between [-180 180] degrees
for i=1:1:n_t
    if alpha1(i) > 180
      alpha1(i) = alpha1(i) - 360;
    elseif alpha1(i) < -180
      alpha1(i) = alpha1(i) + 360;
    end
end

Desired_Alpha = [alpha1(1),alpha1(2)]';
Desired_thrust = [u_d(1) u_d(2)]';

%% Update outputs
sys = [Desired_Alpha',Desired_thrust'];

function sys=mdlOutputs(t,x,u)
% Giving the desired angle output [ 1 2 3] together with desired
% thrust [4 5 6]
sys=[x(1),x(2),x(3),x(4)];

function sys=mdlTerminate(t,x,u) 
% If error within the algorithm, system terminates
sys = [];