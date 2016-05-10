#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "etasetgett";

// For Block etasetgett/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etasetgett_geometry_msgs_Vector3> Sub_etasetgett_370;

// For Block etasetgett/Subsystem1/Subscribe
SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etasetgett_std_msgs_Float32MultiArray> Sub_etasetgett_365;

// For Block etasetgett/Subsystem1/EtaSet/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etasetgett_geometry_msgs_Vector3> Pub_etasetgett_363;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

