/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
ros::NodeHandle  nh;

Servo Thrust1;
Servo Thrust2;
Servo Thrust3;
Servo a1;
Servo a2;
Servo a3;


int thrust1;

void Thrust1_cb( const std_msgs::UInt16& cmd_msg){
  
  Thrust1.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

void Thrust2_cb( const std_msgs::UInt16& cmd_msg){
  Thrust2.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

void Thrust3_cb( const std_msgs::UInt16& cmd_msg){
  Thrust3.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

void a1_cb( const std_msgs::UInt16& cmd_msg){
  a1.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

void a2_cb( const std_msgs::UInt16& cmd_msg){
  a2.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

void a3_cb( const std_msgs::UInt16& cmd_msg){
  a3.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

ros::Subscriber<std_msgs::UInt16> sub("Thrust1", Thrust1_cb);
ros::Subscriber<std_msgs::UInt16> sub_th2("Thrust2", Thrust2_cb);
ros::Subscriber<std_msgs::UInt16> sub_th3("Thrust3", Thrust3_cb);

ros::Subscriber<std_msgs::UInt16> sub_a1("a1", a1_cb);
ros::Subscriber<std_msgs::UInt16> sub_a2("a2", a2_cb);
ros::Subscriber<std_msgs::UInt16> sub_a3("a3", a3_cb);


void setup(){
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub_th2);
  nh.subscribe(sub_th3);
  
  nh.subscribe(sub_a1);
  nh.subscribe(sub_a2);
  nh.subscribe(sub_a3);

  

  Thrust1.attach(9); //attach it to pin 9
  Thrust2.attach(10); //attach it to pin 9
    Thrust3.attach(11); //attach it to pin 9
    
  a1.attach(3); //attach it to pin 9
  a2.attach(5); //attach it to pin 9
    a3.attach(6); //attach it to pin 9
  Thrust1.write(80); //set servo angle, should be from 0-180  
  Thrust2.write(80); //set servo angle, should be from 0-180  
  Thrust3.write(80); //set servo angle, should be from 0-180  


}

void loop(){
  nh.spinOnce();
  delay(1);
}
