#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Q2PAll/Subscribe2
extern SimulinkSubscriber<qualisys::Subject, SL_Bus_Q2PAll_qualisys_Subject> Sub_Q2PAll_82;

// For Block Q2PAll/Eta/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Q2PAll_geometry_msgs_Vector3> Pub_Q2PAll_73;

// For Block Q2PAll/EulerAng/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Q2PAll_geometry_msgs_Vector3> Pub_Q2PAll_100;

void slros_node_init(int argc, char** argv);

#endif
