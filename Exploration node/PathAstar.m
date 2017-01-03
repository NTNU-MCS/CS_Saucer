function OptimalPath=PathAstar(StartX,StartY,MAP,GoalRegister,Connecting_Distance,WeightMap,DistWeight,SuperGoal)
save('PathAstar')

%PathAstar -Generates a path in the occupancy grid
%to goal nodes according to the implemented A* algorithm

% Inputs:
% StartX,StartY = Position of the vessel/robot
% MAP=Occupancy grid that the vessel operates in
% GoalRegister=Matrix of goal nodes.
% Connecting_Distance= Connecting distance between individual nodes in the
% grid
% WeightMap= Grid containing the weigths of nodes
% DistWeight= Parameter deciding if nodes should be weigthed. (0=no,1=Weight first and last node in connection,2=Weigth all nodes in connection)
% SuperGoal= Has a value if user has defined an exploration goal outside of
% exlpored map. 

% Outputs:
%    OptimalPath= Matrix containing list of the calculated path
%
% SubFunctions: AstarFindCost(only used if distweight =2)

% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016



%FINDING ASTAR PATH IN AN OCCUPANCY GRID
%WeightMap=ones(256);
%nNeighboor=3;
% Preallocation of Matrices
[Height,Width]=size(MAP); %Height and width of matrix
GScore=zeros(Height,Width);           %Matrix keeping track of G-scores 
FScore=single(inf(Height,Width));     %Matrix keeping track of F-scores (only open list) 
Hn=single(zeros(Height,Width));       %Heuristic matrix
OpenMAT=int8(zeros(Height,Width));    %Matrix keeping of open grid cells
ClosedMAT=int8(zeros(Height,Width));  %Matrix keeping track of closed grid cells
ClosedMAT(MAP==2)=1;                  %Adding object-cells to closed matrix
ClosedMAT(MAP==0)=1;                  %Adding object-cells to closed matrix
%% Edit Spange
ClosedMAT(MAP==3)=1;                  %Adding object-cells to closed matrix
%%
ParentX=int16(zeros(Height,Width));   %Matrix keeping track of X position of parent
ParentY=int16(zeros(Height,Width));   %Matrix keeping track of Y position of parent
%colormap(flipud(gray))
%hold on
%plot(StartY,StartX);
%%% Setting up matrices representing neighboors to be investigated
NeighboorCheck=ones(2*Connecting_Distance+1);
Dummy=2*Connecting_Distance+2;
Mid=Connecting_Distance+1;
for i=1:Connecting_Distance-1
NeighboorCheck(i,i)=0;
NeighboorCheck(Dummy-i,i)=0;
NeighboorCheck(i,Dummy-i)=0;
NeighboorCheck(Dummy-i,Dummy-i)=0;
NeighboorCheck(Mid,i)=0;
NeighboorCheck(Mid,Dummy-i)=0;
NeighboorCheck(i,Mid)=0;
NeighboorCheck(Dummy-i,Mid)=0;
end
NeighboorCheck(Mid,Mid)=0;

[row, col]=find(NeighboorCheck==1);
Neighboors=[row col]-(Connecting_Distance+1);
N_Neighboors=size(col,1);
%%% End of setting up matrices representing neighboors to be investigated


%%%%%%%%% Creating Heuristic-matrix based on distance to nearest  goal node
[row, col]=find(GoalRegister==1);
RegisteredGoals=[col row];
Nodesfound=size(RegisteredGoals,1);

if size(SuperGoal,1)>0
    Distance2SuperGoal=sqrt(sum(abs(RegisteredGoals-repmat(SuperGoal,size(RegisteredGoals,1),1)).^2,2));
    WeigthDist2SuperGoal=2;
    Distance2SuperGoal=Distance2SuperGoal*WeigthDist2SuperGoal;
    minDistance2SuperGoal=min(Distance2SuperGoal);
    FrontierWeigths=0*WeightMap;
    for zzz=1:size(Distance2SuperGoal,1)
        FrontierWeigths(RegisteredGoals(zzz,2),RegisteredGoals(zzz,1))=WeigthDist2SuperGoal*(Distance2SuperGoal(zzz)-minDistance2SuperGoal);
    end
end

for k=1:size(GoalRegister,1)
    for j=1:size(GoalRegister,2)
        if MAP(k,j)==1
            Mat=RegisteredGoals-(repmat([j k],(Nodesfound),1));
            if size(SuperGoal,1)>0
                Distance=(min(sqrt(sum(abs(Mat).^2,2))+Distance2SuperGoal));
            else 
                Distance=(min(sqrt(sum(abs(Mat).^2,2))));
            end
                Hn(k,j)=Distance;
        end
    end
end
%Hn=zeros(256,256)
%End of creating Heuristic-matrix. 
%Note: If Hn values is set to zero the method will reduce to the Dijkstras method.

%Initializign start node with FValue and opening first node.
FScore(StartY,StartX)=Hn(StartY,StartX);         
OpenMAT(StartY,StartX)=1;   




while 1==1 %Code will break when path found or when no path exist
    MINopenFSCORE=min(min(FScore));
    if MINopenFSCORE==inf;
    %Failuere!
    OptimalPath=[inf];
    RECONSTRUCTPATH=0;
     break
    end
    [CurrentY,CurrentX]=find(FScore==MINopenFSCORE);
    CurrentY=CurrentY(1);
    CurrentX=CurrentX(1);

    if GoalRegister(CurrentY,CurrentX)==1
    %GOAL!!
        RECONSTRUCTPATH=1;
        break
    end
    
  %Remobing node from OpenList to ClosedList  
    OpenMAT(CurrentY,CurrentX)=0;
    FScore(CurrentY,CurrentX)=inf;
    ClosedMAT(CurrentY,CurrentX)=1;
    for p=1:N_Neighboors
        i=Neighboors(p,1); %Y
        j=Neighboors(p,2); %X
        if CurrentY+i<1||CurrentY+i>Height||CurrentX+j<1||CurrentX+j>Width
            continue
        end
        Flag=1;
        if(ClosedMAT(CurrentY+i,CurrentX+j)==0) %Neiboor is open;
            if (abs(i)>1||abs(j)>1);   
                %Jumping over a grid cell, Need to check that the path does not hit an object
                JumpCells=2*max(abs(i),abs(j))-1;
                for K=1:JumpCells;
                    YPOS=round(K*i/JumpCells);
                    XPOS=round(K*j/JumpCells);
            
                    if (MAP(CurrentY+YPOS,CurrentX+XPOS)==2)
                        Flag=0;
                    end
                end
            end
            if Flag==1;           
                if DistWeight==1
                    tentative_gScore = GScore(CurrentY,CurrentX) + (WeightMap(CurrentY,CurrentX)+WeightMap(CurrentY+i,CurrentX+j))/2*sqrt(i^2+j^2);
                elseif DistWeight==0;
                    tentative_gScore = GScore(CurrentY,CurrentX) + sqrt(i^2+j^2);
                elseif DistWeight==2
                    tentative_gScore = GScore(CurrentY,CurrentX) +AstarFindCost(i,j,WeightMap,CurrentX,CurrentY);
                end
                if size(SuperGoal,1)>0
                    tentative_gScore=tentative_gScore+FrontierWeigths(CurrentY+i,CurrentX+j);
                end
                    if OpenMAT(CurrentY+i,CurrentX+j)==0
                    OpenMAT(CurrentY+i,CurrentX+j)=1;                    
                elseif tentative_gScore >= GScore(CurrentY+i,CurrentX+j);
                    continue
                end
                ParentX(CurrentY+i,CurrentX+j)=CurrentX;
                ParentY(CurrentY+i,CurrentX+j)=CurrentY;
                GScore(CurrentY+i,CurrentX+j)=tentative_gScore;
                FScore(CurrentY+i,CurrentX+j)= tentative_gScore+Hn(CurrentY+i,CurrentX+j);
            end
        end
    end
end
k=2;
if RECONSTRUCTPATH
    OptimalPath(1,:)=[CurrentY CurrentX];
    while RECONSTRUCTPATH
        if (((CurrentX== StartX)) &&(CurrentY==StartY))
            break
        end

        CurrentXDummy=ParentX(CurrentY,CurrentX);
        CurrentY=ParentY(CurrentY,CurrentX);
        CurrentX=CurrentXDummy;
        OptimalPath(k,:)=[CurrentY CurrentX];
        k=k+1;
    end
end

save('OpenNClosed')

end

      
    

