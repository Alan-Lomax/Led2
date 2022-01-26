#include "Led2.h"
Led2 myLed1 = Led2(13);
Led2 myLed2 = Led2(12);
Led2 myLed3 = Led2(11);

void setup() {
// myLed1
  myLed1.onTime(50);        // Set LED onTime (50 ms)
  myLed1.offTime(300);      // Set LED offTime (300 ms)
  myLed1.blink();           // turn on blink mode

// myLed2
  myLed2.onTime(300);       // Set LED onTime (300 ms)
  myLed2.offTime(300);      // Set LED offTime (300 ms)
  myLed2.blink();           // turn on blink mode

// myLed3
  myLed3.onTime(1000);      // Set LED onTime (1000 ms)
  myLed3.offTime(1000);     // Set LED offTime (1000 ms)
  myLed3.blink();           // turn on blink mode
  
}

void loop()
{
  //
  // call update frequently
  //
  myLed1.update();
  myLed2.update(); 
  myLed3.update(); 
}
