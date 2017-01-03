#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Path2SetPoint";

// For Block Path2SetPoint/Subscribe
SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray> Sub_Path2SetPoint_404;

// For Block Path2SetPoint/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_Path2SetPoint_std_msgs_Float64> Sub_Path2SetPoint_405;

// For Block Path2SetPoint/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_Path2SetPoint_geometry_msgs_Vector3> Sub_Path2SetPoint_370;

// For Block Path2SetPoint/EtaSet/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Path2SetPoint_geometry_msgs_Vector3> Pub_Path2SetPoint_400;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

