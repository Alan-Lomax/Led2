#ifndef MY_LED2_H
#define MY_LED2_H
#include "Arduino.h"
/*
 *****************************************************
 ** LED2_H                                          **
 **                                                 **
 ** This class implements standard LED on-off       **
 ** logic on a pin you specify plus a configurable  **
 ** blinking effect. It does so without any delay   **
 ** calls. (no blocking code)                       **
 *****************************************************
*/
class Led2 {
  private:
    int _pin;                           // the number of the LED pin
    unsigned long _onTime;              // milliseconds of on-time
    unsigned long _offTime;             // milliseconds of off-time
    unsigned long _nextTime;            // next time change in milliseconds
    bool _blink;                        // true if we are in blinking mode, false if not
    int _state;                         // ledstate used to set the LED
    void init();                        // Initialization code

  public:
    Led2(byte pin);                     // Simple default definition without a pre specified on and off time.
    Led2(byte pin, unsigned long on, unsigned long off);  // this definition includes the on and off time values from the outset
    void update();                      // update things based on elapsed time (call this as often as possible)
    bool getState();                    // Return the current state of LED (on / off) Allows parts of your code to run only when LED is on for example.
    bool getBlink();                    // return the LEDs current blinking state (true / false)
    void onTime(long on);               // Set the onTime to a new value
    long onTime();                      // Return the current onTime
    void offTime(long off);             // Set the offTime to a new value
    long offTime();                     // Return the current offTime
    void off();                         // Turning off the LED (sets blink to false and ignores timing values)
    void on();                          // Turning on  the LED (sets blink to false and ignores timing values)
    void blink();                       // set the LED to a blinking state using the previously set timing values
};
#endif
