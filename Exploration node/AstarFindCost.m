function Cost=AstarFindCost(i,j,WeightMap,CurrentX,CurrentY);

%ExplorationMain -Find cost in connection between two nodes in a weigthed  grid. 

% Inputs:
% i,j = Coordinates of connected node from  Current position
%CurrentyX,CurrentY= Position of current node

% Outputs:
%    Cost= Cost of moving from node (CurrentY,CurrentX) to (i,j)
% Subfunctions: none
%
% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016



%Comment: For significantly improved speed; Table containing the calcuated table crossSet for all possible
%orrientations would be much faster. 

%------------- BEGIN CODE --------------




%load AINNFIND
Cost=0;
%WeightMap=ones(256);
%save init
%i=2
%j=3

%j=X

if i==0
    for J=0:sign(j):j
            Currj=(CurrentX+(J));
             Curri=(CurrentY+(i));

        if J==0
            Cost=Cost+(0.5*WeightMap(Curri,Currj));
        elseif J==j
            Cost=Cost+(0.5*WeightMap(Curri,Currj));
        else
    Cost=Cost+WeightMap(Curri,Currj);
        end
    end
elseif j==0
    for I=0:sign(i):i
                Currj=(CurrentX+(j));
             Curri=(CurrentY+(I));

        if I==0
            Cost=Cost+(0.5*WeightMap(Curri,Currj));
        elseif I==i
            Cost=Cost+(0.5*WeightMap(Curri,Currj));
        else
    Cost=Cost+WeightMap(Curri,Currj);
        end
    end
else
    


    
SignI=sign(i);
SignJ=sign(j);
i=abs(i);
j=abs(j);

Valnext_x_Y=0.5*(j/i)+0.5;
Valnext_x_X=1;
CrossSet=[0.5 0.5 0 0];
Xcrossed=0;
Ycrossed=0;

while 1==1;
  

if Valnext_x_X<Valnext_x_Y
    CrossSet=[CrossSet;Valnext_x_X (Valnext_x_X-0.5)*(i/j)+0.5 Xcrossed Ycrossed];
    Valnext_x_X=Valnext_x_X+1;
    Xcrossed=Xcrossed+1;
elseif Valnext_x_X> Valnext_x_Y
    CrossSet=[CrossSet;Valnext_x_Y (Valnext_x_Y-0.5)*(i/j)+0.5 Xcrossed Ycrossed];
Valnext_x_Y=Valnext_x_Y+(j/i);
Ycrossed=Ycrossed+1;
elseif Valnext_x_X==Valnext_x_Y
        CrossSet=[CrossSet;Valnext_x_X (Valnext_x_Y-0.5)*(i/j)+0.5 Xcrossed Ycrossed];
      Valnext_x_Y=Valnext_x_Y+(j/i);
    Valnext_x_X=Valnext_x_X+1;

       
        Ycrossed=Ycrossed+1;
        
        Xcrossed=Xcrossed+1;
end

if (Valnext_x_X>j+(0.5))&&Valnext_x_Y>j+(0.5)
   break;
end
end

CrossSet=[CrossSet;[j+0.5 i+0.5 j i]];
%save CROSS
%CrossSet(:,1:2)=CrossSet(:,1:2)/abs(i);
%CrossSet(:,1:2)=CrossSet(:,1:2)+0.5;
Cost=0;
for k=2:size(CrossSet,1)
    Curri=(CurrentY+(SignI*CrossSet(k,4)));
    Currj=(CurrentX+(CrossSet(k,3)*SignJ));
   

    %dist=norm([CrossSet(k,1)-CrossSet(k-1,1) CrossSet(k,2)-CrossSet(k-1,2)])
    Cost=Cost+norm([CrossSet(k,1)-CrossSet(k-1,1) CrossSet(k,2)-CrossSet(k-1,2)])*WeightMap(Curri,Currj);
end
end
%save ENDOFFNC;
%Square=Cost^2;
end
