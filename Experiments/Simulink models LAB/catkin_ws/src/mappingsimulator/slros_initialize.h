#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block MappingSimulator/Subscribe
extern SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid> Sub_MappingSimulator_4;

// For Block MappingSimulator/Subsystem1/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_MappingSimulator_geometry_msgs_Vector3> Sub_MappingSimulator_57;

// For Block MappingSimulator/Subsystem1/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_MappingSimulator_std_msgs_Float64> Pub_MappingSimulator_77;

// For Block MappingSimulator/Subsystem1/Publish2
extern SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid> Pub_MappingSimulator_37;

void slros_node_init(int argc, char** argv);

#endif
