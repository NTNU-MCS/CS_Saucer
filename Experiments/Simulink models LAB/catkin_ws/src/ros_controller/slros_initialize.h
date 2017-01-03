#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ROS_Controller/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_ROS_Controller_geometry_msgs_Vector3> Sub_ROS_Controller_659;

// For Block ROS_Controller/Subsystem1/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_ROS_Controller_geometry_msgs_Vector3> Sub_ROS_Controller_652;

// For Block ROS_Controller/UOUT/Subscribe2
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_ROS_Controller_std_msgs_Bool> Sub_ROS_Controller_892;

// For Block ROS_Controller/NonlinearPassiveObs/NuOut/Publish3
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_ROS_Controller_geometry_msgs_Vector3> Pub_ROS_Controller_779;

// For Block ROS_Controller/NonlinearPassiveObs/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ROS_Controller_std_msgs_Float64> Pub_ROS_Controller_888;

// For Block ROS_Controller/UOUT/Publish1
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_ROS_Controller_std_msgs_UInt16> Pub_ROS_Controller_701;

// For Block ROS_Controller/UOUT/Publish2
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_ROS_Controller_std_msgs_UInt16> Pub_ROS_Controller_702;

// For Block ROS_Controller/UOUT/Publish3
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_ROS_Controller_std_msgs_UInt16> Pub_ROS_Controller_703;

// For Block ROS_Controller/aout/Publish1
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_ROS_Controller_std_msgs_UInt16> Pub_ROS_Controller_736;

// For Block ROS_Controller/aout/Publish2
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_ROS_Controller_std_msgs_UInt16> Pub_ROS_Controller_737;

// For Block ROS_Controller/aout/Publish3
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_ROS_Controller_std_msgs_UInt16> Pub_ROS_Controller_738;

void slros_node_init(int argc, char** argv);

#endif
