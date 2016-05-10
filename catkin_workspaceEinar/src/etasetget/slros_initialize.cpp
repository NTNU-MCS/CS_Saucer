#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "etasetget";

// For Block etasetget/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etasetget_geometry_msgs_Vector3> Sub_etasetget_370;

// For Block etasetget/Subsystem1/Subscribe
SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etasetget_std_msgs_Float32MultiArray> Sub_etasetget_365;

// For Block etasetget/Subsystem1/EtaSet/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etasetget_geometry_msgs_Vector3> Pub_etasetget_363;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

