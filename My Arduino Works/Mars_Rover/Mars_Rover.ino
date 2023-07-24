 //For Servo Motor
#include <Servo.h>  //Includes Servo Library
int servoPin = 5;   //Declares the Servo Pin
Servo RaunakServo;  //Creates Servo Object

//For Ultrasonic Sensor
const int trigPin = 11;
const int echoPin = 10;

//For Motor Driver
const int in1 = 8;
const int in2 = 9;
const int in3 = 4;
const int in4 = 3;

void setup()
{
  //For Servo Motor
  RaunakServo.attach(5);
  
  //For Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //For Motor Driver
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
}
long duration, distance1, distance2, distance3;
void loop()
{
  RaunakServo.write(0);  //Makes Servo go to 0 degrees
  delay(1000);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance1 = duration/58.2;
  if(distance1>30) //Move Forward
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
else       //Turns Left
  {
    RaunakServo.write(90);  //Makes Servo go to 90 degrees
    delay(1000);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(8);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance2 = duration/58.2;
    if(distance2>30)//Move Left
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else     //Turns Right
    {
      RaunakServo.write(270);  //Makes Servo go to 90 degrees
      delay(1000);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(3);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(8);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance3 = duration/58.2;
      if(distance3>30)   //Moves Right
      {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
      }
      else   //Moves Backward
      {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      }
    }
  } 
}
