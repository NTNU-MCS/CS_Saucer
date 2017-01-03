%clear
close all

%RunDirect
load Frontier256_original
%load Frontier256
load posedata

%% Acoustics
Acoustic_Position = zeros(6,5);
Acoustic_Position(1,:) = [0.5,0,0.05,0*pi/180,0]; %[x,y,z,Yaw,tilt]
Acoustic_Position(2,:) = [0,-0.5,0.05,-90*pi/180,0]; %[x,y,z,Yaw,tilt]
Acoustic_Position(3,:) = [-0.5,0,0.05,180*pi/180,0]; %[x,y,z,Yaw,tilt]
Acoustic_Position(4,:) = [0,0.5,0.05,90*pi/180,0]; %[x,y,z,Yaw,tilt]
n_acu = 4;                                  %Numbers of acusensors in use, for now max 6
%%

%load lidardata
%load 'ScanLength' %lidar node of length 360.
posedata.Data=-ones(256*256,1);
%sim projectDirectControll

%% EDIT SPANGE
%posedata.Info.Origin.Position.X = 100;
%posedata.Info.Origin.Position.Y = 100;
%posedata.Info.Resolution = 0.05; %1px = 5cm
%posedata.Info.Resolution = 0.2;
% chatpubpos = rospublisher('/Position','geometry_msgs/Vector3');
% msg = rosmessage(chatpubpos);
% msg.X = posedata.Info.Origin.Position.X;
% msg.Y = posedata.Info.Origin.Position.Y;
% msg.Z = posedata.Info.Origin.Position.Z;
% send(chatpubpos,msg)
%%
resolution=posedata.Info.Resolution;

%rospublisher('/scan',lidardata)


chatpub = rospublisher('/map','nav_msgs/OccupancyGrid');
%chatpubscan = rospublisher('/scan','sensor_msgs/LaserScan');


%msg = rosmessage(chatpub);
%send(chatpub,msg);
rospublisher('/map',posedata)
%rospublisher('/scan',lidardata)
%load MAP_original MAP
load MAP_acoustic_docking.mat MAP
%load MAP MAP
%%
%MAP(:,150:155)=2;
%MAP(:,50:55)=2;
%%
REFMAPACU = MAP;
MAP(MAP == 3) = 1;      %Removing acoustic object, Lidar don't see them.
REFMAP=MAP;
REFMAP(REFMAP==1)=0;

%av4=imagesc(REFMAP./2);
%colormap(flipud(gray));
 

%subb2=rossubscriber('/EtaSet2')
%posedata2=recieve(subb2,10)
%Set Lidar Stuff
%load lidardata
%load lidardata2 lidardata
%FrameID='laser'
Sec=int32(1460556360);
Nsec=int32(690145390);
AngleMin=single(3.1416);
AngleMax=single(-3.1241);
AngleIncrement=single(-0.0175);
TimeIncrement=single(1.0578e-07);
ScanTime=single(3.7975e-05);
RangeMin=single(0.05);
RangeMax=single(6);
FrameRecievedL=uint32(1);
FrameCurrentL=uint32(1);
Seq=uint32(615);
FrameId='laser';
%NSec=690145390;
%Sec=1460556360;
Sec=int32(1460556360);
Nsec=int32(690145390);



% subb2=rossubscriber('/scan')
% lidardata=receive(subb2,10)
% 
% path='~/bagfiles/2016-04-17-21-17-58.bag'
% BAG=rosbag(path)
% bagselect1 = select(BAG, 'Topic', '/Eta')
% msgs = readMessages(bagselect1);
% ts = timeseries(bagselect1, 'Eta.X')
% %path='bagfiles/2016-04-19-22-38-52.bag'
% %BAG=rosbag(path)BAG=rosbag(path)
% %BAG=rosbag(path)
% %bagselect2 = select(BAG, 'Eta')
% bagselect3 = select(BAG, 'Eta', [0 206])
