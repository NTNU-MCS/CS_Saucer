#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "provPos";

// For Block provPos/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_provPos_std_msgs_Float64> Sub_provPos_2;

// For Block provPos/Out/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_provPos_std_msgs_Float64> Pub_provPos_3;

// For Block provPos/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_provPos_std_msgs_Float64> Pub_provPos_15;

// For Block provPos/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_provPos_20;

// For Block provPos/Set Parameter
SimulinkParameterSetter<real64_T, double> ParamSet_provPos_16;

// For Block provPos/Set Parameter1
SimulinkParameterSetter<real64_T, double> ParamSet_provPos_19;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

