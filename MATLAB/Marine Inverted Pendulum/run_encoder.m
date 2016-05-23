%*************************************************************************
% This script plots the results from encoder.slx. This is the encoder
% values convertet to angular position in degrees.
%*************************************************************************
%
%*************************************
% Author: Rotem Sharoni
% Last updatet: 19th of April 2016
%*************************************


%Plot the results:
set(groot, 'defaultAxesTickLabelInterpreter','latex'); 
set(groot, 'defaultLegendInterpreter','latex');

figure
subplot(2,1,1)
plot(EncDegTrue.time,EncDegTrue.data)
grid on
grid minor
ax.YTick = [-60:10:60];
title('Encoder angle (true)')
xlabel('Time [s]')
ylabel('Angle [deg]')
subplot(2,1,2)
plot(EncDegNorm.time,EncDegNorm.data)
grid on
grid minor
ax.YTick = [-60:10:60];
title('Encoder angle (normalized)')
xlabel('Time [s]')
ylabel('Angle [deg]')

figure
plot(EncVal.time,EncVal.data)
title('Encoder value')
xlabel('Time [s]')
ylabel('Value')