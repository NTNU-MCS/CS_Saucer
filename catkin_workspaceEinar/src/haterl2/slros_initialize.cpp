#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "HaterL2";

// For Block HaterL2/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_HaterL2_std_msgs_Float64> Sub_HaterL2_2;

// For Block HaterL2/Out/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL2_std_msgs_Float64> Pub_HaterL2_3;

// For Block HaterL2/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_HaterL2_std_msgs_Float64> Pub_HaterL2_15;

// For Block HaterL2/Set Parameter
SimulinkParameterSetter<real64_T, double> ParamSet_HaterL2_16;

// For Block HaterL2/Set Parameter1
SimulinkParameterSetter<real64_T, double> ParamSet_HaterL2_19;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

