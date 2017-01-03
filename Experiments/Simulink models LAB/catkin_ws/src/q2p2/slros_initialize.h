#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Q2P2/Subscribe2
extern SimulinkSubscriber<qualisys::Subject, SL_Bus_Q2P2_qualisys_Subject> Sub_Q2P2_82;

// For Block Q2P2/Subsystem1/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_Q2P2_geometry_msgs_Vector3> Sub_Q2P2_89;

// For Block Q2P2/Eta/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Q2P2_geometry_msgs_Vector3> Pub_Q2P2_73;

void slros_node_init(int argc, char** argv);

#endif
