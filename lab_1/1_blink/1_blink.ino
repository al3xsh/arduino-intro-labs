/*
 * 1_blink.ino
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
  // turn led on, wait for 1 second, turn led off, wait for 1 second,
  // repeat ...
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
