#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float64.h>
#include <std_msgs/UInt16.h>
#include "ROS_Controller_types.h"


void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_ROS_Controller_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_ROS_Controller_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convert_from_bus(std_msgs::Bool* msgPtr, SL_Bus_ROS_Controller_std_msgs_Bool const* busPtr);
void convert_to_bus(SL_Bus_ROS_Controller_std_msgs_Bool* busPtr, std_msgs::Bool const* msgPtr);

void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_ROS_Controller_std_msgs_Float64 const* busPtr);
void convert_to_bus(SL_Bus_ROS_Controller_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);

void convert_from_bus(std_msgs::UInt16* msgPtr, SL_Bus_ROS_Controller_std_msgs_UInt16 const* busPtr);
void convert_to_bus(SL_Bus_ROS_Controller_std_msgs_UInt16* busPtr, std_msgs::UInt16 const* msgPtr);


#endif
