#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "LidarMapSim";

// For Block LidarMapSim/Subscribe
SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid> Sub_LidarMapSim_4;

// For Block LidarMapSim/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_LidarMapSim_geometry_msgs_Vector3> Sub_LidarMapSim_57;

// For Block LidarMapSim/Publish2
SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid> Pub_LidarMapSim_37;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

