%%
load MAPPERMAT
MEAN1POS=MEAN1POS(1:end-1);
MEAN3Pos=MEAN3Pos(1:end-5);

TH1NEG=(TH1NEG(1:end-1));
TH3Pos=TH3Pos(1:end-5);
MEAN1NEG(MEAN1NEG>0)=0;
MEAN1POS(MEAN1POS<0)=0;
MEAN1POS(1)=1e-2;



Th1=[fliplr(TH1NEG) TH1POS];
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
MAPP3=[fliplr(-MEAN3Pos) MEAN3Pos];
LowerCut=min(find(MAPP3==0));
UpperCut=max(find(MAPP3==0));
Th3=[Th3(1:LowerCut-1) Th3(UpperCut+1:end)];
MAPP3=[MAPP3(1:LowerCut-1) MAPP3(UpperCut+1:end)];




Th2=[fliplr(TH2Neg) TH2Pos];
MAPP2=[fliplr(-MEAN2Pos) MEAN2Pos];
LowerCut=min(find(MAPP2==0));
UpperCut=max(find(MAPP2==0));
Th2=[Th2(1:LowerCut-1) Th2(UpperCut+1:end)];
MAPP2=[MAPP2(1:LowerCut-1) MAPP2(UpperCut+1:end)];



Nu_init=[0 0 0]; %initial velocities
InitialPos=[0 ;0 ;0]; %initial Position
NoiseGain=0.1; %Noise gain on Positions
ReferenceModel=1; %Lowpass filter on reference 

%%

%% Thrust allocation matix and inverse Thrust allocation
rt=0.13735;
Tr=[0 sin(2*pi/3) -sin(4*pi/3);-1 -cos(2*pi/3) cos(4*pi/3);-rt -rt rt];
Tr2=[0 sin(2*pi/3) -sin(4*pi/3);1 -cos(2*pi/3) cos(4*pi/3);rt -rt rt];
Tr=[0 sin(2*pi/3) -sin(4*pi/3);1 cos(2*pi/3) -cos(4*pi/3);rt rt -rt];


Tr=[0 sin(2*pi/3) sin(4*pi/3);1 cos(2*pi/3) cos(4*pi/3);rt rt rt];



invThrustAloc=inv(Tr);


% Hydrodynamic Constants
% m=6.34;
% Xudot=-3.5;
% Yvdot=-3.5;
% Nr=0;
% Xu=-1.9599;
% Xuu=-7.0948;
% Yv=-1.9599;
% Yvv=-7.0948;
% Iz=0.116;
%%%%%%%%%%%

%% Hydrodynamic Constants Spange invention
addonm = 3;
m=6.34+addonm;
Xudot=-3.5;
Yvdot=-3.5;
Nr=-1;
Xu=-1.9599;
Xuu=-7.0948;
Yv=-4;
Yvv=-14;
Iz=0.3;

%%%Creating matrices for hydrodynamic equations.
M=[1.5*m 0 0;0 2.5*m 0;0 0 (Iz)];
invM=inv(M);
D=[-Xu 0 0;0 -Yv 0;0 0 0.7*-Xu];
%Parameters for nonlinear damping and corealis
D_nuParams=[-Xuu 0 0;0 -Yvv 0;0 0 -0.7*Xuu];
C_nuParams=[0 -1.5*m 0;1.5*m 0 -0;0 0 0];
pathMatrix=[[1;1;0.2] -[1;1;0.2]];
%%



% %%%Creating matrices for hydrodynamic equations.
% M=[1.5*m 0 0;0 1.5*m 0;0 0 (Iz)];
% invM=inv(M);
% D=[-Xu 0 0;0 -Yv 0;0 0 0.1*-Xu];
% %Parameters for nonlinear damping and corealis
% D_nuParams=[-Xuu 0 0;0 -Yvv 0;0 0 -0.1*Xuu];
% C_nuParams=[0 -1.5*m 0;1.5*m 0 -0;0 0 0];
% pathMatrix=[[1;1;0.2] -[1;1;0.2]];

%Setting gains for Nonlinear Passive Observer
K2=0.250 *diag([1 1 1]);
K3=0.1*diag([2 2 2]);
K4=5*diag([1 1 0.1]);
T=1*diag([0.1 0.1 0.1]);
invT=inv(T);

%Setting gains for PID controller
Kp=1.5*diag([1,1,1]);
Kd=4*diag([1,1,1]);
Ki=0.1*diag([1,1,1]);


wni=diag([0.8 0.8 1.1]).^0.5; %idland had this as squared as well
wnisquared=wni.^2;
Ceta=0.8;
Sat2Up=2*[0.28 0.28 0.56];
Sat2Low=2*[-0.28 -0.28 -0.56];
Sat1Up=20*[0.13 0.13 0.26];
Sat1Low=20*[-0.13 -0.13 -0.26];
wniCeta2=Ceta*2*wni;
