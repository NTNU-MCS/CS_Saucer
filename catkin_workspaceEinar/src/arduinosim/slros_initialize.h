#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ArduinoSim/PwmINn/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Sub_ArduinoSim_2;

// For Block ArduinoSim/PwmINn/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Sub_ArduinoSim_22;

// For Block ArduinoSim/PwmINn/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Sub_ArduinoSim_23;

// For Block ArduinoSim/U_out/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Pub_ArduinoSim_153;

// For Block ArduinoSim/U_out/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Pub_ArduinoSim_156;

// For Block ArduinoSim/U_out/Publish3
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ArduinoSim_std_msgs_Float64> Pub_ArduinoSim_158;

void slros_node_init(int argc, char** argv);

#endif
