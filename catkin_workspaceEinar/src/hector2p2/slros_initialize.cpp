#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Hector2P2";

// For Block Hector2P2/Subscribe2
SimulinkSubscriber<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_Hector2P2_geometry_msgs_PoseWithCovarianceStamped> Sub_Hector2P2_82;

// For Block Hector2P2/Subsystem1/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_Hector2P2_geometry_msgs_Vector3> Sub_Hector2P2_89;

// For Block Hector2P2/Eta/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_Hector2P2_geometry_msgs_Vector3> Pub_Hector2P2_73;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

