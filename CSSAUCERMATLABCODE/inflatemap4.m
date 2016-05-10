function [inflatedmap TravelDist]= inflatemap4(map,resolution,radius,PosX,PosY)

resolution=1/resolution;
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
            if (Distance<resolution*radius);
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
        if (sqrt(((j-PosX)^2+(i-PosY)^2)) <resolution*radius*0.7);
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
TravelDist=1+5./(0.1+TravelDist*4/resolution);


    
end   
% Squarex=[max([1 PosX-floor((inflateMargin/resolution))]) min(([Height PosX+floor((inflateMargin/resolution))]];
% Squarey=[max([1 PosY-floor((inflateMargin/resolution))]) min(([Height PosY+floor((inflateMargin/resolution))]))];
% clearing area around vessel that has been inflated
% for i=1:(Squarex(2)-Squarex(1))
%     for j=1:(Squarey(2)-Squarey(1))
% 



