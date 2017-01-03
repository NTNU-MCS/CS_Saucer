#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Path2SetPoint/Subscribe
extern SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray> Sub_Path2SetPoint_404;

// For Block Path2SetPoint/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_Path2SetPoint_std_msgs_Float64> Sub_Path2SetPoint_405;

// For Block Path2SetPoint/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_Path2SetPoint_geometry_msgs_Vector3> Sub_Path2SetPoint_370;

// For Block Path2SetPoint/EtaSet/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Path2SetPoint_geometry_msgs_Vector3> Pub_Path2SetPoint_400;

void slros_node_init(int argc, char** argv);

#endif
