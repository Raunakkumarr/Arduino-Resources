//Home security with door locking by Bluetooth////////
//******Coded by RAUNAK KUMAR*********
#include <Servo.h>  //Includes Servo Library
int servoPin = 5;   //Declares the Servo Pin
Servo RaunakServo;  //Creates Servo Object
void setup()
{
  RaunakServo.attach(5);
}
void loop()
{
  RaunakServo.write(0);  //Makes Servo go to 0 degrees
  delay(5000);
  RaunakServo.write(180);  //Makes Servo go to 90 degrees
  delay(1000);
}
