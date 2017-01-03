#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_VesselSimulator_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_VesselSimulator_geometry_msgs_Vector3 const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_VesselSimulator_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_VesselSimulator_std_msgs_UInt16 and std_msgs::UInt16

void convert_from_bus(std_msgs::UInt16* msgPtr, SL_Bus_VesselSimulator_std_msgs_UInt16 const* busPtr)
{
  msgPtr->data =  busPtr->Data;
}

void convert_to_bus(SL_Bus_VesselSimulator_std_msgs_UInt16* busPtr, std_msgs::UInt16 const* msgPtr)
{
  busPtr->Data =  msgPtr->data;
}

