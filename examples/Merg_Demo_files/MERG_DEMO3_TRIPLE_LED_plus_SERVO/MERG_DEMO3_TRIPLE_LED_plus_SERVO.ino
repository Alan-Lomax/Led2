#include "Led2.h"
#include "Servo2.h"

Led2 myLed1 = Led2(13,50,300);       // Pin 13 
Led2 myLed2 = Led2(12,300,300);      // Pin 12
Led2 myLed3 = Led2(11,1000,1000);    // Pin 11
Servo2 myServo1 = Servo2(30);        // interval (ms between movements) - higher number is slower

void setup() {
  myLed1.blink();           // turn on blink mode
  myLed2.blink();           // turn on blink mode
  myLed3.blink();           // turn on blink mode

// Servo
  myServo1.attach(5);       // Pin 5 
}

void loop()
{
  //
  // call update frequently
  //
  myLed1.update();              
  myLed2.update(); 
  myLed3.update(); 
  myServo1.update();        // at present the servo2 class only sweeps the servo back and forth.
}
