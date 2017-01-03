function MAP= poppOut(MAP,PosX,PosY)


%poppOut -Responsible for reducing the map to reachable cells

% Inputs:
% PosX,PosY = Position of the vessel/robot
% MAP=Occupancy grid that the vessel operates in

% Outputs:
%    MAP= Occupancy grid reduced to reachable cells

% SubFunctions: none

% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016



%
Height=size(MAP,2);
% MAP=2*zeros(10);MAP=int8(MAP);
SavePos=[PosX PosY];
%h4=imagesc(ROBOMAP3); colormap(flipud(gray));
%PosX=100
%PosY=4
%MAP=ROBOMAP3;
%%
        


Width=size(MAP,2);

Height=size(MAP,1);

MAP(PosY,PosX)=5; 
while sum(sum(MAP==5))~=0;
    [r c]=find(MAP==5);
    for kk=1:length(r)
        PosX=c(kk);
        PosY=r(kk);
         for i=-1:1
         for j=-1:1
             if (~(i==0&&j==0))&&(PosY+i~=0)&&(PosX+j~=0)&&(PosY+i~=Width+1)&&(PosX+j~=Height+1)
             if MAP(PosY+i,PosX+j)==1;
                 MAP(PosY+i,PosX+j)=5;

             end
             end
         end
         end
         MAP(PosY,PosX)=4;
    end
 %  pause(0.2)
end
             MAP(MAP==1)=0;
             MAP(MAP==4)=1;
 %            set(h4,'CData',double(MAP)./2)
%save('TEST')
%a=asl
%MAP=2*zeros(56); MAP(2:end-1,2:end-1)=zeros(54);MAP=int8(MAP)
end
         