#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray and std_msgs::Float32MultiArray

void convert_from_bus(std_msgs::Float32MultiArray* msgPtr, SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Data_SL_Info.CurrentLength;
    msgPtr->data.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->data[i] =  busPtr->Data[i];
    }
  }
  convert_from_bus(&msgPtr->layout, &busPtr->Layout);
}

void convert_to_bus(SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray* busPtr, std_msgs::Float32MultiArray const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->data.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("etasetget256Discretized2", "Truncating array '%s' in received message '%s' from %d to %d items", "data", "std_msgs/Float32MultiArray", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->Data_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Data[i] =  msgPtr->data[i];
    }
  }
  convert_to_bus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_etasetget256Discretized2_std_msgs_Float64 and std_msgs::Float64

void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_etasetget256Discretized2_std_msgs_Float64 const* busPtr)
{
  msgPtr->data =  busPtr->Data;
}

void convert_to_bus(SL_Bus_etasetget256Discretized2_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr)
{
  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo and std_msgs::MultiArrayDimension

void convert_from_bus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Label_SL_Info.CurrentLength;
    msgPtr->label.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->label[i] =  busPtr->Label[i];
    }
  }
  msgPtr->size =  busPtr->Size;
  msgPtr->stride =  busPtr->Stride;
}

void convert_to_bus(SL_Bus_etasetget256Discretized2_MultiArrayDimension_ni5sxo* busPtr, std_msgs::MultiArrayDimension const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->label.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("etasetget256Discretized2", "Truncating array '%s' in received message '%s' from %d to %d items", "label", "std_msgs/MultiArrayDimension", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->Label_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Label[i] = (uint8_T) msgPtr->label[i];
    }
  }
  busPtr->Size =  msgPtr->size;
  busPtr->Stride =  msgPtr->stride;
}


// Conversions between SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout and std_msgs::MultiArrayLayout

void convert_from_bus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout const* busPtr)
{
  msgPtr->data_offset =  busPtr->DataOffset;
  {
    const int numItemsToCopy = busPtr->Dim_SL_Info.CurrentLength;
    msgPtr->dim.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_from_bus(&msgPtr->dim[i], &busPtr->Dim[i]);
    }
  }
}

void convert_to_bus(SL_Bus_etasetget256Discretized2_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr)
{
  busPtr->DataOffset =  msgPtr->data_offset;
  {
    int numItemsToCopy = msgPtr->dim.size();
    if (numItemsToCopy > 16)
    {
      ROS_WARN_NAMED("etasetget256Discretized2", "Truncating array '%s' in received message '%s' from %d to %d items", "dim", "std_msgs/MultiArrayLayout", numItemsToCopy, 16);
      numItemsToCopy = 16;
    }
    busPtr->Dim_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_to_bus(&busPtr->Dim[i], &msgPtr->dim[i]);
    }
  }
}

