//*Created By Agkiya Infotech
//*4-Way Automated Traffic Light

// lightpins for roadway1 and 2
const int Red12 = 2;
const int Yellow12 = 3;
const int Green12 = 4;
// lightpins for roadway3 and 4
const int Red34 = 5;
const int Yellow34 = 6;
const int Green34 = 7;

void setup() {  
  pinMode(Red12, OUTPUT);
  pinMode(Yellow12, OUTPUT);
  pinMode(Green12, OUTPUT);
  pinMode(Red34, OUTPUT);
  pinMode(Yellow34, OUTPUT);
  pinMode(Green34, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  delay(5000);
  // Red light for R1, R2, F3and F4; green for R3, R4, F1 and F2, 
  digitalWrite(Red12,  HIGH); 
  digitalWrite(Yellow12, LOW);
  digitalWrite(Green12, LOW);
  digitalWrite(Red34, LOW);
  digitalWrite(Yellow34, LOW);
  digitalWrite(Green34, HIGH);
  
  delay(1000);
  digitalWrite(Red12,  LOW); 
  digitalWrite(Yellow12, HIGH);
  digitalWrite(Green12, LOW);
  digitalWrite(Red34, LOW);
  digitalWrite(Yellow34, HIGH);
  digitalWrite(Green34, LOW);
  
  delay(2000);
  digitalWrite(Red12,  LOW); 
  digitalWrite(Yellow12, LOW);
  digitalWrite(Green12, HIGH);
  digitalWrite(Red34, HIGH);
  digitalWrite(Yellow34, LOW);
  digitalWrite(Green34, LOW);
  
  delay(2000);
}
