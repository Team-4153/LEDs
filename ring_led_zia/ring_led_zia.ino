#include "FastLED.h" // library used for LEDs, as long as it's compatible with WS2812B leds it should work
#include <math.h>

//Setup LEDs
const int ledPin = 12; // digital pin number on the arduino
const int ledCount = 48; // number of LEDs
int speed = 100; //speed at which the LEDs blink in miliseconds
CRGB leds[ledCount];

//Arrays
const int ringCounts[5] = {8,12,12,12,4}; //how many leds in each ring
const int rings[5][12] = { {1,2,3,4,5,6,7,8, NULL, NULL, NULL, NULL},
                           {9,12,16,19,22,26,29,32,36,39,42,46},
                           {10,13,17,20,23,27,30,33,37,40,43,47},
                           {11,14,18,21,24,28,31,34,38,41,44,48},
                           {15,25,35,45, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL} }; // setup for the led ring array

//Color definitions
CRGB color = CRGB(0,255,0); // Use (G,R,B) instead of (R,G,B), meaning this color is red
CRGB off = CRGB(0,0,0);

void setup() // loop used to turn on the leds all at once, if the for loop was in loop(), it would not instantly light up
{
  FastLED.addLeds<WS2812B, ledPin>(leds, ledCount); // sets up the leds so the program can use it. 
  pinMode(ledPin,OUTPUT); // arduino pin setup
}

void loop() 
{
  for (int j = 0; j < 5; j++) //ring loop
  {
    for (int k=0; k < ledCount; k++) // move this loop outside of the ring loop to have a different effect
    {
      leds[k] = off;
    }
    for (int i = 0; i < ringCounts[j]; i++) // loop that goes through every led within the current ring
      {
        leds[rings[j][i]-1] = color; // set the current LED being worked on to red   
      }
    FastLED.show(); // show the current ring
    delay(speed);
  }
}
