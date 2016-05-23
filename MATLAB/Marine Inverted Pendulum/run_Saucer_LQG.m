% ********************************************************************
% This script initializes parameters needed to run LQR control. This is a
% version where the coupled equations are considered, but not the
% hydrodynamics.
% ********************************************************************
%
% ***********************************
% Author: Rotem Sharoni
% Last updated: 11th of May 2016
% ***********************************
%


%Thrust mapping:
load MAPPERMAT
MEAN1POS=MEAN1POS(1:end-1);
MEAN3Pos=MEAN3Pos(1:end-5);

TH1NEG=(TH1NEG(1:end-1));
TH3Pos=TH3Pos(1:end-5);
MEAN1NEG(MEAN1NEG>0)=0;
MEAN1POS(MEAN1POS<0)=0;
MEAN1POS(1)=1e-2;



Th1=[fliplr(TH1NEG) TH1POS];
MAPP1=[fliplr(MEAN1NEG) MEAN1POS];
MAPP1=[fliplr(-MEAN1POS) MEAN1POS];
%MAPP1(length(MEAN1POS))=MAPP1(length(MEAN1POS))+1e-3
LowerCut=min(find(MAPP1==0));
UpperCut=max(find(MAPP1==0));
Th1=[Th1(1:LowerCut-1) Th1(UpperCut+1:end)];
MAPP1=[MAPP1(1:LowerCut-1) MAPP1(UpperCut+1:end)];


MEAN2Neg(MEAN2Neg>0)=0;
MEAN2Pos(MEAN2Pos<0)=0;


MEAN3Neg(MEAN3Neg<0)=0;
MEAN3Pos(MEAN3Pos>0)=0;

Th3=[fliplr(TH3Neg) TH3Pos];
MAPP3=[fliplr(MEAN3Neg) MEAN3Pos];
MAPP3=[fliplr(-MEAN3Pos) MEAN3Pos];
LowerCut=min(find(MAPP3==0));
UpperCut=max(find(MAPP3==0));
Th3=[Th3(1:LowerCut-1) Th3(UpperCut+1:end)];
MAPP3=[MAPP3(1:LowerCut-1) MAPP3(UpperCut+1:end)];




Th2=[fliplr(TH2Neg) TH2Pos];
MAPP2=[fliplr(MEAN2Neg) MEAN2Pos];
MAPP2=[fliplr(-MEAN2Pos) MEAN2Pos];
LowerCut=min(find(MAPP2==0));
UpperCut=max(find(MAPP2==0));
Th2=[Th2(1:LowerCut-1) Th2(UpperCut+1:end)];
MAPP2=[MAPP2(1:LowerCut-1) MAPP2(UpperCut+1:end)];



interp1(MAPP1,Th1,-0.3);
interp1(MAPP2,Th2,-0.3);
interp1(MAPP3,Th3,-0.3);


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
n = 6; %States in the system
A = [zeros(3) eye(3);
    -D0\dG0 zeros(3)];
B = [zeros(3,1);D0\H];
C = [eye(3) zeros(3)]; %Measuring all positions

%Controller:
Q = diag([1 1 800 1 1 100]); %Weight for the states, LQR
R = 100; %Weight for the input, LQR
[K_lqr,P,e] = lqr(A,B,Q,R,0);
K_lqr
ref = zeros(6,1); %Desired state, x, theta_0, theta_1, + derivatives

%Observer
eigenvalues = eig(A-B*K_lqr); %Eigenvalues of the closed loop system
radius = 5*real(max(eigenvalues)); %The observer have to be faster
angles = [5*pi/180 15*pi/180 25*pi/180]; %Larger angle --> Larger 
%overshoot and faster response
im = sqrt(-1); %The imaginary number
poles = zeros; %Initialize the poles

%Placing the observer poles on a half circle in the left plane
for i = 1:(n/2)
   poles(i*2) = radius*cos(angles(i)) + (radius*sin(angles(i)))*im;
   poles(i*2-1) = conj(poles(i*2));
end
poles = poles';
L_obs = place(A',C',poles); %Design the observer gain
L_obs = L_obs';


%Thrust allocation:
rt = 0.135; % Radius from CG to motor axis in m
Tr = [1 1 -1;
    0 0 0;
    0 rt rt]; %Thrust allocation matrix
pinvTr = pinv(Tr); % Pseudoinverse

%Heading controller gains:
Kp = 0.1;
Kd = 0.12;

