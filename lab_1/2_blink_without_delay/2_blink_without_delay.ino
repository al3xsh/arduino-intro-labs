/*
 * 2_blink_without_delay.ino
 *
 * this is a simple Arduino program to blink an led (the electronics equivalent 
 * of hello world). this program turns an led on for 1 second and then off for 1 
 * second, and so on ...
 *
 * this program uses pin 13 for the led
 *
 * author: prof. alex shenfield
 * date:   2024/11/12
 */

// the led is connected to pin 13
const int ledPin = 13;

// timing variables ...
long previousTime = 0;   // the last time the led was updated
long interval = 1000;    // the blink interval
int  ledState = LOW;     // initial state of led (off)

// CODE

// this method runs once (when the sketch starts)
void setup()
{
  // sets the digital pin as output
  pinMode(ledPin, OUTPUT);
}

// this methods loops continuously
void loop()
{
  // get the current time this time round the loop
  unsigned long currentTime = millis();

  // if the set time interval has elapsed ...
  if (currentTime - previousTime > interval)
  {
    // save the time
    previousTime = currentTime;

    // blink the led (by flipping the led state)
    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }

    // set the led to the new led state
    digitalWrite(ledPin, ledState);
  }
}
