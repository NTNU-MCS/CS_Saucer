#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_Q2P2_geometry_msgs_Point and geometry_msgs::Point

void convert_from_bus(geometry_msgs::Point* msgPtr, SL_Bus_Q2P2_geometry_msgs_Point const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_Q2P2_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Q2P2_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convert_from_bus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Q2P2_geometry_msgs_Quaternion const* busPtr)
{
  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_Q2P2_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Q2P2_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convert_from_bus(geometry_msgs::Vector3* msgPtr, SL_Bus_Q2P2_geometry_msgs_Vector3 const* busPtr)
{
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convert_to_bus(SL_Bus_Q2P2_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Q2P2_qualisys_Marker and qualisys::Marker

void convert_from_bus(qualisys::Marker* msgPtr, SL_Bus_Q2P2_qualisys_Marker const* busPtr)
{
  {
    const int numItemsToCopy = busPtr->Name_SL_Info.CurrentLength;
    msgPtr->name.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->name[i] =  busPtr->Name[i];
    }
  }
  msgPtr->occluded =  busPtr->Occluded;
  convert_from_bus(&msgPtr->position, &busPtr->Position);
  {
    const int numItemsToCopy = busPtr->SubjectName_SL_Info.CurrentLength;
    msgPtr->subject_name.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->subject_name[i] =  busPtr->SubjectName[i];
    }
  }
}

void convert_to_bus(SL_Bus_Q2P2_qualisys_Marker* busPtr, qualisys::Marker const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->name.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("Q2P2", "Truncating array '%s' in received message '%s' from %d to %d items", "name", "qualisys/Marker", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->Name_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Name[i] = (uint8_T) msgPtr->name[i];
    }
  }
  busPtr->Occluded =  msgPtr->occluded;
  convert_to_bus(&busPtr->Position, &msgPtr->position);
  {
    int numItemsToCopy = msgPtr->subject_name.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("Q2P2", "Truncating array '%s' in received message '%s' from %d to %d items", "subject_name", "qualisys/Marker", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->SubjectName_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->SubjectName[i] = (uint8_T) msgPtr->subject_name[i];
    }
  }
}


// Conversions between SL_Bus_Q2P2_qualisys_Subject and qualisys::Subject

void convert_from_bus(qualisys::Subject* msgPtr, SL_Bus_Q2P2_qualisys_Subject const* busPtr)
{
  convert_from_bus(&msgPtr->header, &busPtr->Header);
  {
    const int numItemsToCopy = busPtr->Markers_SL_Info.CurrentLength;
    msgPtr->markers.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_from_bus(&msgPtr->markers[i], &busPtr->Markers[i]);
    }
  }
  {
    const int numItemsToCopy = busPtr->Name_SL_Info.CurrentLength;
    msgPtr->name.resize(numItemsToCopy);
    for (int i=0; i < numItemsToCopy; i++)
    {
      msgPtr->name[i] =  busPtr->Name[i];
    }
  }
  msgPtr->occluded =  busPtr->Occluded;
  convert_from_bus(&msgPtr->orientation, &busPtr->Orientation);
  convert_from_bus(&msgPtr->position, &busPtr->Position);
}

void convert_to_bus(SL_Bus_Q2P2_qualisys_Subject* busPtr, qualisys::Subject const* msgPtr)
{
  convert_to_bus(&busPtr->Header, &msgPtr->header);
  {
    int numItemsToCopy = msgPtr->markers.size();
    if (numItemsToCopy > 16)
    {
      ROS_WARN_NAMED("Q2P2", "Truncating array '%s' in received message '%s' from %d to %d items", "markers", "qualisys/Subject", numItemsToCopy, 16);
      numItemsToCopy = 16;
    }
    busPtr->Markers_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      convert_to_bus(&busPtr->Markers[i], &msgPtr->markers[i]);
    }
  }
  {
    int numItemsToCopy = msgPtr->name.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("Q2P2", "Truncating array '%s' in received message '%s' from %d to %d items", "name", "qualisys/Subject", numItemsToCopy, 128);
      numItemsToCopy = 128;
    }
    busPtr->Name_SL_Info.CurrentLength = static_cast<uint32_T>( numItemsToCopy );
    for (int i=0; i < numItemsToCopy; i++)
    {
      busPtr->Name[i] = (uint8_T) msgPtr->name[i];
    }
  }
  busPtr->Occluded =  msgPtr->occluded;
  convert_to_bus(&busPtr->Orientation, &msgPtr->orientation);
  convert_to_bus(&busPtr->Position, &msgPtr->position);
}


// Conversions between SL_Bus_Q2P2_ros_time_Time and ros::Time

void convert_from_bus(ros::Time* msgPtr, SL_Bus_Q2P2_ros_time_Time const* busPtr)
{
  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convert_to_bus(SL_Bus_Q2P2_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_Q2P2_std_msgs_Header and std_msgs::Header

void convert_from_bus(std_msgs::Header* msgPtr, SL_Bus_Q2P2_std_msgs_Header const* busPtr)
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

void convert_to_bus(SL_Bus_Q2P2_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  {
    int numItemsToCopy = msgPtr->frame_id.size();
    if (numItemsToCopy > 128)
    {
      ROS_WARN_NAMED("Q2P2", "Truncating array '%s' in received message '%s' from %d to %d items", "frame_id", "std_msgs/Header", numItemsToCopy, 128);
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

