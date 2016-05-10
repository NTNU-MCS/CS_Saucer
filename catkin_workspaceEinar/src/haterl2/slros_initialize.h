#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block HaterL2/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_HaterL2_std_msgs_Float64> Sub_HaterL2_2;

// For Block HaterL2/Out/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL2_std_msgs_Float64> Pub_HaterL2_3;

// For Block HaterL2/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL2_std_msgs_Float64> Pub_HaterL2_15;

// For Block HaterL2/Set Parameter
extern SimulinkParameterSetter<real64_T, double> ParamSet_HaterL2_16;

// For Block HaterL2/Set Parameter1
extern SimulinkParameterSetter<real64_T, double> ParamSet_HaterL2_19;

void slros_node_init(int argc, char** argv);

#endif
