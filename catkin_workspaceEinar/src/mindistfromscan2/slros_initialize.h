#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block mindistfromscan2/Subscribe1
extern SimulinkSubscriber<sensor_msgs::LaserScan, SL_Bus_mindistfromscan2_sensor_msgs_LaserScan> Sub_mindistfromscan2_416;

// For Block mindistfromscan2/Publish1
extern SimulinkPublisher<std_msgs::Float32, SL_Bus_mindistfromscan2_std_msgs_Float32> Pub_mindistfromscan2_413;

// For Block mindistfromscan2/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_mindistfromscan2_std_msgs_Float64> Pub_mindistfromscan2_414;

void slros_node_init(int argc, char** argv);

#endif
