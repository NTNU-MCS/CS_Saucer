#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "mindistfromscan2";

// For Block mindistfromscan2/Subscribe1
SimulinkSubscriber<sensor_msgs::LaserScan, SL_Bus_mindistfromscan2_sensor_msgs_LaserScan> Sub_mindistfromscan2_416;

// For Block mindistfromscan2/Publish1
SimulinkPublisher<std_msgs::Float32, SL_Bus_mindistfromscan2_std_msgs_Float32> Pub_mindistfromscan2_413;

// For Block mindistfromscan2/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_mindistfromscan2_std_msgs_Float64> Pub_mindistfromscan2_414;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

