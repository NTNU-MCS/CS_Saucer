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
#include <geometry_msgs/Vector3.h> //For battery and encoder

ros::NodeHandle  nh;

//std_msgs::Int64 enc_msg;
//ros::Publisher pub_enc("encoder", &enc_msg);
//std_msgs::Float32 bat_msg;
//ros::Publisher pub_bat("Battery", &bat_msg);

geometry_msgs::Vector3 batEnc_msg;
ros::Publisher pub_batEnc("BatteryAndEncoder", &batEnc_msg);


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
volatile unsigned int  encoder0Pos = 0;      //the encoder position variable.
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
  
  
//Encoder from here:  
nh.initNode(); // ROS node
nh.advertise(pub_batEnc); // Publisher

//encoder pinModes
pinMode(encoder0PinA, INPUT); 
 digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
pinMode(encoder0PinB, INPUT); 
 digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
//pinMode(encoder0PinC, INPUT); 
// digitalWrite(encoder0PinC, HIGH);       // turn on pullup resistor
 
// Only using one interrupt:
 attachInterrupt(0, doEncoder, CHANGE);  // encoder track A on interrupt 0 - pin 2
 //attachInterrupt(0, doIndex, RISING);        // encoder Index track on interupt 0 - pin 2
} 

void loop(){

  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // Multiply by number of cells:
  float sumVoltage = voltage*3;
  
     //Publish to ROS
      batEnc_msg.x = sumVoltage;
      batEnc_msg.y = encoder0Pos;
      pub_batEnc.publish(&batEnc_msg);
      nh.spinOnce();
       delay(10);                        //delay 10ms so that the screen does not flood
}
                                                         
void doEncoder(){                        //every time a change happens on encoder pin A doEncoder will run.
 
if (digitalRead(encoder0PinA) == HIGH) {         // found a low-to-high on channel A
   if (digitalRead(encoder0PinB) == LOW) {        // check channel B to see which way encoder is spinning
     ccw = true;                           // CCW
   } else {
     ccw = false;                          // CW
   }
 } else {                               //found a high-to-low on channel A
   if (digitalRead(encoder0PinB) == LOW) {      // check channel B to see which way encoder is spinning
     ccw = false;                            // CW
   } else {
     ccw = true;                            // CCW
   }
 }
  if (ccw == true){
  encoder0Pos = (encoder0Pos - 1);            //if encoder is spinning CCW subtract a count from encoder position
   if (encoder0Pos == -1){                  // if encoder position is equal to -1
   encoder0Pos = 4095;                         //make encoder position equal to 4096-1.
   turn = (turn - 1);      }                  //if concoder position is changed to 4096 subtract 1 from turns.
                                   //this keeps rolling over the encoder positions so that it never
                                   //gets below 0 counts
} else {
  encoder0Pos = (encoder0Pos + 1);            //if encoder is spinning CW add a count to encoder position
   if (encoder0Pos == 4096){                  // if encoder position is equal to 4096.
   encoder0Pos = 0;                         //make encoder position equal to 0. 
   turn = (turn + 1);      }                  //if concoder position is changed to 0 then add 1 to turns.
 }                                    //this keeps rolling over the encoder positions so that it never
}                                    //gets over 4096 counts

