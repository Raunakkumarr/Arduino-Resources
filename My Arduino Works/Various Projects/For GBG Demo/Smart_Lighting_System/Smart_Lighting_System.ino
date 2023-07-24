//*Created By Agkiya Infotech
//*Smart Home Lighting
//Define pins for ultrasonic and Lights
int const trigPin = 10;
int const echoPin = 9;
int const lightPin = 2;
int const LightPin = 3;
void setup()
{
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  pinMode(lightPin, OUTPUT); // light pin is output to control light
  pinMode(LightPin, OUTPUT); // light pin is output to control light
}

void loop()
{
  // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration, distance;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH); 
  delay(2000);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  // if distance less than 10 meter and more than 0 (0 or less means over range) 
    if (distance <= 15 && distance >= 0) {
      // Lights On
      digitalWrite(lightPin, HIGH);
      digitalWrite(LightPin, HIGH);
    } else {
      // Lights off
      digitalWrite(lightPin, LOW);
      digitalWrite(LightPin, LOW);
    }
    // Waiting 60
    delayMicroseconds(2000);
}
