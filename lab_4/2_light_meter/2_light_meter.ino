/*
 * 2_light_meter.ino
 * 
 * simple sketch to read from an ldr and display the results on the lcd screen 
 * as a percentage
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// include the lcd library
#include <LiquidCrystal.h>

// initialise the lcd display
// pin inputs are rs, enable, d4, d5, d6, d7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// sensor pin
const int sensor_pin = A0;

// calibration variables:
int sensor_value = 0;         // the current sensor value
int sensor_min = 1023;        // the minimum sensor value
int sensor_max = 0;           // the maximum sensor value

// CODE

// calibration routine to call during setup()
void calibrate() 
{
  // turn on led to signal the start of the calibration
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first ten seconds
  while (millis() < 10000) 
  {
    sensor_value = analogRead(sensor_pin);

    // record the maximum sensor value
    if (sensor_value > sensor_max) 
    {
      sensor_max = sensor_value;
    }

    // record the minimum sensor value
    if (sensor_value < sensor_min) 
    {
      sensor_min = sensor_value;
    }
  }

  // signal the end of the calibration period by turning the led off
  digitalWrite(13, LOW);
}

// set everything up
void setup()
{
  // start serial communication
  Serial.begin(9600);
  
  // setup the lcd display (16x2 lines)
  lcd.begin(16, 2);
  
  // print a message
  lcd.setCursor(0, 0);
  lcd.print("dark-o-meter");

  // do calibration
  calibrate()
}

// main program loop
void loop()
{  
  // read the sensor
  sensor_value = analogRead(sensor_pin);

  // remap the sensor value using calibration information
  sensor_value = map(sensor_value, sensor_min, sensor_max, 0, 100);

  // if the sensor value is outside the calibrated range then constrain it
  sensor_value = constrain(sensor_value, 0, 100);

  // set the lcd cursor to be the first element of the second row
  lcd.setCursor(0,1);

  // clear the line, reset the cursor position, and write the new data to it
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(sensor_value);
  lcd.print(" %");
}
