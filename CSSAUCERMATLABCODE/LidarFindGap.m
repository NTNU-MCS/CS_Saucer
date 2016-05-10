
function [MAP Gaps]=LidarFindGap(RobotPositionY,RobotPositionX,RefMap,resolution)
MAP=RefMap;
MaxDist=100;
Ranges=zeros(1,360/0.25,1);
RangesPos=zeros(360/0.25,1);
FreeRecorder=zeros(360/0.25,1);
%RefMap(RobotPositionX,RobotPositionY)=1;
for Degangle=0.25:0.25:360
    Radangle=Degangle*pi/180;
for r=0:0.5:round(MaxDist/resolution);
    Ranges(Degangle*4)=round(MaxDist/resolution);
    XPOS=(RobotPositionX+round(r*cos(Radangle)));
    YPOS=RobotPositionY+round(r*sin(Radangle));
    if ( (XPOS>0) && (XPOS<1+size(RefMap,2)) && (YPOS>0) &&(YPOS<1+size(RefMap,1)) )  
    if RefMap(XPOS,YPOS)==2
    % RefMap(XPOS,YPOS)=2;
    Ranges(Degangle*4)=r;
    RangesPos(Degangle*4,1:2)=[XPOS YPOS];
    break
    elseif  (RefMap(XPOS,YPOS)==0)
   FreeRecorder(Degangle*4)=1;
   Ranges(Degangle*4)=r;
    XPOS=(RobotPositionX+round((r-1)*cos(Radangle)));
    YPOS=RobotPositionY+round((r-1)*sin(Radangle));
    RangesPos(Degangle*4,1:2)=[XPOS YPOS];
break
 end
    end
%if r==4
%    Ranges(Degangle*4)=4/resolution;
%end
RangesPos(Degangle*4,1:2)=[XPOS YPOS];
end
end
save LLidar
%ZZ=find(Ranges==max(Ranges))
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
K=find(abs(diff(Ranges))>2);
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
end
