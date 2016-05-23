#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <avr/interrupt.h>
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int64.h> //64 Bit best with Matlab. rpm
#include <std_msgs/UInt16.h> //For servo
#include <std_msgs/Float32.h> //For battery
#include <geometry_msgs/Vector3.h> //For battery and rpm

ros::NodeHandle  nh;


geometry_msgs::Vector3 batRPM_msg;
ros::Publisher pub_batRPM("BatteryAndRPM", &batRPM_msg);


Servo Thrust1; //Force
Servo Thrust2; //Force
Servo Thrust3; //Force
Servo a1; //Azimuth angle
Servo a2; //Azimuth angle
Servo a3; //Azimuth angle


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

//RPM:
 volatile byte half_revolutions;

 unsigned int rpm;

 unsigned long timeold;



void setup(){ 
//Servo and thrust control:
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub_th2);
  nh.subscribe(sub_th3);
  
  nh.subscribe(sub_a1);
  nh.subscribe(sub_a2);
  nh.subscribe(sub_a3);

  

  Thrust1.attach(9); //attach it to pin 9
  Thrust2.attach(10); //attach it to pin 10
    Thrust3.attach(11); //attach it to pin 11
    
  a1.attach(3); //attach it to pin 3
  a2.attach(5); //attach it to pin 5
    a3.attach(6); //attach it to pin 6
  Thrust1.write(80); //set servo angle, should be from 0-180  
  Thrust2.write(80); //set servo angle, should be from 0-180  
  Thrust3.write(80); //set servo angle, should be from 0-180  
  
  //RPM:
   attachInterrupt(0, rpm_fun, RISING);

   half_revolutions = 0;
   rpm = 0;
   timeold = 0;
   
//ROS
nh.initNode(); // ROS node
nh.advertise(pub_batRPM); // Publisher
  
}  


void loop(){
//Battery:
  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // Multiply by number of cells:
  float sumVoltage = voltage*3;
  
//RPM:  
     if (half_revolutions >= 2) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
     rpm = 30*1000/(millis() - timeold)*half_revolutions;
     timeold = millis();
     half_revolutions = 0;
      
   }
  
     //Publish to ROS
      batRPM_msg.x = sumVoltage;
      batRPM_msg.y = rpm;
      pub_batRPM.publish(&batRPM_msg);
      nh.spinOnce();
       delay(1);                        //delay 10ms so that the screen does not flood
}

 void rpm_fun()
 {
   half_revolutions++;
   //Each rotation, this interrupt function is run twice
 }

//----------------------------------------------- 
                                                         

