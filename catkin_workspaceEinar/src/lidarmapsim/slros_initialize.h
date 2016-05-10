#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block LidarMapSim/Subscribe
extern SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid> Sub_LidarMapSim_4;

// For Block LidarMapSim/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_LidarMapSim_geometry_msgs_Vector3> Sub_LidarMapSim_57;

// For Block LidarMapSim/Publish2
extern SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid> Pub_LidarMapSim_37;

void slros_node_init(int argc, char** argv);

#endif
