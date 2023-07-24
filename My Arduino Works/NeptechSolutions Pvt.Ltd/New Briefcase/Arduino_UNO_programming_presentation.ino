int LedPin = 13;
void setup() 
{
  pinMode(LedPin,OUTPUT);// put your setup code here, to run once:
}

void loop() 
 {
digitalWrite(LedPin,HIGH);// put your main code here, to run repeatedly:
delay(1000);
digitalWrite(LedPin,LOW);
delay(1000);
 }
