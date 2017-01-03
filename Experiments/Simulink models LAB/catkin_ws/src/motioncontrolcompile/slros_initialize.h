#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic_pubsub.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block MotionControlCompile/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_MotionControlCompile_geometry_msgs_Vector3> Sub_MotionControlCompile_659;

// For Block MotionControlCompile/Subsystem1/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_MotionControlCompile_geometry_msgs_Vector3> Sub_MotionControlCompile_652;

// For Block MotionControlCompile/UOUT/Subscribe2
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_MotionControlCompile_std_msgs_Bool> Sub_MotionControlCompile_892;

// For Block MotionControlCompile/NonlinearPassiveObs/NuOut/Publish3
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_MotionControlCompile_geometry_msgs_Vector3> Pub_MotionControlCompile_779;

// For Block MotionControlCompile/NonlinearPassiveObs/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_MotionControlCompile_std_msgs_Float64> Pub_MotionControlCompile_888;

// For Block MotionControlCompile/UOUT/Publish1
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_MotionControlCompile_std_msgs_UInt16> Pub_MotionControlCompile_701;

// For Block MotionControlCompile/UOUT/Publish2
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_MotionControlCompile_std_msgs_UInt16> Pub_MotionControlCompile_702;

// For Block MotionControlCompile/UOUT/Publish3
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_MotionControlCompile_std_msgs_UInt16> Pub_MotionControlCompile_703;

// For Block MotionControlCompile/aout/Publish1
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_MotionControlCompile_std_msgs_UInt16> Pub_MotionControlCompile_736;

// For Block MotionControlCompile/aout/Publish2
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_MotionControlCompile_std_msgs_UInt16> Pub_MotionControlCompile_737;

// For Block MotionControlCompile/aout/Publish3
extern SimulinkPublisher<std_msgs::UInt16, SL_Bus_MotionControlCompile_std_msgs_UInt16> Pub_MotionControlCompile_738;

void slros_node_init(int argc, char** argv);

#endif
