#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_mindistfromscan2_ros_time_Time and ros::Time

void convert_from_bus(ros::Time* msgPtr, SL_Bus_mindistfromscan2_ros_time_Time const* busPtr)
{
  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convert_to_bus(SL_Bus_mindistfromscan2_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_mindistfromscan2_sensor_msgs_LaserScan and sensor_msgs::LaserScan

void convert_from_bus(sensor_msgs::LaserScan* msgPtr, SL_Bus_mindistfromscan2_sensor_msgs_LaserScan const* busPtr)
{
  msgPtr->angle_increment =  busPtr->AngleIncrement;
  msgPtr->angle_max =  busPtr->AngleMax;
  msgPtr->angle_min =  busPtr->AngleMin;
  convert_from_bus(&msgPtr->header, &busPtr->Header);
  {
    const int numItemsToCopy = busPtr->Intensities_SL_Info.CurrentLength;
    msgPtr->intensities.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->intensities[i] =  busPtr->Intensities[i];
    }
  }
  msgPtr->range_max =  busPtr->RangeMax;
  msgPtr->range_min =  busPtr->RangeMin;
  {
    const int numItemsToCopy = busPtr->Ranges_SL_Info.CurrentLength;
    msgPtr->ranges.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->ranges[i] =  busPtr->Ranges[i];
    }
  }
  msgPtr->scan_time =  busPtr->ScanTime;
  msgPtr->time_increment =  busPtr->TimeIncrement;
}

void convert_to_bus(SL_Bus_mindistfromscan2_sensor_msgs_LaserScan* busPtr, sensor_msgs::LaserScan const* msgPtr)
{
  busPtr->AngleIncrement =  msgPtr->angle_increment;
  busPtr->AngleMax =  msgPtr->angle_max;
  busPtr->AngleMin =  msgPtr->angle_min;
  convert_to_bus(&busPtr->Header, &msgPtr->header);
  {
    int numItemsToCopy = msgPtr->intensities.size();
    if (numItemsToCopy > 360)
    {
      ROS_WARN_NAMED("mindistfromscan2", "Truncating array '%s' in received message '%s' from %d to %d items", "intensities", "sensor_msgs/LaserScan", numItemsToCopy, 360);
      numItemsToCopy = 360;
    }
    busPtr->Intensities_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Intensities[i] =  msgPtr->intensities[i];
    }
  }
  busPtr->RangeMax =  msgPtr->range_max;
  busPtr->RangeMin =  msgPtr->range_min;
  {
    int numItemsToCopy = msgPtr->ranges.size();
    if (numItemsToCopy > 360)
    {
      ROS_WARN_NAMED("mindistfromscan2", "Truncating array '%s' in received message '%s' from %d to %d items", "ranges", "sensor_msgs/LaserScan", numItemsToCopy, 360);
      numItemsToCopy = 360;
    }
    busPtr->Ranges_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Ranges[i] =  msgPtr->ranges[i];
    }
  }
  busPtr->ScanTime =  msgPtr->scan_time;
  busPtr->TimeIncrement =  msgPtr->time_increment;
}


// Conversions between SL_Bus_mindistfromscan2_std_msgs_Float32 and std_msgs::Float32

void convert_from_bus(std_msgs::Float32* msgPtr, SL_Bus_mindistfromscan2_std_msgs_Float32 const* busPtr)
{
  msgPtr->data =  busPtr->Data;
}

void convert_to_bus(SL_Bus_mindistfromscan2_std_msgs_Float32* busPtr, std_msgs::Float32 const* msgPtr)
{
  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_mindistfromscan2_std_msgs_Float64 and std_msgs::Float64

void convert_from_bus(std_msgs::Float64* msgPtr, SL_Bus_mindistfromscan2_std_msgs_Float64 const* busPtr)
{
  msgPtr->data =  busPtr->Data;
}

void convert_to_bus(SL_Bus_mindistfromscan2_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr)
{
  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_mindistfromscan2_std_msgs_Header and std_msgs::Header

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_mindistfromscan2_std_msgs_Header const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->FrameId_SL_Info.CurrentLength;
    msgPtr->frame_id.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->frame_id[i] =  busPtr->FrameId[i];
    }
  }
  msgPtr->seq =  busPtr->Seq;
  convert_from_bus(&msgPtr->stamp, &busPtr->Stamp);
}

void convert_to_bus(SL_Bus_mindistfromscan2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->frame_id.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("mindistfromscan2", "Truncating array '%s' in received message '%s' from %d to %d items", "frame_id", "std_msgs/Header", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->FrameId_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->FrameId[i] = (uint8_T) msgPtr->frame_id[i];
    }
  }
  busPtr->Seq =  msgPtr->seq;
  convert_to_bus(&busPtr->Stamp, &msgPtr->stamp);
}

