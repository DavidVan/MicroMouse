#include <AccelStepper.h>
#define HALFSTEP 8

//initialize motor pins for both motors

  //initialize Motor 1(Left)
  #define motor1PinA 41
  #define motor1PinB 39
  #define motor1PinC 37
  #define motor1PinD 35

  //initialize Motor 2(Right)
  #define motor2PinA 43
  #define motor2PinB 45
  #define motor2PinC 47
  #define motor2PinD 49

  //initialize Ultrasonic Sensor 1(Left Sensor)
  #define ursEcho1 9
  #define ursTrig1 8

  //initialize Ultrasonic Sensor 2 (Front Sensor)
  #define ursEcho2 23 
  #define ursTrig2 22

  //initialize Ultrasonic Sensor 3(Right Sensor)
  #define ursEcho3 3
  #define ursTrig3 2

  //initialize Stepper Motor 
  AccelStepper LeftStepper(HALFSTEP, motor1PinA, motor1PinB, motor1PinC, motor1PinD);
  AccelStepper RightStepper(HALFSTEP, motor2PinB, motor2PinB, motor2PinC, motor2PinD);

  long duration1, left, duration2, front, duration3, right;

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
  LeftStepper.setMaxSpeed(MaxSpeed);
  LeftStepper.setSpeed(SetSpeed);
  RightStepper.setMaxSpeed(MaxSpeed);
  RightStepper.setSpeed(SetSpeed);

}

void loop() {

  //read all sensors
  readSensors();

  //Sensor Readings 
  //Serial.print(left);
  //Serial.print("\n");
  Serial.print(front);
  Serial.print("\n");
  //Serial.print(right);
  //Serial.print("\n");


//Left Corner Test
if (front > 3)
  {
    RightStepper.moveTo(50);
    LeftStepper.moveTo(50);
  }
else
  {
    LeftStepper.moveTo(50);
    RightStepper.moveTo(-50);
  }

}

void readSensors()
{
  // Ultrasonic Sensor Signal Setup
  digitalWrite(ursTrig1, LOW);
  delayMicroseconds(2);
  digitalWrite(ursTrig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(ursTrig1,LOW);
  duration1 = pulseIn(ursEcho1, HIGH);
  left = duration1/29.1;
  
  digitalWrite(ursTrig2, LOW);
  delayMicroseconds(2);
  digitalWrite(ursTrig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(ursTrig2,LOW);
  duration2 = pulseIn(ursEcho2, HIGH);
  front = duration2/29.1;
  
  digitalWrite(ursTrig3, LOW);
  delayMicroseconds(2);
  digitalWrite(ursTrig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(ursTrig3,LOW);
  duration3 = pulseIn(ursEcho3, HIGH);
  right = duration3/29.1;
  
}
