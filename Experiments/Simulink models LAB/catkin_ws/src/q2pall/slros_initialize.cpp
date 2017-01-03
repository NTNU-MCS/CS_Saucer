#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Q2PAll";

// For Block Q2PAll/Subscribe2
SimulinkSubscriber<qualisys::Subject, SL_Bus_Q2PAll_qualisys_Subject> Sub_Q2PAll_82;

// For Block Q2PAll/Eta/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Q2PAll_geometry_msgs_Vector3> Pub_Q2PAll_73;

// For Block Q2PAll/EulerAng/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Q2PAll_geometry_msgs_Vector3> Pub_Q2PAll_100;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

