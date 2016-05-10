
function MAP=UpdateUserMap4(RobotPositionX,RobotPositionY,RefMap,resolution)
MAP=RefMap;
MaxDist=3;
%RefMap(RobotPositionX,RobotPositionY)=1;
for Degangle=0:1:360
    Radangle=Degangle*pi/180;
for r=0:0.5:round(MaxDist/resolution);
    XPOS=(RobotPositionX+round(r*cos(Radangle)));
    YPOS=RobotPositionY+round(r*sin(Radangle));
     if ( (XPOS>0) && (XPOS<1+size(RefMap,2)) && (YPOS>0) &&(YPOS<1+size(RefMap,1)) )

    if RefMap(XPOS,YPOS)==0
     MAP(XPOS,YPOS)=1;
     %if RefMap(XPOS,YPOS)==-1
     %    RefMap(XPOS,YPOS)=0;
     %end e
    end
 
 if RefMap(XPOS,YPOS)==2
       % RefMap(XPOS,YPOS)=2;
        break
     end
end
end
end
end