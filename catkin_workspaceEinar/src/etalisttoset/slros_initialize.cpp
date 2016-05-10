#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "etalisttoset";

// For Block etalisttoset/Subscribe
SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etalisttoset_std_msgs_Float32MultiArray> Sub_etalisttoset_694;

// For Block etalisttoset/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etalisttoset_geometry_msgs_Vector3> Sub_etalisttoset_699;

// For Block etalisttoset/EtaSet/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etalisttoset_geometry_msgs_Vector3> Pub_etalisttoset_692;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

