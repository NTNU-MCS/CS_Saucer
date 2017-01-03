#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ROS_ControllerNiKi/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3> Sub_ROS_ControllerNiKi_659;

// For Block ROS_ControllerNiKi/Subsystem1/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3> Sub_ROS_ControllerNiKi_652;

// For Block ROS_ControllerNiKi/U out/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3> Pub_ROS_ControllerNiKi_153;

void slros_node_init(int argc, char** argv);

#endif
