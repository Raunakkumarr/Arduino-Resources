






void setup() 
{
  
  pinMode(10, OUTPUT);
}


void loop() 
{
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);
                       // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(50);                      // wait for a second
}
