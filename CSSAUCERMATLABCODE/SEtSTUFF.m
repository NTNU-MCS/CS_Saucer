clear
close all

clear all
%RunDirect
load Frontier256
load Frontier128
load posedata

%load lidardata
%load 'ScanLength' %lidar node of length 360.
posedata.Data=-ones(128*128,1);
%posedata.Info.Resolution=0.05
%sim projectDirectControll

resolution=posedata.Info.Resolution;

 lidardata.Header.Seq=616;
%rospublisher('/scan',lidardata)
chatpub = rospublisher('/map','nav_msgs/OccupancyGrid');
%chatpubscan = rospublisher('/scan','sensor_msgs/LaserScan');

%msg = rosmessage(chatpub);
%send(chatpub,msg);
rospublisher('/map',posedata)
%rospublisher('/scan',lidardata)

REFMAP=zeros(128,128);
REFMAP(1:128,1)=2;
REFMAP(1:64,1)=2;

REFMAP(1:128,128)=2;
REFMAP(1,1:128)=2;
REFMAP(128,1:128)=2;
REFMAP(100,1:100)=2;
REFMAP(50,28:100)=2;
REFMAP(20:50,50)=2;
REFMAP(1:128,1)=2;
REFMAP(1:128,128)=2;
REFMAP(1,1:128)=2;
REFMAP(128,1:128)=2;
REFMAP(10,1:50)=2;
REFMAP(25,1:50)=2;
REFMAP(40,40:50)=2;
REFMAP(40,40:45)=2;
REFMAP(80,20:40)=2;
REFMAP(80:100,40)=2;
REFMAP(80:100,120)=2;
REFMAP(120:122,120:122)=2;
REFMAP(120:122,20:25)=2;
REFMAP(120:122,10:11)=2;
REFMAP(125:128,10:11)=2;
REFMAP(100:110,30:40)=2;
REFMAP(1:20,100:128)=2;
REFMAP(10:20,80:128)=2;
REFMAP(20:40,80:90)=2;
REFMAP(1:128,90:90)=2;

REFMAP(100:105,70:80)=2;

REFMAP=zeros(128);
MAP(56:76,1:45)=2;
MAP(56:76,85:128)=2;
MAP(85:128,56:76)=2;
MAP(1:45,56:76)=2;



%av4=imagesc(REFMAP./2);
% colormap(flipud(gray));
 

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
FrameId='laser'
%NSec=690145390;
%Sec=1460556360;
Sec=int32(1460556360);
Nsec=int32(690145390);



subb2=rossubscriber('/scan')
lidardata=receive(subb2,10)

path='~/bagfiles/2016-04-17-21-17-58.bag'
BAG=rosbag(path)
bagselect1 = select(BAG, 'Topic', '/Eta')
msgs = readMessages(bagselect1);
ts = timeseries(bagselect1, 'Eta.X')
%path='bagfiles/2016-04-19-22-38-52.bag'
%BAG=rosbag(path)BAG=rosbag(path)
%BAG=rosbag(path)
%bagselect2 = select(BAG, 'Eta')
bagselect3 = select(BAG, 'Eta', [0 206])
