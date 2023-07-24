//Created by Raunak Kumar//

//Tags for including libraries//
#include <LiquidCrystal.h>

//Defining pins//
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
//Pins Description//
//LCD -> Arduino Pin//
//RS -> 2//
//Enable -> 3//
//D4 -> 4//
//D5 -> 5//
//D6 -> 6//
//D7 -> 7//
//R/W -> Gnd//
//Vss -> Gnd//
//Vcc -> 5V//

//Code to run the pre-defined program once//
void setup()
{
  lcd.begin(16, 2);//Sets the no. of Rows and Columns of LCD//
  lcd.print("Hey, this is Raunak Kumar here");//Prints the message on LCD//
}

//Code to repeat the pre-defined program//
void loop()
{
  lcd.setCursor(0, 1);//Sets the cursor at the desired point. Here, 0is the first column and 1 is the second row.//
  lcd.print(millis()/1000);//Prints the no. of seconds since reset//
}
