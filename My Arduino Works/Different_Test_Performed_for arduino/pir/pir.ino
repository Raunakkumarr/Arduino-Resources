const int PIR_SENSOR_OUTPUT_PIN = 4;  /* PIR sensor O/P pin */
int warm_up;
int Buzzer = 2;

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600); /* Define baud rate for serial communication */
  delay(20000); /* Power On Warm Up Delay */
}

void loop() {
  int sensor_output;
  sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);
  if( sensor_output == LOW )
  {
    if( warm_up == 1 )
     {
      Serial.println("Warming Up\n\n");
      warm_up = 0;
    }
    Serial.println("No object in sight\n\n");
  }
  else
  {
    Serial.println("Object detected\n\n");
    digitalWrite(Buzzer, HIGH);
    delay(5000);
    digitalWrite(Buzzer, LOW);
    warm_up = 1;
  }  
}
