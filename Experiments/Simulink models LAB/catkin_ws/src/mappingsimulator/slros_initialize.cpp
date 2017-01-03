#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "MappingSimulator";

// For Block MappingSimulator/Subscribe
SimulinkSubscriber<nav_msgs::OccupancyGrid, SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid> Sub_MappingSimulator_4;

// For Block MappingSimulator/Subsystem1/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_MappingSimulator_geometry_msgs_Vector3> Sub_MappingSimulator_57;

// For Block MappingSimulator/Subsystem1/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_MappingSimulator_std_msgs_Float64> Pub_MappingSimulator_77;

// For Block MappingSimulator/Subsystem1/Publish2
SimulinkPublisher<nav_msgs::OccupancyGrid, SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid> Pub_MappingSimulator_37;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

