% ********************************************************************
% This script initializes parameters and runs the 4 DOF model of the CS
% Saucer
% ********************************************************************
%
% ***********************************
% Author: Rotem Sharoni
% Last updated: 12th of April 2016
% ***********************************
%

nu_init = zeros(4,1); %Initial velocity
eta_init =zeros(4,1); %Initial position and orientation

tsim = 10; %Simulation time, s
sim Saucer_4dof

%Plot the results:
set(groot, 'defaultAxesTickLabelInterpreter','latex'); 
set(groot, 'defaultLegendInterpreter','latex');

figure
plot(tau)
title('Forces (tau, in {b})')
legend('X','Y','M','N')

figure
subplot(2,1,1)
plot(eta.time,eta.data(:,1))
hold on
plot(nu.time,nu.data(:,1))
title('System output')
xlabel('Time (s)')
legend('x [m]','$\dot{x}$ [m/s]')
subplot(2,1,2)
plot(eta.time,rad2deg(eta.data(:,3)),'k')
hold on
plot(nu.time,rad2deg(nu.data(:,3)),'color','[0,0.5,0]')
xlabel('Time (s)')
legend('$\theta$ [deg]','$\dot{\theta}$ [deg/s]')

% figure
% plot(F3)
% hold on
% plot(F3_sat)
% ylim([-5 5])
% legend('Step input','Saturated Output')
% title('Thruster 3')