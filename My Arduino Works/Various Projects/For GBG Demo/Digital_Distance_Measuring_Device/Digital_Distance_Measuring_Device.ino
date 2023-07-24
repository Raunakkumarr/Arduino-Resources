//*Created By Agkiya Infotech
//*Digital Distance Measuring Device  
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
// defines variables
long duration;
float distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
lcd.begin(16,2);   //Displays Status on LCD
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Distance:");
lcd.setCursor(1,1);
lcd.print(distance);
}
