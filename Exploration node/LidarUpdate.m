function MAP=LidarUpdate(RobotPosition_Y,RobotPosition_X,RefMap,resolution)

%LidarUpdate -Assumes that the vessel can see ahead in section where the lidar has not recieved a signal. 
%Assumes that there is no objects in these directions. 

% Inputs:
% RobotPosition_Y,RobotPosition_X = Position of the vessel/robot
% RefMap=Occupancy grid that the vessel operates in
% resolution=resolution of occupancy grid.

% Outputs:
%    MAP= updated occupancy grid
%
% SubFunctions: none

% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016



MAP=RefMap;
MaxDist=5;
%RefMap(RobotPosition_Y,RobotPosition_X)=1;
for Degangle=0:1:360
    Radangle=Degangle*pi/180;
    for r=0:0.5:round(MaxDist/resolution);
        XPOS=(RobotPosition_Y+round(r*cos(Radangle)));
        YPOS=RobotPosition_X+round(r*sin(Radangle));
        if ( (XPOS>0) && (XPOS<1+size(RefMap,2)) && (YPOS>0) &&(YPOS<1+size(RefMap,1)) )
            % EDIT!
            if RefMap(XPOS,YPOS)==0
            %if (RefMap(XPOS,YPOS)==0 || MAP(XPOS,YPOS) == 3)
                 MAP(XPOS,YPOS)=1;
            end

            if RefMap(XPOS,YPOS)==2
               % RefMap(XPOS,YPOS)=2;
                break
            end
        end
    end
end
end