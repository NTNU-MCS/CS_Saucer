#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <qualisys/Marker.h>
#include <qualisys/Subject.h>
#include <ros/time.h>
#include <std_msgs/Header.h>
#include "Q2PAll_types.h"


void convert_from_bus(geometry_msgs::Point* msgPtr, SL_Bus_Q2PAll_geometry_msgs_Point const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convert_from_bus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Q2PAll_geometry_msgs_Quaternion const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_Q2PAll_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convert_from_bus(qualisys::Marker* msgPtr, SL_Bus_Q2PAll_qualisys_Marker const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_qualisys_Marker* busPtr, qualisys::Marker const* msgPtr);

void convert_from_bus(qualisys::Subject* msgPtr, SL_Bus_Q2PAll_qualisys_Subject const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_qualisys_Subject* busPtr, qualisys::Subject const* msgPtr);

void convert_from_bus(ros::Time* msgPtr, SL_Bus_Q2PAll_ros_time_Time const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_Q2PAll_std_msgs_Header const* busPtr);
void convert_to_bus(SL_Bus_Q2PAll_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
