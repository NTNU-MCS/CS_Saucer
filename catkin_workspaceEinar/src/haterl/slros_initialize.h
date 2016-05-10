#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block HaterL/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_HaterL_std_msgs_Float64> Sub_HaterL_2;

// For Block HaterL/Out/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL_std_msgs_Float64> Pub_HaterL_3;

// For Block HaterL/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL_std_msgs_Float64> Pub_HaterL_15;

void slros_node_init(int argc, char** argv);

#endif
