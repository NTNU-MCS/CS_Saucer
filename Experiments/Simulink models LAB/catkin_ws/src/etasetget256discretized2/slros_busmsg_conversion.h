#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/MultiArrayLayout.h>
#include "etasetget256Discretized2_types.h"


void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convert_from_bus(std_msgs::Float32MultiArray* msgPtr, SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray const* busPtr);
void convert_to_bus(SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray* busPtr, std_msgs::Float32MultiArray const* msgPtr);

void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_etasetget256Discretized2_std_msgs_Float64 const* busPtr);
void convert_to_bus(SL_Bus_etasetget256Discretized2_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);

void convert_from_bus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo const* busPtr);
void convert_to_bus(SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo* busPtr, std_msgs::MultiArrayDimension const* msgPtr);

void convert_from_bus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout const* busPtr);
void convert_to_bus(SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr);


#endif
