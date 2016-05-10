#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <ros/time.h>
#include <std_msgs/Header.h>
#include "Hector2P2_types.h"


void convert_from_bus(geometry_msgs::Point* msgPtr, SL_Bus_Hector2P2_geometry_msgs_Point const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convert_from_bus(geometry_msgs::Pose* msgPtr, SL_Bus_Hector2P2_geometry_msgs_Pose const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr);

void convert_from_bus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_Hector2P2_geometry_msgs_PoseWithCovariance const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr);

void convert_from_bus(geometry_msgs::PoseWithCovarianceStamped* msgPtr, SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped* busPtr, geometry_msgs::PoseWithCovarianceStamped const* msgPtr);

void convert_from_bus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Hector2P2_geometry_msgs_Quaternion const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_Hector2P2_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convert_from_bus(ros::Time* msgPtr, SL_Bus_Hector2P2_ros_time_Time const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_Hector2P2_std_msgs_Header const* busPtr);
void convert_to_bus(SL_Bus_Hector2P2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
