#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block LidarMapSim128/Subscribe
extern SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid> Sub_LidarMapSim128_4;

// For Block LidarMapSim128/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_LidarMapSim128_geometry_msgs_Vector3> Sub_LidarMapSim128_57;

// For Block LidarMapSim128/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_LidarMapSim128_std_msgs_Float64> Pub_LidarMapSim128_77;

// For Block LidarMapSim128/Publish2
extern SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_LidarMapSim128_nav_msgs_OccupancyGrid> Pub_LidarMapSim128_37;

void slros_node_init(int argc, char** argv);

#endif
