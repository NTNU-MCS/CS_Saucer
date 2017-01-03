function [MAP_acu] = add_acoustic_signals(MAP_acu,MAP,Acoustic_dist,n_acu,Acoustic_Postion,resolution,RobotPositionX,RobotPositionYMap,RobotHeadingP)
    for i = 1:n_acu
       if (Acoustic_dist(i) < 1 && Acoustic_dist(i) > 0.15)           %Less than 1m
           Yaw =  -Acoustic_Postion(i,4)-RobotHeadingP;
           tilt = Acoustic_Postion(i,5);
           horisontal_dist = Acoustic_dist(i)/resolution*cos(tilt);
           x = round(RobotPositionX+horisontal_dist*cos(Yaw));
           y = round(RobotPositionYMap+horisontal_dist*sin(Yaw));
           if MAP(y,x) < 2 %The acoustic sensor has detected an obstacel, but not the Lidar
                %Acoustic obstacle is detoned 3 to have another property
                %than Lidar 2.
                %MAP_acu(y,x) = 3; %The acoustic sensor has detected an obstacel, but not the Lidar
                MAP_acu(y,x) = 3; %The acoustic sensor has detected an obstacel, but not the Lidar
                disp('Added signal from Acoustics')
                disp('  ')
           end
       end
    end
end