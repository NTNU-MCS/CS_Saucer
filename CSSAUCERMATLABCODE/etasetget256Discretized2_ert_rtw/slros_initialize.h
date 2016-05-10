#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block etasetget256Discretized2/Subscribe
extern SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray> Sub_etasetget256Discretized2_404;

// For Block etasetget256Discretized2/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_etasetget256Discretized2_std_msgs_Float64> Sub_etasetget256Discretized2_405;

// For Block etasetget256Discretized2/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3> Sub_etasetget256Discretized2_370;

// For Block etasetget256Discretized2/EtaSet/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3> Pub_etasetget256Discretized2_400;

void slros_node_init(int argc, char** argv);

#endif
