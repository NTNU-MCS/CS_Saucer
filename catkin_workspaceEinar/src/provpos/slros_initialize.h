#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block provPos/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_provPos_std_msgs_Float64> Sub_provPos_2;

// For Block provPos/Out/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_provPos_std_msgs_Float64> Pub_provPos_3;

// For Block provPos/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_provPos_std_msgs_Float64> Pub_provPos_15;

// For Block provPos/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_provPos_20;

// For Block provPos/Set Parameter
extern SimulinkParameterSetter<real64_T, double> ParamSet_provPos_16;

// For Block provPos/Set Parameter1
extern SimulinkParameterSetter<real64_T, double> ParamSet_provPos_19;

void slros_node_init(int argc, char** argv);

#endif
