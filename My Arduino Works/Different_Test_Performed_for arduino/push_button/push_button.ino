const int push_pin = 2;
int push_read;
int maxi = 20;
void setup(){
  pinMode(push_pin, INPUT);
  Serial.begin(9600);
}
void loop(){
  push_read = digitalRead(push_pin);
  if(push_read == HIGH){
    delay(2000);
    Serial.println("Push Button Pressed.");
    maxi = maxi + 1;
    Serial.println(maxi);
  }
  else{
    Serial.println("Push Button not Pressed.");
  }
}
