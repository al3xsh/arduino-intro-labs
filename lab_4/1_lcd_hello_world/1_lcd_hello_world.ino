/*
 * 1_lcd_hello_world.ino
 *  
 * this is just a simple sketch to test our lcd display
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// include the lcd library
#include <LiquidCrystal.h>

// initialise the lcd display
// pin inputs are rs, enable, d4, d5, d6, d7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// CODE

// set everything up
void setup()
{
  // setup the lcd display (16x2 lines)
  lcd.begin(16, 2);

  // print a message
  lcd.setCursor(0, 0);
  lcd.print("lcd hello world!");
}

// main program loop
void loop()
{
  // set the lcd cursor to be the first element of the second row
  lcd.setCursor(0, 1);

  // print the time on the second row of the lcd
  lcd.print(millis() / 1000);
}
