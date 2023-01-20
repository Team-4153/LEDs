#include "FastLED.h" // library used for LEDs, as long as it's compatible with WS2812B leds it should work
#include <math.h>

//Setup LEDs
const int ledPin = 12; // digital pin number on the arduino
const int ledCount = 48; // number of LEDs
CRGB ledArray[ledCount]; // setup for the led array

//Color definitions
CRGB color = CRGB(0,255,0); // Use (G,R,B) instead of (R,G,B), meaning this color is red

void setup() // loop used to turn on the leds all at once, if the for loop was in loop(), it would not instantly light up
{
  FastLED.addLeds<WS2812B, ledPin>(ledArray, ledCount); // sets up the leds so the program can use it. 
  pinMode(ledPin,OUTPUT); // arduino pin setup
  
  for (int i = 0; i < ledCount; i++) // for loop that runs through each LED
    {
      ledArray[i] = color; // set the current LED being worked on to red
    }
  FastLED.show(); // library function used to actually turn on the led with whatever color it has been given
}

void loop() 
{

}
