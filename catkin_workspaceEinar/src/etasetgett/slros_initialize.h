#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block etasetgett/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etasetgett_geometry_msgs_Vector3> Sub_etasetgett_370;

// For Block etasetgett/Subsystem1/Subscribe
extern SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etasetgett_std_msgs_Float32MultiArray> Sub_etasetgett_365;

// For Block etasetgett/Subsystem1/EtaSet/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etasetgett_geometry_msgs_Vector3> Pub_etasetgett_363;

void slros_node_init(int argc, char** argv);

#endif
