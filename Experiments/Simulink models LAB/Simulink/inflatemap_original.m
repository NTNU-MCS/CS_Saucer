function [inflatedmap TravelDist]= inflatemap(map,resolution,radius,PosX,PosY)

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

%------------- BEGIN CODE --------------


map2=map;
Nodesfound=sum(sum(map==2));
RegisteredMap=inf(Nodesfound,2);
z=1;
Xlength=size(map,2);
Ylength=size(map,1);
TravelDist=zeros(Xlength,Ylength);

[col row]=find(map'==2);
RegisteredMap=[col row];


for k=1:size(map,1)
    for j=1:size(map,2)
        if map(k,j)==1
            Mat=RegisteredMap-(repmat([j k],(Nodesfound),1));
            Distance=(min(sqrt(sum(abs(Mat).^2,2))));
            TravelDist(k,j)=Distance;
            if (Distance<radius/resolution);
            map2(k,j)=2;
            end

            
    end
    end
end
  %  map2(PosY,PosX)==1;
inflatedmap=map2;
save('INfShitt')
if map2(PosY,PosX)==2 %Position within inflated shitt  :(
for i=1:Xlength
    for j=1:Ylength
        if (sqrt(((j-PosX)^2+(i-PosY)^2)) <radius*0.7/resolution);
            if map(i,j)~=2
                map2(i,j)=1;
            end
        end
    end
end

inflatedmap=map2;
end
save('TravelDist')
%a=asl
TravelDist(TravelDist==0)=1e4;
TravelDist=1+5./(0.1+TravelDist);


    
end   
% Squarex=[max([1 PosX-floor((inflateMargin/resolution))]) min(([Height PosX+floor((inflateMargin/resolution))]];
% Squarey=[max([1 PosY-floor((inflateMargin/resolution))]) min(([Height PosY+floor((inflateMargin/resolution))]))];
% clearing area around vessel that has been inflated
% for i=1:(Squarex(2)-Squarex(1))
%     for j=1:(Squarey(2)-Squarey(1))
% 



