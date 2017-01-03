#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <avr/interrupt.h>
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int64.h> //64 Bit best with Matlab. Encoder
#include <std_msgs/UInt16.h> //For servo
#include <std_msgs/Float32.h> //For battery
#include <geometry_msgs/Twist.h> //For publishing

ros::NodeHandle  nh;

geometry_msgs::Twist vect_msg;
ros::Publisher pub_vect("BatterEncoderThrustRPM", &vect_msg);


// Acoustcs
geometry_msgs::Twist vect_msg_acu;
ros::Publisher pub_vect_acu("Acoustics", &vect_msg_acu);
int trigPin1 = 50; //Sensor Trip pin connected to Arduino pin 50, responsible for tripping all acoutstic sensors at once
int echoPin1 = 7; //Sensor Echo pin connected to Arduino pin 7 - Acoustic sensor #1
int trigPin2 = 51;
int echoPin2 = 8;
int trigPin3 = 52;
int echoPin3 = 12;
int trigPin4 = 53;
int echoPin4 = 13;
// free pwm-pins: 2,4
int timeout = 2*6000; // microsecounds before timeout. 2*6000μs -> 2*2m
float pingTime1;
float Distance1;
float pingTime2;
float Distance2;
float pingTime3;
float Distance3;
float pingTime4;
float Distance4;
float const SpeedofSound = 3.432 * pow(10, -2); // cm/μs in dry air and 20degC
//


Servo Thrust1; //Force
Servo Thrust2; //Force
Servo Thrust3; //Force
Servo a1; //Azimuth angle
Servo a2; //Azimuth angle
Servo a3; //Azimuth angle

#define encoder0PinA  2            //Quadrature Track A
#define encoder0PinB  4            //Quadrature Track B

int thrust1;
//encoder variables:
//volatile unsigned int  encoder0Pos = 0;      //the encoder position variable.
int turn = 0;                              //the total turns.
int ccw = false;                        //which direction the encoder is spinning.

//unsigned long time;

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

//RPM1:
 volatile byte half_revolutions1;

 unsigned int rpm1;

 unsigned long timeold1;
 
//RPM2:
 volatile byte half_revolutions2;

 unsigned int rpm2;

 unsigned long timeold2;
 
 //RPM3:
 volatile byte half_revolutions3;

 unsigned int rpm3;

 unsigned long timeold3;


void setup(){ 
// Acoustics
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
//

//Servo and thrust control:
  //pinMode(13, OUTPUT);
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
  
  //RPM1: pin 21
   attachInterrupt(2, rpm_fun1, RISING);

   half_revolutions1 = 0;
   rpm1 = 0;
   timeold1 = 0;  
   
   //RPM1: pin 20
   attachInterrupt(3, rpm_fun2, RISING);

   half_revolutions2 = 0;
   rpm2 = 0;
   timeold2 = 0;  
   
   //RPM1: pin 19
   attachInterrupt(4, rpm_fun3, RISING);

   half_revolutions3 = 0;
   rpm3 = 0;
   timeold3 = 0;  
  
//ROS
nh.initNode(); // ROS node
nh.advertise(pub_vect); // Publisher
nh.advertise(pub_vect_acu); // Publisher

// digitalWrite(encoder0PinC, HIGH);       // turn on pullup resistor
 
// Only using one interrupt:
// attachInterrupt(0, doEncoder, CHANGE);  // encoder track A on interrupt 0 - pin 2
 //attachInterrupt(0, doIndex, RISING);        // encoder Index track on interupt 0 - pin 2
} 

void loop(){
// Acoustics
  digitalWrite(trigPin1, LOW);                   //Set trigger pin low
  delayMicroseconds(2000);                      //Let signal settle
  digitalWrite(trigPin1, HIGH);                  //Set trigPin high
  delayMicroseconds(10);                        //Delay in high state
  digitalWrite(trigPin1, LOW);                   //ping has now been sent
  pingTime1 = pulseIn(echoPin1, HIGH,timeout);  //pingTime is presented in microceconds
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  Distance1 = pingTime1 * SpeedofSound / 2;     //cm

  digitalWrite(trigPin2, LOW);                   //Set trigger pin low
  delayMicroseconds(2000);                      //Let signal settle
  digitalWrite(trigPin2, HIGH);                  //Set trigPin high
  delayMicroseconds(10);                        //Delay in high state
  digitalWrite(trigPin2, LOW);                   //ping has now been sent
  pingTime2 = pulseIn(echoPin2, HIGH,timeout);  //pingTime is presented in microceconds
  Distance2 = pingTime2 * SpeedofSound / 2;     //cm
  
  digitalWrite(trigPin3, LOW);                   //Set trigger pin low
  delayMicroseconds(2000);                      //Let signal settle
  digitalWrite(trigPin3, HIGH);                  //Set trigPin high
  delayMicroseconds(10);                        //Delay in high state
  digitalWrite(trigPin3, LOW);                   //ping has now been sent
  pingTime3 = pulseIn(echoPin3, HIGH,timeout);  //pingTime is presented in microceconds
  Distance3 = pingTime3 * SpeedofSound / 2;     //cm

  digitalWrite(trigPin4, LOW);                   //Set trigger pin low
  delayMicroseconds(2000);                      //Let signal settle
  digitalWrite(trigPin4, HIGH);                  //Set trigPin high
  delayMicroseconds(10);                        //Delay in high state
  digitalWrite(trigPin4, LOW);                   //ping has now been sent
  pingTime4 = pulseIn(echoPin4, HIGH,timeout);  //pingTime is presented in microceconds
  Distance4 = pingTime4 * SpeedofSound / 2;     //cm
//

  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // Multiply by number of cells:
  float sumVoltage = voltage*3;
  
  
  //RPM1:  
     if (half_revolutions1 >= 2) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
     rpm1 = 30*1000/(millis() - timeold1)*half_revolutions1;
     timeold1 = millis();
     half_revolutions1 = 0;
      
   }
   
   //RPM2:  
     if (half_revolutions2 >= 2) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
     rpm2 = 30*1000/(millis() - timeold2)*half_revolutions2;
     timeold2 = millis();
     half_revolutions2 = 0;
      
   }
   
   //RPM3:  
     if (half_revolutions3 >= 2) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
     rpm3 = 30*1000/(millis() - timeold3)*half_revolutions3;
     timeold3 = millis();
     half_revolutions3 = 0;
      
   }
  
     //Publish to ROS
      vect_msg.linear.x = sumVoltage;
      vect_msg.linear.y = 0;
      vect_msg.linear.z =0;
      vect_msg.angular.x = rpm1;
      vect_msg.angular.y = rpm2;
      vect_msg.angular.z = rpm3;
      pub_vect.publish(&vect_msg);
      nh.spinOnce();
      delay(1);                        //delay 1ms so that the screen does not flood

      // Publish acoustics to ROS
      vect_msg_acu.linear.x = Distance1;
      vect_msg_acu.linear.y = Distance2;
      vect_msg_acu.linear.z = Distance3;
      vect_msg_acu.angular.x = Distance4;
      vect_msg_acu.angular.y = 0;
      vect_msg_acu.angular.z = 0;
      pub_vect_acu.publish(&vect_msg_acu);
      nh.spinOnce();
      delay(1);                        //delay 1ms so that the screen does not flood
}
          

//RPM1
 void rpm_fun1()
 {
   half_revolutions1++;
   //Each rotation, this interrupt function is run twice
 }
 
//RPM2
 void rpm_fun2()
 {
   half_revolutions2++;
   //Each rotation, this interrupt function is run twice
 }
 
//RPM2
 void rpm_fun3()
 {
   half_revolutions3++;
   //Each rotation, this interrupt function is run twice
 }
