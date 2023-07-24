const int trig = 12;
const int echo = 13;
int Buzzer = 2;
int led01 = 1;
int led02 = 3;

int t=0;
int h=0;
int hp=0;
int a=0;

int t2=0;
int h2=0;
int hp2=0;
int b=0;
int c=0;
int height=28; //height of the container
int amount=-120000; //Set your limit of water usage, it should be in ml, the value should be negative, this is for 120 liters
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  h = t / height ;
  h = h - 6;  
  h = 50 - h;  
  hp = 2 * h; 
  a = hp*10 ; 
  Serial.print("Reading 1 \n");
  Serial.print(a);
  Serial.print(" ml \n");
  
  delay(3600000); // reading will take after one hour


  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t2 = pulseIn(echo, HIGH);
  h2 = t2 / height;
  h2 = h2 - 6;  
  h2 = 50 - h2;  
  hp2 = 2 * h2; 
  b = hp2*10;
  Serial.print("Reading 2 \n");
  Serial.print(b);
  Serial.print(" ml \n");
  delay(3600);
  Serial.print("AMOUNT OF WATER DECREASED \n");
  c = c+(b-a);
  Serial.print(c);
  Serial.print(" ml \n");
  delay(1000);

  if (c <= amount)
  {
    tone(Buzzer,500);
    digitalWrite(led01, HIGH);
    digitalWrite(led02, LOW);
  }
  else
  {
    digitalWrite(led02, HIGH);
    digitalWrite(led01, LOW);
    }
}
