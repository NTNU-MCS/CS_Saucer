#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <udrone/TutorialsConfig.h>

void callback(udrone::TutorialsConfig &config, uint32_t level) {
    ros::NodeHandle n;
//    n.setParam("/thrustAllocation/K1m",config.K1m);
//    n.setParam("/thrustAllocation/K2m",config.K2m);
//    n.setParam("/thrustAllocation/K3m",config.K3m);
//    n.setParam("/thrustAllocation/K4m",config.K4m);
//    n.setParam("/thrustAllocation/K5m",config.K5m);
//    n.setParam("/thrustAllocation/K6m",config.K6m);

//    n.setParam("/thrustAllocation/K1p",config.K1p);
//    n.setParam("/thrustAllocation/K2p",config.K2p);
//    n.setParam("/thrustAllocation/K3p",config.K3p);
//    n.setParam("/thrustAllocation/K4p",config.K4p);
//    n.setParam("/thrustAllocation/K5p",config.K5p);
//    n.setParam("/thrustAllocation/K6p",config.K5p);

    n.setParam("/autoDepthControl/K1",config.K1);
    n.setParam("/autoDepthControl/K2",config.K2);
    n.setParam("/autoDepthControl/K3",config.K3);
    n.setParam("/autoDepthControl/L1",config.L1);
    n.setParam("/autoDepthControl/L2",config.L2);

    n.setParam("/autoHeadingControl/Kp",config.Kp_h);
    n.setParam("/autoHeadingControl/Ki",config.Ki_h);
    n.setParam("/autoHeadingControl/Kd",config.Kd_h);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "parameterChange");
  dynamic_reconfigure::Server<udrone::TutorialsConfig> server;
  dynamic_reconfigure::Server<udrone::TutorialsConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ros::spin();
  return 0;
}

