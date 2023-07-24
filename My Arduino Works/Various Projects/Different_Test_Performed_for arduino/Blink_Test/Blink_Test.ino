
//*Created By Agkiya infotech
//*Automatic Street Light

#define LDRpin A0 // pin where we connected the LDR and the resistor

int LDRValue = 0;     // result of reading the analog pin
void setup() 
{
  Serial.begin(9600); // sets serial port for communication
  pinMode(10, OUTPUT);
}


void loop() 
{
  LDRValue = analogRead(LDRpin); // read the value from the LDR
  Serial.println(LDRValue);      // print the value to the serial port
   if(LDRValue < 100)
 {
   Serial.println("LED light on");
   digitalWrite(10,HIGH);
   delay(1000);
 }
 digitalWrite(10,LOW);
 delay(LDRValue);      // put your main code here, to run repeatedly:

}
