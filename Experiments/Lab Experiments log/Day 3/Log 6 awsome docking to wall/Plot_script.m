%% load
% aaa
close all

Setpoint = load('Log_eta_desired.mat');
Setpoint = Setpoint.ans.Data;
eta = load('Log_eta.mat');
eta = eta.ans.Data;
eta_d = Setpoint(:,3)-eta(:,3);
l = min([length(Setpoint),length(eta)]);

%% -inf inf to -pi pi
d1 = 0;
d2 = 0;
for i = 2:l
%     eta(i,3) = rem(eta(i,3)+sign(eta(i,3))*pi,2*pi) -sign(eta(i,3))*pi;
%     eta_d(i) = rem(eta_d(i)+sign(eta_d(i))*pi,2*pi) -sign(eta_d(i))*pi;
    if abs(eta(i-1,3)-eta(i,3))>300*pi/180
       %d1 = d1 + (-1)*sign(eta(i-1,3)-eta(i,3))*2*pi;
       eta(i:end,3) = eta(i:end,3)+ sign(eta(i-1,3)-eta(i,3))*2*pi;
    end
    if abs(Setpoint(i-1,3)-Setpoint(i,3))>300*pi/180
        %d2 = d2 + (-1)*sign(Setpoint(i-1,3)-Setpoint(i,3))*2*pi;
        Setpoint(i:end,3) = Setpoint(i:end,3)+ sign(Setpoint(i-1,3)-Setpoint(i,3))*2*pi;
    end
    %eta(i,3) = eta(i,3) + d1;
    %Setpoint(i,3) = Setpoint(i,3) + d2;
end
%%
Setpoint(309:end,3) = Setpoint(309:end,3) + 2*pi;
Setpoint_eta = [eta(1:l,:),Setpoint(1:l,:)];

xmin = 0;
%xmax = length(Setpoint(:,1));
%xmin = 1620;
xmax = 1000;


%% Plot
pi1 = -pi*ones(xmax-xmin,1);
pi2 =  pi*ones(xmax-xmin,1);
figure(1)
plot(Setpoint_eta(:,1))
hold on
plot(Setpoint_eta(:,2))
%plot(Setpoint_eta(:,3))
plot(Setpoint_eta(:,4))
plot(Setpoint_eta(:,5))
%plot(Setpoint_eta(:,6))
%plot(eta_d)
%plot(pi1)
%plot(pi2)
%legend('X','Y','\psi','X_s_e_t','Y_s_e_t','\psi_s_e_t','\psi_d')
legend('X','Y','X_s_e_t','Y_s_e_t')
%title('Heading and Setpoint')
xlim([xmin xmax])
grid on

figure(2)
plot(Setpoint_eta(:,3)*180/pi)
hold on
plot(Setpoint_eta(:,6)*180/pi)
%plot(eta_d*180/pi)
%plot(pi1*180/pi)
%plot(pi2*180/pi)
%legend('\psi','\psi_s_e_t','\psi_d','-180','180')
legend('\psi','\psi_s_e_t')
%title('Heading')
xlim([xmin xmax])
ylabel('Degrees')
grid on

figure(3)
plot(Setpoint_eta(xmin+1:xmax,1),Setpoint_eta(xmin+1:xmax,2))
hold on
plot(Setpoint_eta(xmin+1:xmax,4),Setpoint_eta(xmin+1:xmax,5))
legend('X     vs Y','X_s_e_t vs Y_s_e_t')
title('Postition')
grid on

