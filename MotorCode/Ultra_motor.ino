#include <AccelStepper.h>
#define HALFSTEP 8

// initialize the stepper library on pins 8 through 11:
#define motor1Pin1 4
#define motor1Pin2 5
#define motor1Pin3 6
#define motor1Pin4 7
#define motor2Pin1 10
#define motor2Pin2 11
#define motor2Pin3 12
#define motor2Pin4 13
#define ECHO1 3
#define TRIG1 2
#define ECHO2 9
#define TRIG2 8
#define ECHO3 23
#define TRIG3 22

//Initialize with pin sequence using AccelStepper
AccelStepper stepper1(HALFSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper stepper2(HALFSTEP, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);

void setup()
{
  Serial.begin(9600);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG2, OUTPUT);
  stepper1.setMaxSpeed(4000.0);
  stepper1.setSpeed(2000);
  stepper2.setMaxSpeed(4000.0);
  stepper2.setSpeed(2000);
}

void loop()
{
  // Ultrasonic
  long duration1, distance1, duration2, distance2;
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1,LOW);
  duration1 = pulseIn(ECHO1, HIGH);
  distance1 = duration1/29.1;
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2,LOW);
  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = duration2/29.1;
// Sensor One  
  if (distance1 > 100)
  {
  stepper1.runSpeed();
  }
  else if (distance1 <= 100 && distance1 > 60)
  {
  stepper1.setSpeed(2000);
  stepper1.runSpeed();
  }
  else if (distance1 <= 60 && distance1 > 20)
  {
  stepper1.setSpeed(1000);
  stepper1.runSpeed();
  }
  else if (distance1 <= 20)
  {
  stepper1.stop();
  }
// Sensor Two
  if (distance2 > 100)
  {
  stepper2.runSpeed();
  }
  else if (distance2 <= 100 && distance2 > 60)
  {
  stepper2.setSpeed(2000);
  stepper2.runSpeed();
  }
  else if (distance2 <= 60 && distance2 > 20)
  {
  stepper2.setSpeed(1000);
  stepper2.runSpeed();
  }
  else if (distance2 <= 20)
  {
  stepper2.stop();
  }
  Serial.print(distance1);
  Serial.print("\n");
  Serial.print(distance2);
  Serial.print("\n");
  stepper1.run();
  stepper2.run();
}
