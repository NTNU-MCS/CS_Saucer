#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ArduinoSim";

// For Block ArduinoSim/PwmINn/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Sub_ArduinoSim_2;

// For Block ArduinoSim/PwmINn/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Sub_ArduinoSim_22;

// For Block ArduinoSim/PwmINn/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Sub_ArduinoSim_23;

// For Block ArduinoSim/U_out/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Pub_ArduinoSim_153;

// For Block ArduinoSim/U_out/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Pub_ArduinoSim_156;

// For Block ArduinoSim/U_out/Publish3
SimulinkPublisher<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Pub_ArduinoSim_158;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

