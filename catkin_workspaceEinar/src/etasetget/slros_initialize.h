#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block etasetget/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etasetget_geometry_msgs_Vector3> Sub_etasetget_370;

// For Block etasetget/Subsystem1/Subscribe
extern SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etasetget_std_msgs_Float32MultiArray> Sub_etasetget_365;

// For Block etasetget/Subsystem1/EtaSet/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etasetget_geometry_msgs_Vector3> Pub_etasetget_363;

void slros_node_init(int argc, char** argv);

#endif
