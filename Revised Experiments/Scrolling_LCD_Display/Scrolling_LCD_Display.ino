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
  lcd.setCursor(0, 1);//Sets the cursor at the desired point. Here, 0is the first column and 1 is the second row.//
  lcd.print("Welcome to my Place");//Prints the no. of seconds since reset//
}

//Code to repeat the pre-defined program//
void loop()
{
  for(int PositionCount=0;PositionCount<24; PositionCount++)//Counts the Position of cursor, PositionCount<24 value can be changed as per need.//
   {
    lcd.scrollDisplayLeft();//Builtin command to scroll text Left//
    delay(1000);//Delay of 1000millisecond = 1second//
   }
  for(int PositionCount=0;PositionCount<24; PositionCount++)//Counts the Position of cursor, PositionCount<24 value can be changed as per need.//
   {
    lcd.scrollDisplayRight();//Builtin command to scroll text Right//
    delay(1000);//Delay of 1000millisecond = 1second//
   }
  for(int PositionCount=0;PositionCount<24; PositionCount++)//Counts the Position of cursor, PositionCount<24 value can be changed as per need.//
   {
    lcd.scrollDisplayLeft();//Builtin command to scroll text Left again//
    delay(1000);//Delay of 1000millisecond = 1second//
   }
}
