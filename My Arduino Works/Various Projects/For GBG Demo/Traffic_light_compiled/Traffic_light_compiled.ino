//*Created By Agkiya Infotech
//*Automatic Traffic Light

// lightpins for Footpath1 and 2
const int RedF12 = 8;
const int GreenF12 = 9;
// lightpins for Footpath3 and 4
const int RedF34 = 10;
const int GreenF34 = 11;
// lightpins for roadway1 and 2
const int Red12 = 2;
const int Yellow12 = 3;
const int Green12 = 4;
// lightpins for roadway3 and 4
const int Red34 = 5;
const int Yellow34 = 6;
const int Green34 = 7;

void setup() {
  pinMode(RedF12, OUTPUT);
  pinMode(GreenF12, OUTPUT);
  pinMode(RedF34, OUTPUT);
  pinMode(GreenF34, OUTPUT);
  pinMode(Red12, OUTPUT);
  pinMode(Yellow12, OUTPUT);
  pinMode(Green12, OUTPUT);
  pinMode(Red34, OUTPUT);
  pinMode(Yellow34, OUTPUT);
  pinMode(Green34, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  delay(50000);
  // Red light for R1, R2, F3and F4; green for R3, R4, F1 and F2, 
  digitalWrite(Red12,  HIGH); 
  digitalWrite(Yellow12, LOW);
  digitalWrite(Green12, LOW);
  digitalWrite(Red34, LOW);
  digitalWrite(Yellow34, LOW);
  digitalWrite(Green34, HIGH);
  digitalWrite(RedF12,  LOW);
  digitalWrite(GreenF12,  HIGH);
  digitalWrite(RedF34,  HIGH);
  digitalWrite(GreenF34,  LOW);
  delay(10000);
  digitalWrite(Red12,  LOW); 
  digitalWrite(Yellow12, LOW);
  digitalWrite(Green12, LOW);
  digitalWrite(Red34, LOW);
  digitalWrite(Yellow34, HIGH);
  digitalWrite(Green34, LOW);
  digitalWrite(RedF12, HIGH);
  digitalWrite(GreenF12, LOW);
  digitalWrite(RedF34,  HIGH);
  digitalWrite(GreenF34,  LOW);
  delay(2000);
  digitalWrite(Red12,  LOW); 
  digitalWrite(Yellow12, LOW);
  digitalWrite(Green12, HIGH);
  digitalWrite(Red34, HIGH);
  digitalWrite(Yellow34, LOW);
  digitalWrite(Green34, LOW);
  digitalWrite(RedF12, HIGH);
  digitalWrite(GreenF12, LOW);
  digitalWrite(RedF34,  LOW);
  digitalWrite(GreenF34,  HIGH);
  delay(10000);
}
