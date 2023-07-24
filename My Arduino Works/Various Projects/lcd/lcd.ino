
#include <LiquidCrystal.h>//Library for LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);//LCD pins at which it is attached to the Arudino

const int maxN=20;
const int leftN=10;

void setup()//method used to run the code for once 
{
  lcd.begin(16, 2);//LCD order
  Serial.begin(9600);
}

void loop() //used to run the code repeatedly
{
 lcd.println("Vacant Space: "+String(leftN));
 lcd.setCursor(0,1);
 lcd.println("-Wait for 10 sec");
 //delay(1000);
 //Serial.println("Maximum Number of People increased to: "+String(maxN));
 //lcd.print("Vacant Sapce: "+String(maxN));//prints on LCD
 //lcd.setCursor(0,1);//Setting the cursor on LCD
 //lcd.print("-Wait for: 5 sec");//prints on LCD
 //delay(1000);//delay of 1 second
 
}
