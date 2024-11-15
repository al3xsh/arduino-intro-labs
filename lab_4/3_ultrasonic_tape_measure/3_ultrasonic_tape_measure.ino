/*
 * 3_ultrasonic_tape_measure.ino
 * 
 * A simple application to use the newping library and the parallax ping)))
 * sensor to measure the distance from the sensor to an object.
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// include some libraries 
#include <NewPing.h>
#include <LiquidCrystal.h>

// define the range of our sensor (in cm)
#define MAX_DISTANCE 200

// create our sensor object (on pin 8)
NewPing sonar(8, 8, MAX_DISTANCE);

// initialise the lcd display
// pin inputs are rs, enable, d4, d5, d6, d7
LiquidCrystal lcd(7, 6, 2, 3, 4, 5);

// CODE

// set everything up
void setup()
{
  // start serial comms
  Serial.begin(9600);
  
  // setup the lcd display (16x2 lines)
  lcd.begin(16, 2);
  
  // print a message
  lcd.setCursor(0, 0);
  lcd.print("ultrasonic ruler");
  delay(500);
}

// main program loop
void loop()
{  
  // wait half a second between measurements
  delay(500); 

  // send the ping, listen for a response, and get the distance in cm
  int distance = sonar.ping_cm();

  // print to the serial monitor for debugging
  Serial.print(distance);
  Serial.print(" cm\n");

  // set the lcd cursor to be the first element of the second row
  lcd.setCursor(0,1);

  // clear the line, reset the cursor position, and write the new data to it
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
}
