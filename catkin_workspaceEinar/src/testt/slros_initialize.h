#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block TESTT/Subscribe
extern SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_TESTT_nav_msgs_OccupancyGrid> Sub_TESTT_4;

// For Block TESTT/Subsystem1/Subscribe
extern SimulinkSubscriber<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_TESTT_geometry_msgs_PoseWithCovarianceStamped> Sub_TESTT_21;

// For Block TESTT/Publish2
extern SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_TESTT_nav_msgs_OccupancyGrid> Pub_TESTT_37;

void slros_node_init(int argc, char** argv);

#endif
