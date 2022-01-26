#include "Led2.h"
Led2 myLed1 = Led2(13);

void setup() {
  myLed1.onTime(100);       // Set LED onTime (100 ms)
  myLed1.offTime(900);      // Set LED offTime (900 ms)
  myLed1.blink();           // turn on blink mode
}

void loop()
{
  myLed1.update();              // call update frequently
}
