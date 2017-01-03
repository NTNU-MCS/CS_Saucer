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

% Subfunctions: InflateMap,Poppout,LidarUpdate,PathAstar,AtarFindCost,LidarFindGap,InvestigateGap 
%s
% Author: Einar Ueland1
% email: einarsu@stud.ntnu.no
% June 2016; Last revision: 01-June-2016

%------------- BEGIN CODE --------------

%It is very convenient to save the start and end of the function in the
%workspace.
%Allocation of persistent variables.
persistent Count hh1 hh2 h1 h2 h3 h4 h5 h6 h7 h8 h9 Optimal_path Optimal_pathOld UnFlagList GAPS RobotPositionYMapLog RobotPositionXLog writerObj ;

%Connecting_Distance=4;
Recalculate=1;
% Extracting Map, and other information from input Matrix
MAP=u(1:end-1,1:end);
MAP=int8(MAP);
TravelDist=[0 0];
%Map representation: 2=visited:object, 1=visited:free. 0=unvisited.
MAP(MAP>50)=2; 
MAP(MAP==0)=1;
MAP(MAP<0)=0;
%save MAP
MAP(1,1)=2; %Dummy variable for image
%    MAP(1,1)=2; %Making sure that fthe image range is from 0-2.  

resolution=u(end,4);
if resolution==0
    resolution=0.1; 
end
%sim Frontier40GAPOUT
%Obtaining User Algorithm Strategy Parameters
DistWeight=u(end,5); %0= no weights, 1=weights on, calculate using first and last, 2=weight on, calculate using all nodes in connection.    
Method=u(end,6); % 1=Frontier Based Exploration, 2=Gap Navigation Exploration
Inflate_Radius=u(end,7);
Inflate_Radius=0.4;
Connecting_Distance=u(end,8);
Connecting_Distance=4;
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
RobotPositionYMapP=Height+1-RobotPositionYP; %Y position starting from the top. 

%RobotPositionY=Height-72;        
%RobotPositionY=256-72;
%RobotPositionX=109

RobotPositionYMap=Height+1-RobotPositionY; %Y position starting from the top. 


save STARTOFFNC


%% innitializing plot window
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
    %.F{
%When including legend square:
%.}

    hold on
plot(-10,-10,'square','color','k','MarkerSize',10,'MarkerEdgeColor','k','MarkerFaceColor','k')
plot(-10,-10,'square','color',[0.5 0.5 0.5],'MarkerSize',10,'MarkerEdgeColor',[0.5 0.5 0.5],'MarkerFaceColor',[0.5 0.5 0.5])
plot(-20,-20,'square','color',[0 0 0],'MarkerSize',10,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',[1 1 1])
  %             plot(nan,nan,'o','color','r','MarkerFaceColor','r')
   % hh2=plot(nan,nan,'o','color','k','MarkerFaceColor','g','MarkerSize',7);

        %plot(RobotPositionX,RobotPositionY,'o','color','k','MarkerFaceColor','r')
            %    plot(RobotPositionY,RobotPositionX,'o','color','r')

               % plot(30,30,'o','color',r'r')

%plot(-2,-2,'square','color',[1 1 0],'MarkerSize',10,'MarkerEdgeColor',[1 1 0],'MarkerFaceColor',[1 1 0])
    hh1=plot(nan,nan,':','color','g','LineWidth',2);
   hh2=plot(nan,nan,'o','color','k','MarkerFaceColor','g','MarkerSize',7);
    h1=plot(nan,nan,'o','color','r','MarkerFaceColor','r','MarkerSize',7,'LineWidth',2);


    h2=plot(nan,nan,'--');
    h6=plot(nan,nan,'o','color','b','MarkerFaceColor','b','MarkerSize',7,'LineWidth',2);

    h7= plot(nan,nan,'y','LineWidth',3);
    h8=plot(nan,nan,'o','color','k');
    %h8=plot(nan,nan,'o','color','k','MarkerFaceColor','g','MarkerSize',7);
    h9=plot(nan,nan,'o','color','r');


    h1=plot(nan,nan,'o','color','r','MarkerFaceColor','r');
%xlim([25 240])
%ylim([75 180])
axis equal
%axis off
%xlim([
%    ylim([
legend('Occupied cell','Free cell','Unexplored cell','Traversed path','Exploration Goal','Vessel Position','Lidar Range','Goal','Path')%,'Identified Gap','Explored Gap')

   % legend('Scanner Range','Goal','Planned Path','Vessel Position')


    
    
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
%axis off
end
%% End of if

OUTSHOW= h4.UserData; %Obtaining user input from plot window. 

%OUTSHOW=[56 93];
%OUTSHOW=[186 132];
%OUTSHOW=[167 135];
%ROBOMAP=UpdateUserMap(RobotPositionYMap,RobotPositionX,MAP,ROBOMAP);
%MAP=UpdateUserMap3(RobotPositionYMap,RobotPositionX,MAP,MAP,0.05);
foundValues=0;
Mapper=zeros(Height*Width,2);

%% Processign the map prior to pathplanners
% Inflating map objects to that of safety distance

[InfMAP, TravelDist]=inflatemap(MAP,resolution,Inflate_Radius,RobotPositionX,RobotPositionYMap);


% Popping out map so that only paths the vessel can reach is considered.
InfMAP=poppOut(InfMAP,RobotPositionX,Height+1-RobotPositionY);

% Simulating lidar, so that if no laserscant one assume that the nearest area is clean.
InfMAP=LidarUpdate(RobotPositionYMap,RobotPositionX,InfMAP,resolution);
%set(h4,'CData',double(InfMAP)./2)
%a=asl
%set(h4,'CData',InfMAP);
[~, TravelDist]=inflatemap(InfMAP,resolution,Inflate_Radius,RobotPositionX,RobotPositionYMap);

%%%%%%%%%%%%%%%%%%%5
 %%Playing with plots. 
if size(RobotPositionYMapLog,1)<1
    RobotPositionYMapLog=RobotPositionYMap;
    RobotPositionXLog=RobotPositionX;
else 
    RobotPositionYMapLog(end+1)=RobotPositionYMapP;
    RobotPositionXLog(end+1)=RobotPositionXP;
end


set(h1,'XData',RobotPositionXP,'YData',RobotPositionYMapP)
set(hh1,'XData',RobotPositionXLog,'YData',RobotPositionYMapLog)
%set(h4,'CData',double(MAP)./2)
pause(1)
%set(h4,'CData',double(InfMAP)./2)
set(h4,'CData',double(InfMAP)./2)
if size(OUTSHOW,1)>0
    if OUTSHOW(1,1)<10
legend('Occupied cell','Free cell','Unexplored cell','Traversed path','Exploration Goal','Vessel Position','Lidar Range','Goal','Path')%,'Identified Gap','Explored Gap')

%        for i=1:10
              %  set(gca,'nextplot','replacechildren');
%set(gcf,'Renderer','zbuffer');
%frame = getframe;

%writeVideo(writerObj,frame);
        end
        
 %       close(writerObj)
  %      a=asl
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
if Method==1
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
elseif Method==0
%legend('Explored cell: Occupied','Explored cell: Free Occupied','Unexplored cell','Traversed path','Goal','Path','Vessel Position','Unexamined GAP','Examined GAP')

    % save('Stuff')
    if size(GAPS,2)>0&&size(Optimal_path,2)>0;
        Flagg =InvestigateGap(Optimal_path(1,2),Optimal_path(1,1),InfMAP,0.05);
        if Flagg==0;
            [a]=(ismember(round(GAPS),Optimal_path(1,:),'rows'));
            if sum(a)>0
                ZZZ=find(a==1); %Index of GAP
                ZZZ=ZZZ(1,1);
                if ZZZ==1
                    UnFlagList(end+1,:)=GAPS(1,:);
                     GAPS=GAPS(2:end,:);
                elseif ZZZ==size(GAPS,1)
                    UnFlagList(end+1,:)=GAPS(ZZZ,:);
                    GAPS=GAPS(1:end-1,:);
                else
                    UnFlagList(end+1,:)=GAPS(ZZZ,:);
                    GAPS=[GAPS(1:ZZZ-1,:);GAPS(ZZZ+1:end,:)];
                end
            end
        end
        [Flag]=InvestigateGap(round(RobotPositionYMap),round(RobotPositionX),InfMAP,0.05);
            K=1;
            while K<=size(GAPS,1)
                [Flag]=InvestigateGap(round(GAPS(K,1)),round(GAPS(K,2)),InfMAP,resolution);
                if Flag==0
                    if K==1
                        UnFlagList(end+1,:)=GAPS(1,:);
                        GAPS=GAPS(2:end,:);
                    elseif K==size(GAPS,1)
                        UnFlagList(end+1,:)=GAPS(K,:);
                        GAPS=GAPS(1:end-1,:);
                    else
                        UnFlagList(end+1,:)=GAPS(K,:);
                        GAPS=[GAPS(1:K-1,:);GAPS(K+1:end,:)];
                    end
                    K=K-1;    
                end
                K=K+1;    
            end
        end
    ReGap=1;
    if size(Optimal_path,2)>0
        DistTotal=norm(Optimal_path(1,:)-[RobotPositionX RobotPositionYMap])*resolution
    end
    if ReGap
        ReGap=0;
        Recalculate=1;
        [GAPS_found]=LidarFindGap(RobotPositionX,RobotPositionYMap,InfMAP,resolution);
        for i=1:size(GAPS_found,1)
            [Flag]=InvestigateGap(round(GAPS_found(i,1)),round(GAPS_found(i,2)),InfMAP,resolution);
            if Flag
                if ~exist('GAPS')
                    GAPS=GAPS_found(i,:);
                else
                    GAPS(end+1,:)=GAPS_found(i,:);
                end
            end
        end
    end
    if size(GAPS,1)>0
        set(h8,'XData',GAPS(:,2),'YDATA',GAPS(:,1))
    end
    if size(UnFlagList,1)>0
        set(h9,'XData',UnFlagList(:,2),'YDATA',UnFlagList(:,1))
    end
    if size(GAPS,1)>0           
        Goall=round(GAPS(1,:));
    end
    for i=1:size(GAPS,1)
        MapperMat((round(GAPS(i,1))),(round(GAPS(i,2))))=1;
    end
end
%TravelDist=ones(256);
if size(OUTSHOW,2)>0
    CompValues=OUTSHOW;
    Goall(1)=CompValues(2);
    Goall(2)=CompValues(1);
    CompValues=[fliplr([CompValues])];    
    MapperMat=0*MAP;    MapperMat(Goall(1),Goall(2))=1;
%   Optimal_path=PATH6([RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,CompValues);
  %  Optimal_path= PATH_ALL3(f[RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,DistWeight,PathFinder,TravelDist,MapperMat);
              Optimal_path=PathAstar(RobotPositionX,RobotPositionYMap,InfMAP,MapperMat,Connecting_Distance,TravelDist,DistWeight,SuperGoal);
 
elseif sum(sum(MapperMat))==0 %All frontiers are investigated return to innitial position.
   % a=asl
        Goall(1)=InitPos(1);
       Goall(2)=InitPos(2);
       MapperMat( Goall(2), Goall(1))=1;
       CompValues=[Goall];
      % CompValues=[sMID MID];

      
      
           Optimal_path=PathAstar(RobotPositionX,RobotPositionYMap,InfMAP,MapperMat,Connecting_Distance,TravelDist,DistWeight,SuperGoal);

    %  Optimal_path= PATH_ALL3([RobotPositionX RobotPositionYMap],[Goall(2) Goall(1)],InfMAP,Height,Width,DistWeight,PathFinder,TravelDist,MapperMat);
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
    Optimal_path=Optimal_pathOld
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


save ENDOFFNC

%set(h4,'CData',double(InfMAP)./2)
       % set(gca,'nextplot','replacechildren');
%set(gcf,'Renderer','zbuffer');
%frame = getframe;

%writeVideo(writerObj,frame);

if size(Count,1)<1
    Count=0
else
    Count=Count+1
end
if Count>20
end 
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
message     = sprintf('x: %.1f , y: %.1f',coordinates (1) ,coordinates (2));
helpdlg(message);

%{
axis equal
ylim([20 130])
set(gca,'
Label','')
set(gca,'YTickLabel','')

colordata = colormap;

colordata(1,:)=[1 1 1 ]
colordata(2,:)=[0.5 0.5 0.5]
colordata(3,:)=[0.5 0.5 0.5]

colordata(3,:)=[0 0 0]
colordata(end,:)=[1 1 0]
colormap(colordata)
%}

end
