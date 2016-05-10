#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block VesselSimulator/Subsystem/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_VesselSimulator_geometry_msgs_Vector3> Sub_VesselSimulator_22;

// For Block VesselSimulator/U out1/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_VesselSimulator_geometry_msgs_Vector3> Pub_VesselSimulator_269;

void slros_node_init(int argc, char** argv);

#endif
