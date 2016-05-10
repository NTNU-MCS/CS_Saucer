#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "TESTT";

// For Block TESTT/Subscribe
SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_TESTT_nav_msgs_OccupancyGrid> Sub_TESTT_4;

// For Block TESTT/Subsystem1/Subscribe
SimulinkSubscriber<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_TESTT_geometry_msgs_PoseWithCovarianceStamped> Sub_TESTT_21;

// For Block TESTT/Publish2
SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_TESTT_nav_msgs_OccupancyGrid> Pub_TESTT_37;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

