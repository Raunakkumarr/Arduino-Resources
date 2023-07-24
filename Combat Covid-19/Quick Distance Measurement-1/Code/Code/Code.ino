// covid-19 denis fournier 2020-05-02
// V 1.0

// Digital pins of arduino nano
int trig = 4, echo = 5, LedRed=7, LedYellow=8 , LedGreen=9;
long lecture_echo, cm;

void setup()
{
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  pinMode(LedRed,OUTPUT);
  pinMode(LedGreen,OUTPUT);
  pinMode(LedYellow,OUTPUT);  
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  cm = lecture_echo / 58;
  Serial.print("Distance en cm : ");
  Serial.println(cm);

  digitalWrite(LedRed,0);
  digitalWrite(LedYellow,0);
  digitalWrite(LedGreen,0);
  if (cm)
  {
      if (cm < 100)
         digitalWrite(LedRed,1);
      else
      {
          if (cm < 150)
              digitalWrite(LedYellow,1);
          else
              digitalWrite(LedGreen,1);
      }
  }
  else
     digitalWrite(LedGreen,1);
  delay(100);
}
