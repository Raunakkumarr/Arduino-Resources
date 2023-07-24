//Shop Door Traffic Light
//Rev.1: H.Anderson-Chapman 09/06/2020


//LED sign pins
int redLedPin = 3;
int amberLedPin = 8;
int greenLedPin = 2;

//Entry ultrasonic sensor Pins
int entryPinOut = 5;
int entryPinIn = 6;

//Exit ultrasonic sensor Pins
int exitPinOut = 7;
int exitPinIn = 9;

//Seven segment display pins
int GPin = A5;
int FPin = A4;
int EPin = A1;
int DPin = 12;
int CPin = A0;
int BPin = A2;
int APin = A3;

//Button pins
int buttonUpPin = 10;
int buttonDownPin = 11;

//Initialising variables
int personCount = 1;
int maxPersonCount = 20;

void setup() {
  // put your setup code here, to run once:
  //Setting the sign LED pins
  pinMode(redLedPin, OUTPUT);
  pinMode(amberLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  //Setting the entry ultrasonic sesnor pins
  pinMode(entryPinOut, OUTPUT);
  pinMode(entryPinIn, INPUT);

  //Setting the exit ultrasonic sesnor pins
  pinMode(exitPinOut, OUTPUT);
  pinMode(exitPinIn, INPUT);

  //Setting seven segment display pins
  pinMode(GPin, OUTPUT);
  pinMode(FPin, OUTPUT);
  pinMode(EPin, OUTPUT);
  pinMode(DPin, OUTPUT);
  pinMode(CPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(APin, OUTPUT);

  //Setting button pins
  pinMode(buttonUpPin, INPUT);
  pinMode(buttonDownPin, INPUT);

  //Observe with terminal while in testing
  Serial.begin(9600);
}

void loop() {
  //variables to be used
  long entryDuration, entryCm, exitDuration, exitCm;

  //Any distance under this value (cm) is a confirmed scan
  int sensorLimit = 15;

  //Writing the final digit of remaining spaces to the 7-segment display
  segmentNumber((maxPersonCount - personCount) % 10);

  //taking readings for the buttons
  bool upButton = digitalRead(buttonUpPin);
  bool downButton = digitalRead(buttonDownPin);

  //If the increase button has been pressed, increase the person count
  if (upButton) {
    maxPersonCount++;
    Serial.println("Max person increased to:");
    Serial.println(maxPersonCount);
    delay(500);
  }
  //If the decrease button has been pressed, decrease the person count if possible
  else if (downButton & maxPersonCount > 0) {
    maxPersonCount--;
    Serial.println("Max person decreased to:");
    Serial.println(maxPersonCount);
    delay(500);
  }

  //If current customer count is greater or equal to max allowance, show the red sign.
  if (personCount >= maxPersonCount) {
    digitalWrite(redLedPin, HIGH);
    Serial.println("Red, wait for person to leave");
  }
  //Otherwise show the amber sign and detect for an entry
  else {
    digitalWrite(amberLedPin, HIGH);
    //Taking a distance sensor reading
    digitalWrite(entryPinOut, HIGH);
    delayMicroseconds(2);
    digitalWrite(entryPinOut, LOW);
    delayMicroseconds(10);
    entryDuration = pulseIn(entryPinIn, HIGH);

    //Converting to cm
    entryCm = entryDuration / 29 / 2;
    Serial.println("Entry Sensor:");
    Serial.println(entryCm);

    //If the distance is below the sensorLimit and there is space, the green light will turn on
    if (entryCm <= sensorLimit & personCount < maxPersonCount) {
      digitalWrite(amberLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      personCount++; //Noting the entry of a person
      Serial.println("Green, enter, person count:");
      Serial.println(personCount);
      delay(3000);
      return personCount;
    }
  }

  //If a person can leave, detect for one
  if (personCount > 0) {

    //Taking a distance sensor reading for exiting sensors
    digitalWrite(exitPinOut, HIGH);
    delayMicroseconds(2);
    digitalWrite(exitPinOut, LOW);
    delayMicroseconds(10);
    exitDuration = pulseIn(exitPinIn, HIGH);

    //Converting to cm
    exitCm = exitDuration / 29 / 2;
    Serial.println("Exit Sensor:");
    Serial.println(exitCm);

    if (exitCm <= sensorLimit) {
      personCount--;
      //Putting all lights on to indicate the departure has been read.
      digitalWrite(amberLedPin, HIGH);
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, HIGH);

      Serial.println("Person left the room, person Count:");
      Serial.println(personCount);
      delay(3000);
    }

  }

  //resetting the lights
  digitalWrite(amberLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
}

//A function to convert the number to display into the right 7-segment outputs.
void segmentNumber(int desiredNumber) {
  digitalWrite(APin, LOW);
  digitalWrite(FPin, LOW);
  digitalWrite(GPin, LOW);
  digitalWrite(CPin, LOW);
  digitalWrite(DPin, LOW);
  digitalWrite(EPin, LOW);
  digitalWrite(BPin, LOW);
  switch (desiredNumber) {
    case 0:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(EPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(FPin, HIGH);
      break;
    case 1:
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      break;
    case 2:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(EPin, HIGH);
      digitalWrite(DPin, HIGH);
      break;
    case 3:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(DPin, HIGH);
      break;
    case 4:
      digitalWrite(FPin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(CPin, HIGH);
      break;
    case 5:
      digitalWrite(APin, HIGH);
      digitalWrite(FPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(DPin, HIGH);
      Serial.println("5");
      break;
    case 6:
      digitalWrite(APin, HIGH);
      digitalWrite(FPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(EPin, HIGH);
      break;
    case 7:
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(APin, HIGH);
      break;
    case 8:
      digitalWrite(APin, HIGH);
      digitalWrite(FPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(EPin, HIGH);
      digitalWrite(BPin, HIGH);
      break;
    case 9:
      digitalWrite(FPin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(GPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(APin, HIGH);
      break;
    //Default shows 0, for when a negative value shows, no one can enter.
    default:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(EPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(FPin, HIGH);
  }
  return;
}
