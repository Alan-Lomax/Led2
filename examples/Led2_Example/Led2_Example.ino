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
    Led2 myLed1 = Led2(LED_BUILTIN);      // define myLed as an object created from the Led2 class. (Use the builtin LED for this demo)

    void setup() {
      Serial.begin(9600);                 // for serial / debug console
      Serial.println(__FILE__);           // by default I like to output the file name as a minimum.

      myLed1.on();                         // turn on the LED
      myLed1.update();                     // call update once to put it in effect (remember this is setup code - only once through)
      delay(2000);                        // a forced delay for 2 seconds so you can see it

      myLed1.off();                        // turn off the LED
      myLed1.update();                     // call update once to put it in effect (remember this is setup code - only once through)
      delay(2000);                        // a forced delay for 2 seconds so you can see it

      // Here I am setting the two timing values individually
      myLed1.onTime(50);                   // Set LED ontime (50 ms)
      myLed1.offTime(300);                 // Set LED offtime (300 ms) - these numbers will give a fairly fast flashing effect
      myLed1.blink();                      // turn on blink mode for the LED
    }

    // In the loop the update function runs over and over again - it does all the work.

    void loop() {
      myLed1.update();                     // This is all that is needed. You should see the Led flashing about 3 times per second (50ms on, 300 ms off)
    }
