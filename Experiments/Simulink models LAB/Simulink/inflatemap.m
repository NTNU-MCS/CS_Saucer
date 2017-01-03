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

%------------- BEGIN CODE --------------


map2=map;
Nodesfound=sum(sum(map==2));
NodesfoundAcu=sum(sum(map==3));
Xlength=size(map,2);
Ylength=size(map,1);
TravelDist=zeros(Xlength,Ylength);
%% EDIT SPANGE
Anlge2Cell=zeros(Xlength,Ylength); %Angle to each cell
%%

[col, row]=find(map'==2);
RegisteredMap=[col row];
[col, row]=find(map'==3);
RegisteredMapAcu=[col row];


for k=1:size(map,1)
    for j=1:size(map,2)
        if map(k,j)==1
            Mat=RegisteredMap-(repmat([j k],(Nodesfound),1));
            Distance=(min(sqrt(sum(abs(Mat).^2,2))));
            TravelDist(k,j)=Distance;
            %Anlge2Cell(k,j)=atan2(k-PosY,j-PosX);
            Anlge2Cell(k,j)=atan2(j-PosX,k-PosY);
            if (Distance<radius/resolution);
                map2(k,j)=2;
            end
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

inflatedmap = map2;
%if map2(PosY,PosX)==2 %Position within inflated shitt  :(
if map2(PosY,PosX)>=2 %EDIT
    for k=1:Xlength
        for j=1:Ylength
            if (sqrt(((j-PosX)^2+(k-PosY)^2)) <radius*0.7/resolution);
                if map(k,j)<2
                %if map(k,j)~=2
                    map2(k,j)=1;
                end
            end
        end
    end
    inflatedmap=map2;
end
%save('TravelDist')
%a=asl
AngDiff=abs(Anlge2Cell-Psi);
%
TravelDist(TravelDist==0)=1e4;

%TravelDist=1+5./(0.1+TravelDist);
%TravelDist=1+5./(0.1+TravelDist)+5*AngDiff/(0.1+TravelDist);
TravelDist=1+(5+AngDiff)./(0.1+TravelDist);
save('Inflatemap_use_to_see_heading_cost')

end   
% Squarex=[max([1 PosX-floor((inflateMargin/resolution))]) min(([Height PosX+floor((inflateMargin/resolution))]];
% Squarey=[max([1 PosY-floor((inflateMargin/resolution))]) min(([Height PosY+floor((inflateMargin/resolution))]))];
% clearing area around vessel that has been inflated
% for i=1:(Squarex(2)-Squarex(1))
%     for j=1:(Squarey(2)-Squarey(1))
% 



