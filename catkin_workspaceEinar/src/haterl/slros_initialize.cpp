#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "HaterL";

// For Block HaterL/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_HaterL_std_msgs_Float64> Sub_HaterL_2;

// For Block HaterL/Out/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL_std_msgs_Float64> Pub_HaterL_3;

// For Block HaterL/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL_std_msgs_Float64> Pub_HaterL_15;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

