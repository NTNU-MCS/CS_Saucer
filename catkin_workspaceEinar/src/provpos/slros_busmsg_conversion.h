#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include "provPos_types.h"


void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_provPos_std_msgs_Float64 const* busPtr);
void convert_to_bus(SL_Bus_provPos_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);


#endif
