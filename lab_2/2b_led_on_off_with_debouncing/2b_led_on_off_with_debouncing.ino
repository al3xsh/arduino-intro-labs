/*
 * 2b_led_on_off_with_debouncing.ino
 * 
 * latch an led based on the press of a button (now with added button 
 * debouncing)
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// set pin numbers for button and led
const int button_pin = 12;
const int led_pin    = 13;  

// variable for latching the led
int led_state = 0;

// variables for reading and storing the pushbutton status
int curr_button_state = 0;
int last_button_state = 0;

// set up timing variables for the debounce process
unsigned long debounce_time = 0;
unsigned long debounce_delay = 50;

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

  // check to see if the button was pressed - i.e. the input went from LOW to 
  // HIGH - and it was long enough after the last transition to not be due to
  // noise

  // if the button state was changed, we reset the timer
  if (button_state != last_button_state)
  {
    debounce_time = millis();
  }

  // if this was a genuine button push and not noise (measured by the button 
  // state having changed for longer than the debounce delay)
  if ((millis() - debounce_time) > debounce_delay)
  {
    // if the button state has changed, update the button state. if it has 
    // gone from LOW to HIGH then also toggle the state of the led
    if (button_state != curr_button_state)
    {
      curr_button_state = button_state;
      if (curr_button_state == HIGH)
      {
        led_state = !led_state;
        digitalWrite(led_pin, led_state);
        
        // this is where we will do whatever else we want to happen after 
        // pressing the button!
      }
    }
  }

  // update the button state (right at the end of the loop!)
  last_button_state = button_state;

}
