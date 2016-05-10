#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_provPos_std_msgs_Float64 and std_msgs::Float64

void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_provPos_std_msgs_Float64 const* busPtr)
{
  msgPtr->data =  busPtr->Data;
}

void convert_to_bus(SL_Bus_provPos_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr)
{
  busPtr->Data =  msgPtr->data;
}

