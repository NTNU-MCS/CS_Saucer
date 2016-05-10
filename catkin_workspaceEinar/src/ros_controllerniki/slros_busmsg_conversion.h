#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include "ROS_ControllerNiKi_types.h"


void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_ROS_ControllerNiKi_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);


#endif
