void setup() 
{
  
  pinMode(10, OUTPUT);
}


void loop() 
{
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10000);
                       // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
