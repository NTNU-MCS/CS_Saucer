#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "VesselSimulator";

// For Block VesselSimulator/Subsystem/Subscribe1
SimulinkSubscriber<std_msgs::UInt16, SL_Bus_VesselSimulator_std_msgs_UInt16> Sub_VesselSimulator_22;

// For Block VesselSimulator/Subsystem/Subscribe2
SimulinkSubscriber<std_msgs::UInt16, SL_Bus_VesselSimulator_std_msgs_UInt16> Sub_VesselSimulator_306;

// For Block VesselSimulator/Subsystem/Subscribe3
SimulinkSubscriber<std_msgs::UInt16, SL_Bus_VesselSimulator_std_msgs_UInt16> Sub_VesselSimulator_307;

// For Block VesselSimulator/U out1/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_VesselSimulator_geometry_msgs_Vector3> Pub_VesselSimulator_269;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

