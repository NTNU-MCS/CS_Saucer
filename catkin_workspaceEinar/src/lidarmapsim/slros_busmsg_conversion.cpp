#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_LidarMapSim_geometry_msgs_Point and geometry_msgs::Point

void convert_from_bus(geometry_msgs::Point* msgPtr, SL_Bus_LidarMapSim_geometry_msgs_Point const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_LidarMapSim_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_LidarMapSim_geometry_msgs_Pose and geometry_msgs::Pose

void convert_from_bus(geometry_msgs::Pose* msgPtr, SL_Bus_LidarMapSim_geometry_msgs_Pose const* busPtr)
{
  convert_from_bus(&msgPtr->orientation, &busPtr->Orientation);
  convert_from_bus(&msgPtr->position, &busPtr->Position);
}

void convert_to_bus(SL_Bus_LidarMapSim_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr)
{
  convert_to_bus(&busPtr->Orientation, &msgPtr->orientation);
  convert_to_bus(&busPtr->Position, &msgPtr->position);
}


// Conversions between SL_Bus_LidarMapSim_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convert_from_bus(geometry_msgs::Quaternion* msgPtr, SL_Bus_LidarMapSim_geometry_msgs_Quaternion const* busPtr)
{
  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_LidarMapSim_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_LidarMapSim_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_LidarMapSim_geometry_msgs_Vector3 const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_LidarMapSim_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_LidarMapSim_nav_msgs_MapMetaData and nav_msgs::MapMetaData

void convert_from_bus(nav_msgs::MapMetaData* msgPtr, SL_Bus_LidarMapSim_nav_msgs_MapMetaData const* busPtr)
{
  msgPtr->height =  busPtr->Height;
  convert_from_bus(&msgPtr->map_load_time, &busPtr->MapLoadTime);
  convert_from_bus(&msgPtr->origin, &busPtr->Origin);
  msgPtr->resolution =  busPtr->Resolution;
  msgPtr->width =  busPtr->Width;
}

void convert_to_bus(SL_Bus_LidarMapSim_nav_msgs_MapMetaData* busPtr, nav_msgs::MapMetaData const* msgPtr)
{
  busPtr->Height =  msgPtr->height;
  convert_to_bus(&busPtr->MapLoadTime, &msgPtr->map_load_time);
  convert_to_bus(&busPtr->Origin, &msgPtr->origin);
  busPtr->Resolution =  msgPtr->resolution;
  busPtr->Width =  msgPtr->width;
}


// Conversions between SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid and nav_msgs::OccupancyGrid

void convert_from_bus(nav_msgs::OccupancyGrid* msgPtr, SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Data_SL_Info.CurrentLength;
    msgPtr->data.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->data[i] =  busPtr->Data[i];
    }
  }
  convert_from_bus(&msgPtr->header, &busPtr->Header);
  convert_from_bus(&msgPtr->info, &busPtr->Info);
}

void convert_to_bus(SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid* busPtr, nav_msgs::OccupancyGrid const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->data.size();
    if (numItemsToCopy > 16384)
    {
      ROS_WARN_NAMED("LidarMapSim", "Truncating array '%s' in received message '%s' from %d to %d items", "data", "nav_msgs/OccupancyGrid", numItemsToCopy, 16384);
      numItemsToCopy = 16384;
    }
    busPtr->Data_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Data[i] =  msgPtr->data[i];
    }
  }
  convert_to_bus(&busPtr->Header, &msgPtr->header);
  convert_to_bus(&busPtr->Info, &msgPtr->info);
}


// Conversions between SL_Bus_LidarMapSim_ros_time_Time and ros::Time

void convert_from_bus(ros::Time* msgPtr, SL_Bus_LidarMapSim_ros_time_Time const* busPtr)
{
  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convert_to_bus(SL_Bus_LidarMapSim_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_LidarMapSim_std_msgs_Header and std_msgs::Header

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_LidarMapSim_std_msgs_Header const* busPtr)
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

void convert_to_bus(SL_Bus_LidarMapSim_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->frame_id.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("LidarMapSim", "Truncating array '%s' in received message '%s' from %d to %d items", "frame_id", "std_msgs/Header", numItemsToCopy, 128);
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

