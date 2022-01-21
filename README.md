# Led2

This class defines the passed pin as an output typically for an LED. In addition to behaving like a normal LED with On and Off commands it also implements
a fully configurable blink operation where both the on time and off time can be configured (and changed on the run).
The timing and state of the LED is changed automatically at appropriate times - all you do is call the update method in your loop code.
Notes:
    This class executes in a non blocking manner. (There are no delay calls).
    All key properties can be read to determine the current value thus enabling other parts of your program to be triggered at specific times.

### Example usage from my turntable project:
Define a normal LED that at first just indicates a sensor status. If at some point an error condition is detected then turn on rapid blinking/flashing off all the LED's for a short period of time. (The operator (me) knows right away I should not have done that!)  When the invalid setting is cleared return to normal LED behaviour. 

### Files: Led2.h, Led2.CPP

## Example Program:
    /*
      Led2 example code
      In setup I demonstrate turning LED on and off (with forced pauses to observe effect)
      At the end of the setup code I set up the timing and then turn on blink mode
      The call to update in the loop code lets the class take care of all the timing details.
      
      Note:
      In a typical sketch you would turn LED on according to your logic and then carry on - no delays needed.
      At the next call to update (in your loop code) the class would pick up on your wish to turn on the LED and do it.
    */
    #include "Led2.h"

    // Notice in the line below the OnTime or OffTime is not defined (they could have been). Instead I set them separately on lines below.
    LED2 myLed1 = LED2(LED_BUILTIN);      // define myLed as an object created from the Led2 class. (Use the builtin LED for this demo)

    void setup() {
      Serial.begin(9600);                 // for serial / debug console
      Serial.println(__FILE__);           // by default I like to output the file name as a minimum.

      myLed.on();                         // turn on the LED
      myLed.update();                     // call update once to put it in effect (remember this is setup code - only once through)
      delay(2000);                        // a forced delay for 2 seconds so you can see it

      myLed.off();                        // turn off the LED
      myLed.update();                     // call update once to put it in effect (remember this is setup code - only once through)
      delay(2000);                        // a forced delay for 2 seconds so you can see it

      // Here I am setting the two timing values individually
      myLed.onTime(50);                   // Set LED ontime (50 ms)
      myLed.offTime(300);                 // Set LED offtime (300 ms) - these numbers will give a fairly fast flashing effect
      myLed.blink();                      // turn on blink mode for the LED
    }

    // In the loop the update function runs over and over again - it does all the work.

    void loop() {
      myLed.update();                     // This is all that is needed. You should see the Led flashing about 3 times per second (50ms on, 300 ms off)
    }


## Instantiation:
Choose one of these two methods to create a new LED2 object.
Note even if you use the first approach to instantiate you can later in your program change the on and off times to suit.

    Led2(byte pin);                                      // Only the pin is given The Led will default to off at the start.
    Led2(byte pin, unsigned long on, unsigned long off); // In addition to the pin both the on time and off time are passed. The Led will default to off at the start.

## Methods
     update();                         // update things based on elapsed time (call this in your loop code as often as possible)
     void off();                       // turns blink mode off and sets the desired state to off The next call to update will make it so.
     void on();                        // turns blink mode off and sets the desired state to on  The next call to update will make it so.
     void blink();                     // turns blink mode on .. in which case the LED will cycle on and off according to the onTime and offTime timing values

## Properties:
     bool getState();                  // RO Return the current state of LED (true/false)
     bool getBlink();                  // RO Return the current blink state of LED  (true/false)

     void onTime(long on);             // Sets the on Time in ms
     long onTime();                    // Reads the on Time in ms

     void offTime(long off);           // Sets the off Time in ms
     long offTime();                   // Reads the off Time in ms
