function [inflatedmap, TravelDist]= inflatemap(map,resolution,radius,PosX,PosY,Psi)

%LidarFindGap - Responsible for inflating (expanding) objects 
%This is performed by emulating a lidar sending
%out rays from vessel position and detect discontinuities. Also detect Gaps
%in areas between seen and unseen area.
%
% Inputs:
% raduis=Inflation Radius
% map=Occupancy grid that the vessel operates in
% resolution=resolution of occupancy grid.
% PosX,PosY= Positoin of the vessel in the Occupancy Grid.
% 
%     
% Outputs:
% MAP= inflated occupancy grid

% Subfunctions: none
%
% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016
% Revised:
% Joachim Spange 07-December-2016

%------------- BEGIN CODE --------------


map2=map;
Nodesfound=sum(sum(map==2));
NodesfoundAcu=sum(sum(map==3));
Xlength=size(map,2);
Ylength=size(map,1);
TravelDist=zeros(Xlength,Ylength);
%% EDIT SPANGE
Anlge2Cell=zeros(Xlength,Ylength); %Angle to each cell
% 
for Degangle=-180:1:180
    Radangle=Degangle*pi/180;
    for r=0:.1:6.5/resolution;
        XPOS=PosX+round(r*cos(Radangle-Psi));
        YPOS=PosY+round(r*sin(Radangle-Psi));
        if (XPOS == PosX && YPOS == PosY)
            1;
        elseif map(YPOS,XPOS) > 1
            break
        elseif (Anlge2Cell(YPOS,XPOS) == 0 && XPOS<256 && XPOS > 0 && YPOS<256 && XPOS > 0)
            if abs(Radangle) < 1
                Anlge2Cell(YPOS,XPOS)=0;
            else
                Anlge2Cell(YPOS,XPOS)=2*abs(Radangle);
            end
        end
    end
    
end
%%

[col row]=find(map'==2);
RegisteredMap=[col row];
[col, row]=find(map'==3);
RegisteredMapAcu=[col row];

for k=1:size(map,1)
    for j=1:size(map,2)
        if map(k,j)==1
            Mat=RegisteredMap-(repmat([j k],(Nodesfound),1));
            Distance=(min(sqrt(sum(abs(Mat).^2,2))));
            TravelDist(k,j)=Distance;
            %%Anlge2Cell(k,j)=atan2(k-PosY,j-PosX);
            %Anlge2Cell(k,j)=atan2(j-PosX,k-PosY);
            if (Distance<radius/resolution);
                map2(k,j)=2;
            end
            
            % Searching for acoustic entry
            if ~isempty(RegisteredMapAcu)
                MatAcu = RegisteredMapAcu-(repmat([j k],(NodesfoundAcu),1));
                DistanceAcu=(min(sqrt(sum(abs(MatAcu).^2,2))));
                TravelDist(k,j)=min(Distance,DistanceAcu);
    %             if DistanceAcu < Distance
    %                 TravelDist(k,j)=DistanceAcu;
    %             end
                if (DistanceAcu<0.6*radius/resolution);
                    map2(k,j)=3;
                end
            end
            
        end
    end
end
  %  map2(PosY,PosX)==1;
inflatedmap=map2;
save('INfShitt')
if map2(PosY,PosX)==2 %Position within inflated shitt  :(
for k=1:Xlength
    for j=1:Ylength
        if (sqrt(((j-PosX)^2+(k-PosY)^2)) <radius*0.7/resolution);
            if map(k,j)~=2
                map2(k,j)=1;
            end
        end
    end
end

inflatedmap=map2;
end
%save('TravelDist')
%a=asl
%AngDiff=abs(Anlge2Cell-Psi);
%
TravelDist(TravelDist==0)=1e4;

%TravelDist=1+5./(0.1+TravelDist);
TravelDist=1+5./(0.1+TravelDist)+Anlge2Cell;
save('Inflatemap_use_to_see_heading_cost')

    
end   
% Squarex=[max([1 PosX-floor((inflateMargin/resolution))]) min(([Height PosX+floor((inflateMargin/resolution))]];
% Squarey=[max([1 PosY-floor((inflateMargin/resolution))]) min(([Height PosY+floor((inflateMargin/resolution))]))];
% clearing area around vessel that has been inflated
% for i=1:(Squarex(2)-Squarex(1))
%     for j=1:(Squarey(2)-Squarey(1))
% 



