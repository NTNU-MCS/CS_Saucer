#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ROS_ControllerNiKi";

// For Block ROS_ControllerNiKi/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3> Sub_ROS_ControllerNiKi_659;

// For Block ROS_ControllerNiKi/Subsystem1/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3> Sub_ROS_ControllerNiKi_652;

// For Block ROS_ControllerNiKi/U out/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3> Pub_ROS_ControllerNiKi_153;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

