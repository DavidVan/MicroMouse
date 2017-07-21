#include <AccelStepper.h>
#define HALFSTEP 8

//initialize motor pins for both motors

  //initialize Motor 1
  #define motor1PinA 4
  #define motor1PinB 5
  #define motor1PinC 6
  #define motor1PinD 7

  //initialize Motor 2
  #define motor2PinA 10
  #define motor2PinB 11
  #define motor2PinC 12 
  #define motor2PinD 13

  //initialize Ultrasonic Sensor 1
  #define ursEcho1 8
  #define ursTrig1 9

  //initialize Ultrasonic Sensor 2
  #define ursEcho2 10 
  #define ursTrig2 11

  //initialize Ultrasonic Sensor 3
  #define ursEcho3 22
  #define ursTrig3 23

  //initialize Stepper Motor 
  AccelStepper stepper1(HALFSTEP, motor1PinA, motor1PinB, motor1PinC, motor1PinD);
  AccelStepper stepper2(HALFSTEP, motor2PinB, motor2PinB, motor2PinC, motor2PinD);

void setup() {
  Serial.begin(9600);
  
  //Intialize veriables 
  int MaxSpeed = 6000;
  int SetSpeed = 4000;
  int blockDistance = 3000;
  
  //Intialize pin mode for the first sensor
  pinMode(ursEcho1, INPUT);
  pinMode(ursTrig1, OUTPUT);
  
  //Intialize pin mode for the second sesnor
  pinMode(ursEcho2, INPUT);
  pinMode(ursTrig2, OUTPUT);
  
  //Intialize pin mode foor the third sensor
  pinMode(ursEcho3, INPUT);
  pinMode(ursTrig3, OUTPUT);

  //Intialize stepper speeds 
  stepper1.setMaxSpeed(MaxSpeed);
  stepper1.setSpeed(SetSpeed);
  stepper2.setMaxSpeed(Maxspeed);
  stepper2.setSpeed(SetSpeed);

}

void loop() {

   // Ultrasonic Sensor Signal Setup
  long duration1, distance1, duration2, distance2, duration3, distance3;
  digitalWrite(ursTrig1, LOW);
  delayMicroseconds(2);
  digitalWrite(ursTrig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(ursTrig1,LOW);
  duration1 = pulseIn(ursEcho1, HIGH);
  distance1 = duration1/29.1;
  digitalWrite(ursTrig2, LOW);
  delayMicroseconds(2);
  digitalWrite(ursTrig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(ursTrig2,LOW);
  duration2 = pulseIn(ursEcho2, HIGH);
  distance2 = duration2/29.1;
  digitalWrite(ursTrig3, LOW);
  delayMicroseconds(2);
  digitalWrite(ursTrig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(ursTrig3,LOW);
  duration3 = pulseIn(ursEcho3, HIGH);
  distance3 = duration3/29.1;

  //Sensor Readings 
  Serial.print(distance1);
  Serial.print("\n");
  Serial.print(distance2);
  Serial.print("\n");

  stepper1.run();
  stepper2.run();
  
  

}
