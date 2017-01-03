
function [Gaps]=LidarFindGap(RobotPosition_X,RobotPosition_Y,RefMap,resolution)

%LidarFindGap - Identifies Gaps in the map. 
%This is performed by emulating a lidar sending
%out rays from vessel position and detect discontinuities. Also detect Gaps
%in areas between seen and unseen area.
%
% Inputs:
% RobotPosition_X, RobotPosition_Y : Position of the vessel/robot
% Occupancy grid that the vessel operates in
% resolution=resolution of occupancy grid.
%
% 
%     
% Outputs:
%  Gaps- List over identified Gaps, Contains x and y position
% Subfunctions: none
%
% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016

%------------- BEGIN CODE --------------
MaxDist=6.5;
%A=ALS
Ranges=zeros(1,360/0.25,1);
RangesPos=zeros(360/0.25,1);
FreeRecorder=zeros(360/0.25,1); %end of 

%Sending out rays in all angles around vessel
for Degangle=0.25:0.25:360
    Radangle=Degangle*pi/180;
for r=0:0.5:round(MaxDist/resolution);
    Ranges(Degangle*4)=round(MaxDist/resolution);
    XPOS=(RobotPosition_Y+round(r*cos(Radangle)));
    YPOS=RobotPosition_X+round(r*sin(Radangle));
    if ( (XPOS>0) && (XPOS<1+size(RefMap,2)) && (YPOS>0) &&(YPOS<1+size(RefMap,1)) )  
    if RefMap(XPOS,YPOS)==2
    % RefMap(XPOS,YPOS)=2;
    Ranges(Degangle*4)=r;
    RangesPos(Degangle*4,1:2)=[XPOS YPOS];
    break
    elseif  (RefMap(XPOS,YPOS)==0)
   FreeRecorder(Degangle*4)=1;
   Ranges(Degangle*4)=r;
    XPOS=(RobotPosition_Y+round((r-1)*cos(Radangle)));
    YPOS=RobotPosition_X+round((r-1)*sin(Radangle));
    RangesPos(Degangle*4,1:2)=[XPOS YPOS];
   
break
 end
    end
RangesPos(Degangle*4,1:2)=[XPOS YPOS];
end
end
%Finding 
ZZ=find(FreeRecorder==1);
if size(ZZ,1)>0
ZZZ=diff(ZZ);
Reg(1)=ZZ(1);
j=2;
for i=2:length(ZZZ)
    if ZZZ(i)>1
        Reg(j)=ZZ(i);
       Reg(j+1)=ZZ(i+1);
        j=j+2;
    end
end
Reg(end+1)=ZZ(end);
for i=1:length(Reg)/2
    KK(i)=round((Reg(i*2-1)+Reg(i*2))/2);
end
end
save LLidarPre
K=find(abs(diff(Ranges))>4);
if exist('KK');
K=[K KK];
end
K=sort(K);
Ranges=Ranges(K);
Ranges=[Ranges;K];
Ranges=sortrows(Ranges',1);
K=Ranges(:,2);
%Gaps=zeros(K,2);
Gaps=(RangesPos(K,:)+RangesPos(K+1,:))./2;
RangesPos(abs(diff(Ranges))>0.4);
save LLidar
hold on
%for i=1:size(Gaps,1)
 %   plot(Gaps(i,2),Gaps(i,1),'o','color','k','MarkerFaceColor','g')
%end
%a=ASL
end
