#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <ros/time.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Header.h>
#include "mindistfromscan2_types.h"


void convert_from_bus(ros::Time* msgPtr, SL_Bus_mindistfromscan2_ros_time_Time const* busPtr);
void convert_to_bus(SL_Bus_mindistfromscan2_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convert_from_bus(sensor_msgs::LaserScan* msgPtr, SL_Bus_mindistfromscan2_sensor_msgs_LaserScan const* busPtr);
void convert_to_bus(SL_Bus_mindistfromscan2_sensor_msgs_LaserScan* busPtr, sensor_msgs::LaserScan const* msgPtr);

void convert_from_bus(std_msgs::Float32* msgPtr, SL_Bus_mindistfromscan2_std_msgs_Float32 const* busPtr);
void convert_to_bus(SL_Bus_mindistfromscan2_std_msgs_Float32* busPtr, std_msgs::Float32 const* msgPtr);

void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_mindistfromscan2_std_msgs_Float64 const* busPtr);
void convert_to_bus(SL_Bus_mindistfromscan2_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_mindistfromscan2_std_msgs_Header const* busPtr);
void convert_to_bus(SL_Bus_mindistfromscan2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
