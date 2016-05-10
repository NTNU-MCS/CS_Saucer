#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "VesselSimulator";

// For Block VesselSimulator/Subsystem/Subscribe1
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_VesselSimulator_geometry_msgs_Vector3> Sub_VesselSimulator_22;

// For Block VesselSimulator/U out1/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_VesselSimulator_geometry_msgs_Vector3> Pub_VesselSimulator_269;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

