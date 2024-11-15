/*
 * 2a_led_latch.ino
 *
 * latch an led based on the press of a button
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// set pin numbers for button and led
const int button_pin = 12;
const int led_pin    = 13;  

// variable for latching the led
int led_state = LOW;

// CODE

// set up code
void setup()
{
  // set pin i/o
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

// main program
void loop()
{
  // read the state of the pushbutton value:
  int button_state = digitalRead(button_pin);

  // if the button is pressed toggle the state of the led
  if (button_state == HIGH)
  {
    led_state = !led_state;
    digitalWrite(led_pin, led_state);
  }
}
