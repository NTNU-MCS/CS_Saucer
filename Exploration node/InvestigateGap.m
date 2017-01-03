
function [Flag]=InvestigateGap(RobotPosition_Y,RobotPosition_X,RefMap,resolution)

%InvestigateGap -Examine whether a Gap can be checked as explored or not. 

% Inputs:
% RobotPosition_Y,RobotPosition_X = Position of the vessel/robot
%CurrentyX,CurrentY= Position of current node

% Outputs:
%    Flag= 1 if the Gap still needs to be explored, Flag=0 if the Gap can
%    be checked as explored
%
% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016




Flag=0;
MAP=RefMap;
MaxDist=3;

%RefMap(RobotPosition_Y,RobotPosition_X)=1;
for Degangle=1:1:360
    Degangle;
    Radangle=Degangle*pi/180;
for r=0:0.5:round(MaxDist/resolution);
    XPOS=(RobotPosition_Y+round(r*cos(Radangle)));
    YPOS=RobotPosition_X+round(r*sin(Radangle));
     if ( (XPOS>0) && (XPOS<1+size(RefMap,2)) && (YPOS>0) &&(YPOS<1+size(RefMap,1)) )

    if RefMap(XPOS,YPOS)==0
        Flag=1;
        break
     MAP(XPOS,YPOS)=1;
     %if RefMap(XPOS,YPOS)==-1
     %    RefMap(XPOS,YPOS)=0;
     %end e
    end
 
 if RefMap(XPOS,YPOS)==2
       % RefMap(XPOS,YPOS)=2;
 %  a=Asl
       break
     end
     end
end
end
end
