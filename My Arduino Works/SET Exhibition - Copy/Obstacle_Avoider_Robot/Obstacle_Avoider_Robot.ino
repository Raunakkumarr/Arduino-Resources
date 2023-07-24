                                     
//for right sensor
const int right_trigPin = 11;
const int right_echoPin = 10;

//for left sensor
const int left_trigPin = 12;
const int left_echoPin = 13;

const int in1 = 8;
const int in2 = 9;
const int in3 = 4;
const int in4 = 3;

void setup()
{
 //FOR RIGHT
pinMode(right_trigPin, OUTPUT);
pinMode(right_echoPin, INPUT);

//FOR LEFT
pinMode(left_trigPin, OUTPUT);
pinMode(left_echoPin, INPUT);
pinMode (in1, OUTPUT);
pinMode (in2, OUTPUT);
pinMode (in3, OUTPUT);
pinMode (in4, OUTPUT);
}
long duration, distance, distance1, distance2;
void loop()
{
digitalWrite(right_trigPin, LOW);
delayMicroseconds(3);
digitalWrite(right_trigPin, HIGH);
delayMicroseconds(8);
digitalWrite(right_trigPin, LOW);
duration = pulseIn(right_echoPin, HIGH);
distance1 = duration/58.2;
digitalWrite(left_trigPin, LOW);
delayMicroseconds(3);
digitalWrite(left_trigPin, HIGH);
delayMicroseconds(8 );
digitalWrite(left_trigPin, LOW);
duration = pulseIn(left_echoPin, HIGH);
distance2 = duration/58.2;
if(distance1<30 && distance2<30)
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}
else
{
  //FOR right 
digitalWrite(right_trigPin, LOW);
delayMicroseconds(3);
digitalWrite(right_trigPin, HIGH);
delayMicroseconds(8);
digitalWrite(right_trigPin, LOW);
duration = pulseIn(right_echoPin, HIGH);
distance = duration/58.2;
if(distance<30)
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}
else
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}
// for left 
digitalWrite(left_trigPin, LOW);
delayMicroseconds(3);
digitalWrite(left_trigPin, HIGH);
delayMicroseconds(8 );
digitalWrite(left_trigPin, LOW);
duration = pulseIn(left_echoPin, HIGH);
distance = duration/58.2;
if(distance<30)
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}
else
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}
}
}
