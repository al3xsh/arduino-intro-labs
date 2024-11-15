/*
 * 1_analog_led_fade.ino
 *
 * simple sketch to fade an led based on the potentiometer input
 * 
 * the led is on pin 11 because pin 11 is capable of pwm (it has a ~ symbol next 
 * to it)
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// set pin numbers
const int led_pin = 11;
const int pot_pin = A0;

// initialise the brightness value
int brightness = 128;

// CODE

// set up the initial state of the program
void setup()
{
  // set up the serial connection to enable debugging
  Serial.begin(9600);

  // set the pin i/o
  pinMode(led_pin, OUTPUT);
}
//345678901234567890123456789012345678901234567890123456789012345678901234567890

// main program
void loop()
{
  // get the brightness (this value needs to be between 0 and 255, so we need to 
  // divide the pot value by 4 - as the analogRead of the pot is in the range 0 
  // to 1023)
  int val = analogRead(pot_pin);
  brightness = val / 4;

  // note: we could also have used the map() function above

  // debugging
  Serial.print("Potentiometer value: ");
  Serial.println(val, DEC);
  Serial.print("Brightness value: ");
  Serial.println(brightness, DEC);
  
  // set the brightness of the led
  analogWrite(led_pin, brightness);

  // wait slightly to allow dimming effect to be seen
  delay(30);

}
