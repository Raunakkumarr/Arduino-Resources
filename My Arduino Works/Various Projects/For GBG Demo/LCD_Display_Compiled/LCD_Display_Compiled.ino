//*Created By Agkiya Infotech
//*LCD Display

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600); // Starts the serial communication
}

void loop() 
{
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("WELCOME TO");
  lcd.setCursor(1,1);
  lcd.print("AGKIYA INFOTECH");

}
