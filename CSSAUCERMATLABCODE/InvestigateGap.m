
function [Flag]=InvestigateGap(RobotPositionX,RobotPositionY,RefMap,resolution)
%save  'innmap2'
%RobotPositionX= round( 142.5000)
%RobotPositionY=round(155.5000)
%
Flag=0;
MAP=RefMap;
MaxDist=3;

%RefMap(RobotPositionX,RobotPositionY)=1;
for Degangle=1:1:360
    Degangle;
    Radangle=Degangle*pi/180;
for r=0:0.5:round(MaxDist/resolution);
    XPOS=(RobotPositionX+round(r*cos(Radangle)));
    YPOS=RobotPositionY+round(r*sin(Radangle));
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
