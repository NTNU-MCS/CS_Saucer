function [Optimal_pathOut1D]= ExplorationMain(u)
save Uinnt2
%ExplorationMain - Main script for exploration/pathplanning. 
% Responsible for generating a path in the occupancy grid according to the exploration strategy. 
% Displays and update interactive map window.
% Code should be run from Simulink-Node 
%
% Inputs:
%    u: u(1:end-1,1:end) is an occupancy grid containing a vector made to matrix of the type Nav/OccupancyGrid.map 
%which may be generated from Hector Slam. 
%u(end,1:3)=[x-position,y-positoin,heading]
%u(end,4)=resoultion,
%u(end,5:7)= Code parameters, see below.
%     
% Outputs:
%    Optimal_pathOut1D(1:128) = Vector containing the 128 first
%    x-coordinates of the generated path
%    Optimal_pathOut1D(129:256) = Vector containing the 128 first 
%    y-coordinates of the generated path
%    Optimal_pathOut1D(257:768) = Vector recording Gaps if the Gap Based
%    Exploration is chosen
%    Optimal_pathOut1D(769) = Desired heading when performing docking


% Subfunctions: InflateMap,Poppout,LidarUpdate,PathAstar,AtarFindCost,LidarFindGap,InvestigateGap 
%s
% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016

%------------- BEGIN CODE --------------

%It is very convenient to save the start and end of the function in the
%workspace.
%Allocation of persistent variables.
persistent Desired_Docking_Heading MAP_acu Count hh1 hh2 h1 h2 h3 h4 h5 h6 h7 h8 h9 Optimal_path Optimal_pathOld UnFlagList GAPS RobotPositionYMapLog RobotPositionXLog writerObj ;

%Connecting_Distance=4;
Recalculate=1;
% Extracting Map, and other information from input Matrix
MAP=u(1:end-1,1:end);
MAP=int8(MAP);
TravelDist=[0 0];
%Map representation: 2=visited:object, 1=visited:free. 0=unvisited.
MAP(MAP==100)=2; % This is to enable 
%%MAP(MAP>50)=2; 
MAP(MAP==0)=1;
MAP(MAP<0)=0;
%save MAP
MAP(1,1)=3; %Dummy variable for image

%% Adding Acoustic data
if isempty(MAP_acu)
    MAP_acu = zeros(size(MAP));
end
MAP(MAP_acu==3)=3;

%%

resolution=u(end,4);
if resolution==0
    resolution=0.1; 
end
%sim Frontier40GAPOUT
%Obtaining User Algorithm Strategy Parameters
DistWeight=u(end,5); %0= no weights, 1=weights on, calculate using first and last, 2=weight on, calculate using all nodes in connection.    
Method=u(end,6); % 1=Frontier Based Exploration, 2=Gap Navigation Exploration
Inflate_Radius=u(end,7);
%Inflate_Radius=0.4;
Connecting_Distance=u(end,8);
%Connecting_Distance=4;
Acoustic_dist = u(end,9:14);
Acoustic_Postion = vec2mat(u(end,15:44),5);
n_acu = u(end,45);
%DistWeight=1;
%SDeclarations / Parameters for later use
[Height Width]=size(MAP);
MID=Height*resolution/2;
InitPos=[MID/resolution MID/resolution];
MapperMat=0*MAP;
SuperGoal=[];

%Getting VesselPositions
RobotPositionX=round((u(end,1)+MID)/resolution);
RobotPositionY=round((-u(end,2)+ MID)/resolution);

RobotPositionXP=((u(end,1)+MID)/resolution);
RobotPositionYP=((-u(end,2)+ MID)/resolution);

%% Added
RobotHeadingP= u(end,3);                    %Vessel heading
%Patch_heading = pi/2-RobotHeadingP;        %Rotate such that 0 heading is up, and pos heading is clockwise
Patch_heading = RobotHeadingP;              %Rotate such that 0 heading is up, and pos heading is clockwise
%%
RobotPositionYMapP=Height+1-RobotPositionYP; %Y position starting from the top. 

%RobotPositionY=Height-72;        
%RobotPositionY=256-72;
%RobotPositionX=109

RobotPositionYMap=Height+1-RobotPositionY; %Y position starting from the top. 


save STARTOFFNC


%innitializing plot window
if (ishandle(h1)==1)
else
    %VideoName=['THISISSPARTA5.avi']

    %writerObj = VideoWriter(VideoName,'Uncompressed AVI');
    %open(writerObj);

    figure(1)
    MAP(1,1)=2; %Making sure that the image range is from 0-2.  
    h4=imagesc(MAP);
    colormap(flipud(gray));
    hold on

    hold on
    plot(-10,-10,'square','color','k','MarkerSize',10,'MarkerEdgeColor','k','MarkerFaceColor','k')                                  %Acu cell
    plot(-10,-10,'square','color',[0.4 0.4 0.4],'MarkerSize',10,'MarkerEdgeColor',[0.4 0.4 0.4],'MarkerFaceColor',[0.4 0.4 0.4])    %Occuoied cell
    plot(-10,-10,'square','color',[0.7 0.7 0.7],'MarkerSize',10,'MarkerEdgeColor',[0.7 0.7 0.7],'MarkerFaceColor',[0.7 0.7 0.7])    %Free cell
    plot(-20,-20,'square','color',[0 0 0],'MarkerSize',10,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',[1 1 1])                      %Unexplored cell

    hh1=plot(nan,nan,':','color','g','LineWidth',2);                                    %Traversed path
    hh2=plot(nan,nan,'o','color','k','MarkerFaceColor','g','MarkerSize',7);             %Exploration Goal
    h1=plot(nan,nan,'o','color','c','MarkerFaceColor','c','MarkerSize',7,'LineWidth',2);%Vessel Position


    h2=plot(nan,nan,'--');                                                              %Lidar range
    h6=plot(nan,nan,'o','color','b','MarkerFaceColor','b','MarkerSize',7,'LineWidth',2);%Goal

    h7= plot(nan,nan,'y','LineWidth',3);                                                %Path
    h8=plot(nan,nan,'o','color','k');
    %h8=plot(nan,nan,'o','color','k','MarkerFaceColor','g','MarkerSize',7);
    h9=plot(nan,nan,'o','color','r');

    %%
    axis equal
    legend('Occupied cell Acu','Occupied cell','Free cell','Unexplored cell','Traversed path','Exploration Goal','Vessel Position','Lidar Range','Goal','Path')%,'Identified Gap','Explored Gap')

    % PLOTTING 1v4:  load Optimal_path Optimal_path
    %plot(Optimal_path(:,2),Optimal_path(:,1),'b','LineWidth',2)
    %legend('Goal','Path, Connection distance=1','Vessel position','Path, Connection distance=4')
    %   Optimal_path=[]

    %Rescaling axis
    set(gca,'XTick',[0:Height/8:Height]);
    %    set(gca,'FontSize',8);

    set(gca,'YTick',[0:Height/32:Height]);
    set(gca,'XtickLabels',[-MID:Height/8*resolution:MID]);
    set(gca,'YtickLabels',[MID:-Height/32*resolution:-MID]);
    set(h4,'ButtonDownFcn',@ImageClickCallback);
    axis equal
    %% This is the first place to alter!
    %h1=plot(nan,nan,'o','color','c','MarkerFaceColor','c');
    L=5;
    %C/S Saucer
    tmpR=[cos(Patch_heading) -sin(Patch_heading); sin(Patch_heading) cos(Patch_heading)];
    tmpR = tmpR';
    boat = tmpR*[L/2 .4*L/2 -.6*L/2 -L/2 -L/2 -.6*L/2 .4*L/2 L/2;
        0 1.5 1.5 .28 -.28 -1.5 -1.5 0];
    h1 = patch(boat(1,:),boat(2,:),'c');
%axis off
end

OUTSHOW= h4.UserData; %Obtaining user input from plot window.


%OUTSHOW=[56 93];
%OUTSHOW=[186 132];
%OUTSHOW=[167 135];
%ROBOMAP=UpdateUserMap(RobotPositionYMap,RobotPositionX,MAP,ROBOMAP);
%MAP=UpdateUserMap3(RobotPositionYMap,RobotPositionX,MAP,MAP,0.05);
foundValues=0;
Mapper=zeros(Height*Width,2);

%%%%Processign the map prior to pathplanners

% Adding acoustiv signals to map
MAP_acu = add_acoustic_signals(MAP_acu,MAP,Acoustic_dist,n_acu,Acoustic_Postion,resolution,RobotPositionX,RobotPositionYMap,RobotHeadingP);
%MAP_acu = AcousticUpdate(MAP_acu,MAP,n_acu,Acoustic_Postion,resolution,RobotPositionX,RobotPositionYMap,RobotHeadingP);
% Inflating map objects to that of safety distance 
[InfMAP, ~]=inflatemap(MAP,resolution,Inflate_Radius,RobotPositionX,RobotPositionYMap,RobotHeadingP);


% Popping out map so that only paths the vessel can reach is considered.
InfMAP=poppOut(InfMAP,RobotPositionX,Height+1-RobotPositionY);

% Simulating lidar, so that if no laserscant one assume that the nearest area is clean.
InfMAP=LidarUpdate(RobotPositionYMap,RobotPositionX,InfMAP,resolution);
%set(h4,'CData',double(InfMAP)./2)
%a=asl
%set(h4,'CData',InfMAP);
[~, TravelDist]=inflatemap(InfMAP,resolution,Inflate_Radius,RobotPositionX,RobotPositionYMap,RobotHeadingP);

%%%%%%%%%%%%%%%%%%%5
 %%Playing with plots. 
if size(RobotPositionYMapLog,1)<1
    RobotPositionYMapLog=RobotPositionYMap;
    RobotPositionXLog=RobotPositionX;
else 
    RobotPositionYMapLog(end+1)=RobotPositionYMapP;
    RobotPositionXLog(end+1)=RobotPositionXP;
end
%%
L=5;
%C/S Saucer
tmpR=[cos(Patch_heading) -sin(Patch_heading); sin(Patch_heading) cos(Patch_heading)];
tmpR = tmpR';
boat = tmpR*[L/2 .4*L/2 -.6*L/2 -L/2 -L/2 -.6*L/2 .4*L/2 L/2;
    0 1.5 1.5 .28 -.28 -1.5 -1.5 0];
set(h1,'XData',RobotPositionXP+boat(1,:),'YData',RobotPositionYMapP+boat(2,:))
%set(h1,'XData',RobotPositionXP,'YData',RobotPositionYMapP)
%%
set(hh1,'XData',RobotPositionXLog,'YData',RobotPositionYMapLog)
%set(h4,'CData',double(MAP)./2)
pause(1)
%set(h4,'CData',double(InfMAP)./2)
set(h4,'CData',double(InfMAP)./2)
if size(OUTSHOW,1)>0
    if OUTSHOW(1,1)<10
        %legend('Occupied cell','Free cell','Unexplored cell','Traversed path','Exploration Goal','Vessel Position','Lidar Range','Goal','Path')%,'Identified Gap','Explored Gap')
        legend('Occupied cell Acu','Occupied cell','Free cell','Unexplored cell','Traversed path','Exploration Goal','Vessel Position','Lidar Range','Goal','Path')%,'Identified Gap','Explored Gap')
    end
end
if norm(OUTSHOW)<100
    OUTSHOW=[];
    SuperGoal= [];
elseif (InfMAP(OUTSHOW(2),OUTSHOW(1))==0)
    SuperGoal=[OUTSHOW(1),OUTSHOW(2)];
    OUTSHOW=[];
else
    SuperGoal=[];
    PathFinder=1; %Selecting AStar now that there is only one goal.
end

if size(SuperGoal,1)>0     
    set(hh2,'XData',SuperGoal(1),'YData',SuperGoal(2))
else
    set(hh2,'XData',nan,'YData',nan)
end

     
%Method Frontier
if size(Optimal_path>0);
    DistTotal=norm(Optimal_path(1,:)-[RobotPositionX RobotPositionYMap])*resolution;
    i=RobotPositionX;
    k=RobotPositionYMap;
    Neighboors=(([InfMAP(i-1,k) InfMAP(i+1,k) InfMAP(i,k-1) InfMAP(i,k+1)]));
    NeighboorsSum=sum(Neighboors==0);
    NeighboorSum2=sum(Neighboors==2);
    if ((NeighboorsSum>0)&&(NeighboorsSum<4))&&(NeighboorSum2==0)&&DistTotal>1;
        Recalculate=0;
    end
end


if Recalculate==1
    for i=2:(Height)-1
        for k=2:(Width)-1
            if (InfMAP(i,k)==1)
                if ((abs(RobotPositionYMap-i)<2)&& (abs(RobotPositionX-k)<2))
                else
                    Neighboors=(([InfMAP(i-1,k) InfMAP(i+1,k) InfMAP(i,k-1) InfMAP(i,k+1)]));
                    NeighboorsSum=sum(Neighboors==0);
                    NeighboorSum2=sum(Neighboors==2);
                    if ((NeighboorsSum>0)&&(NeighboorsSum<4))%&&(NeighboorSum2==0)
                        foundValues=foundValues+1;
                        Mapper(foundValues,1:2)=[i k];
                        MapperMat(i,k)=1;
                    end
                end
            end
        end
end
CompValues=Mapper(1:foundValues,1:2);
[Avstand Pos]=min((sum((abs(CompValues-repmat([RobotPositionYMap RobotPositionX],foundValues,1))).^2')));
if size(CompValues,1)>0
    Goall=CompValues(Pos,1:2);
end 

end
%InfMAP(MapperMat==1)=63;
%set(h4,'CData',double(InfMAP))
%   save('Stuff')

%a=asl
%TravelDist=ones(256);
if size(OUTSHOW,2)>0
    CompValues=OUTSHOW;
    Goall(1)=CompValues(2);
    Goall(2)=CompValues(1);
    CompValues=[fliplr([CompValues])];    
    MapperMat=0*MAP;    MapperMat(Goall(1),Goall(2))=1;
    %Optimal_path=PATH6([RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,CompValues);
    %Optimal_path= PATH_ALL3(f[RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,DistWeight,PathFinder,TravelDist,MapperMat);
    Optimal_path=PathAstar(RobotPositionX,RobotPositionYMap,InfMAP,MapperMat,Connecting_Distance,TravelDist,DistWeight,SuperGoal);

elseif sum(sum(MapperMat))==0 %All frontiers are investigated return to innitial position.
    % a=asl
    Goall(1)=InitPos(1);
    Goall(2)=InitPos(2);
    MapperMat( Goall(2), Goall(1))=1;
    CompValues=[Goall];
    % CompValues=[sMID MID];

    Optimal_path=PathAstar(RobotPositionX,RobotPositionYMap,InfMAP,MapperMat,Connecting_Distance,TravelDist,DistWeight,SuperGoal);

    %Optimal_path= PATH_ALL3([RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,DistWeight,PathFinder,TravelDist,MapperMat);
else
    if Recalculate==1;
        %DistWeight=0;
        %TravelDist=0*TravelDist;
        %Optimal_path= PATH_ALL3([RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,DistWeight,PathFinder,TravelDist,MapperMat);
        Optimal_path=PathAstar(RobotPositionX,RobotPositionYMap,InfMAP,MapperMat,Connecting_Distance,TravelDist,DistWeight,SuperGoal);

        if size(Optimal_pathOld,2)<1
            Optimal_pathOld=Optimal_path;
        end
        if Method==0
            GAPComp=ismember(round(GAPS),[Optimal_pathOld(1,1) Optimal_pathOld(1,2)],'rows');
            isOldGapfound=sum(GAPComp);
        end
        save TEST

        if ((Optimal_pathOld(1,1)==-1&&Method==1)||(Method==0&&isOldGapfound>0)); %old Frontier Not found
            DirOld=atan2((Optimal_pathOld(1,1)-Optimal_pathOld(2,1)),(Optimal_pathOld(1,2)-Optimal_pathOld(2,2)));
            DirNew=atan2((Optimal_path(1,1)-Optimal_path(2,1)),(Optimal_path(1,2)-Optimal_path(2,2)));
            DirChange=abs(DirOld-DirNew);
            if DirChange>pi/2;
                Optimal_path=Optimal_pathOld;
            end
        end

    end
    Optimal_pathOld=Optimal_path;   
    % FrontierDetected=sum(sum(ismember(CompValues,[Optimal_path(1,1) Optimal_path(1,2)],'rows')));

    %     if (size(Optimal_pathnew,1)< (size(Optimal_path,1)-(1+DummyCount))||(Optimal_path(1,1)==inf)||~FrontierDetected)
    %DummyCount=0;
    %Optimal_path=Optimal_pathnew;
    %    end

end  
%        DummyCount=DummyCount+1;%
%end

%    set(h4,'CData',double(InfMAP)./2)
save HEre
set(h6,'XData',Optimal_path(1,2),'YData',Optimal_path(1,1))
K=size(Optimal_path,1);
set(h7,'XData',[Optimal_path(1:K,2);RobotPositionX],'YData',[Optimal_path(1:K,1);RobotPositionYMap])
%map2 = robotics.BinaryOccupancyGrid(ROBOMAP,1);
%PosMap=-zeros(22);
%PosMap(RobotPositionYMap,RobotPositionX)=1;
%PosMap(22-Goal(2),Goal(1))=1;

x=linspace(0,2*pi,50); %Plot dummy. 
set(h2,'XData',6.5*cos(x)/resolution+(RobotPositionX),'YData',6.5*sin(x)/resolution+RobotPositionYMap);
%set(h7,'XData',[Optimal_path(1:K-(1+DummyCount),2);RobotPositionX],'YData',[Optimal_path(1:Kz-(1+DummyCount),1);RobotPositionYMap])

    


%TEST=rossubscriber('/Eta')
%TEST=recieve(TEST,10)

%Optimal_path=Optimal_path(K,:)*resolution;


%Optimal_pathOut=[-MID+Optimal_path(K,1) -MID+Optimal_path(K,2)] ;
%Optimal_pathOut=resolution*[-MID/resolution+Optimal_path(end-K,2) -MID/resolution+Optimal_path(end-K,1)] ;
%axis tight

%Sending last 64 setpoints to list for procesing . 

N_UnFlagList=min([128 size(UnFlagList,1)]);
N_Gap=min([128 size(GAPS,1)]);

KK=min(128,size(Optimal_path,1));
%DrawList2Set(ROBOMAP3,Optimal_path,resolution,MID,Optimal_path)
%DrawList2Set2(ROBOMAP3,Optimal_path,resolution,MID,Optimal_path,[RobotPositionX RobotPositionYMAP])
Optimal_pathOut1D=1000*ones(768,1);
Optimal_pathOut1D(1:KK)=-((-1+[Optimal_path(end-KK+1:end,1)])*resolution-MID);
Optimal_pathOut1D(129:129+KK-1)=(Optimal_path(end-KK+1:end,2))*resolution-MID;
if size(GAPS,2)>0
    Optimal_pathOut1D(257:257+N_Gap-1)=GAPS(1:N_Gap,1);
    Optimal_pathOut1D(385:385+N_Gap-1)=GAPS(1:N_Gap,2);
end
if size(UnFlagList,2)>0
    Optimal_pathOut1D(513:513+N_UnFlagList-1)=UnFlagList(1:N_UnFlagList,1);
    Optimal_pathOut1D(641:641+N_UnFlagList-1)=UnFlagList(1:N_UnFlagList,2);
end
%%
if isempty(Desired_Docking_Heading)
    Desired_Docking_Heading = -1e6;
end
if length(OUTSHOW) == 3                                         %Docking mode selected
    if (norm([Optimal_path(1,2), Optimal_path(1,1)]-[RobotPositionXP, RobotPositionYMapP])) < 1/resolution
        Desired_Docking_Heading =  OUTSHOW(3);
        %disp('Yodelehiuuuuu2')
    else
        Desired_Docking_Heading = -1e6;
    end
end
Optimal_pathOut1D(769) = Desired_Docking_Heading;
%%
save ENDOFFNC

%set(h4,'CData',double(InfMAP)./2)
       % set(gca,'nextplot','replacechildren');
%set(gcf,'Renderer','zbuffer');
%frame = getframe;

%writeVideo(writerObj,frame);

% if size(Count,1)<1
%     Count=0
% else
%     Count=Count+1
% end
% if Count>20
% end 
end

function ImageClickCallback( objectHandle , eventData )
axesHandle  = get(objectHandle,'Parent');
coordinates = get(axesHandle,'CurrentPoint');
coordinates = round(coordinates(1,1:2));
if (norm(coordinates(1:2))<10)
    objectHandle.UserData=[];
else
    objectHandle.UserData=coordinates(1,1:2);
    coordinates = coordinates(1,1:2);
end
% message = sprintf('x: %.1f , y: %.1f',coordinates (1) ,coordinates (2));
% helpdlg(message);

%% Docking & Desired heading
%Construct a Yes no question
message = sprintf('Are you docking now?\n Going to x: %.1f , y: %.1f',coordinates (1) ,coordinates (2));
choice = questdlg(message, ...
	'Docking?', ...
	'Yes','No','No');
% Handle response
switch choice
    case 'Yes'
        prompt={'Enter a value of \psi (in degrees)'};
        name = 'Heading Value';
        defaultans = {'0'};
        options.Interpreter = 'tex';
        answer = inputdlg(prompt,name,[1 40],defaultans,options);
        if isempty(answer)
            1;
        else
            Heding_dock = str2double(answer{1});
            Heding_dock = pi/180*Heding_dock;
            objectHandle.UserData = [objectHandle.UserData, Heding_dock];
        end
    case 'No'
        1;
end


end
