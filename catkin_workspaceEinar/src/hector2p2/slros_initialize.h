#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Hector2P2/Subscribe2
extern SimulinkSubscriber<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped> Sub_Hector2P2_82;

// For Block Hector2P2/Subsystem1/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_Hector2P2_geometry_msgs_Vector3> Sub_Hector2P2_89;

// For Block Hector2P2/Eta/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Hector2P2_geometry_msgs_Vector3> Pub_Hector2P2_73;

void slros_node_init(int argc, char** argv);

#endif
