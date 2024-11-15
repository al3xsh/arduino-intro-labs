/* 
 * 2_led_crossfader.ino
 *
 * use the analogRead and analogWrite commands to crossfade a set of 3 leds
 *
 * the leds must be connected to pwm capable pins (in this case, pins 9, 10, and 
 * 11)
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// set pin numbers
const int pot_pin = A0;

const int led_pin1 = 9;
const int led_pin2 = 10;
const int led_pin3 = 11;

// set up the initial state of the program
void setup()
{
  // set up the serial connection to enable debugging
  Serial.begin(9600);
  
  // set the pin i/o
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);

  pinMode(pot_pin, INPUT);
}

// main program loop
void loop()
{
  // read potentiometer
  int val = analogRead(pot_pin);

  // if the analog value is in the bottom half of it's range, set:
  // led 1 as 255 - normalised potentiometer value
  // led 2 as normalised potentiometer value
  // led 3 as 0
  if (val < 512)
  {
    int output_val = map(val, 0, 511, 0, 255);
    analogWrite(led_pin1, (255 - output_val));
    analogWrite(led_pin2, output_val);
    analogWrite(led_pin3, 0);
  }
  // otherwise, if the analog value is in the top half of it's range, set:
  // led 1 as 0
  // led 2 as 255 - normalised potentiometer value
  // led 3 as normalised potentiometer value
  else
  {  
    int output_val = map(val, 512, 1023, 0, 255);
    analogWrite(led_pin1, 0);
    analogWrite(led_pin2, (255 - output_val));
    analogWrite(led_pin3, output_val);
  }

}
