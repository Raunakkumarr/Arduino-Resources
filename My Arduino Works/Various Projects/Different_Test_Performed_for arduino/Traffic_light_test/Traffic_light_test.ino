//*Created By Agkiya Infotech
//*Automatic Traffic Light

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(10, OUTPUT); // for red
  pinMode(11, OUTPUT); // for yellow
  pinMode(12, OUTPUT); // for green
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(20000);                       // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(11, HIGH);
  delay(5000);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(30000);
  digitalWrite(12, LOW);
}
