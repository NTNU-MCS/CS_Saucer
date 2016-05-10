#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block etalisttoset/Subscribe
extern SimulinkSubscriber<std_msgs::Float32MultiArray, SL_Bus_etalisttoset_std_msgs_Float32MultiArray> Sub_etalisttoset_694;

// For Block etalisttoset/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_etalisttoset_geometry_msgs_Vector3> Sub_etalisttoset_699;

// For Block etalisttoset/EtaSet/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_etalisttoset_geometry_msgs_Vector3> Pub_etalisttoset_692;

void slros_node_init(int argc, char** argv);

#endif
