#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/UInt16.h>
#include "VesselSimulator_types.h"


void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_VesselSimulator_geometry_msgs_Vector3 const* busPtr);
void convert_to_bus(SL_Bus_VesselSimulator_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convert_from_bus(std_msgs::UInt16* msgPtr, SL_Bus_VesselSimulator_std_msgs_UInt16 const* busPtr);
void convert_to_bus(SL_Bus_VesselSimulator_std_msgs_UInt16* busPtr, std_msgs::UInt16 const* msgPtr);


#endif
