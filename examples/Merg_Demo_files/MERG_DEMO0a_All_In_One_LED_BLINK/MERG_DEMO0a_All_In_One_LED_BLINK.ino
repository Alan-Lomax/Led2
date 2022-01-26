//
// A demonstration of defining a class and implementing it all in the one sketch file.
//    o This is a good approach when developing the class code as it avoids juggling multiple files.
//    o The downside is the code is not immediately available to other sketches.
//
// Eventually this will be a separate Header File (*.h)
//
class Led007 {
  private:
    int _pin;                           // the number of the LED pin
    unsigned long _onTime;              // milliseconds of on-time
    unsigned long _offTime;             // milliseconds of off-time
    unsigned long _nextTime;            // next time change in milliseconds
    bool _blink;                        // true if we are in blinking mode, false if not
    int _state;                         // ledstate used to set the LED
    void init();                        // Initialization code

  public:
    Led007(byte pin);                   // Prototype for simple constructor
    void update();                      // update things based on elapsed time (call this as often as possible)
    void onTime(long on);               // Set the onTime to a new value
    void offTime(long off);             // Set the offTime to a new value
    void off();                         // Turning off the LED (sets blink to false and ignores timing values)
    void on();                          // Turning on  the LED (sets blink to false and ignores timing values)
    void blink();                       // set the LED to a blinking state using the previously set timing values
};





// scroll down !
//
// Eventually this will be a separate Implementation File (*.cpp)
//
Led007::Led007(byte pin) {
  // Save the passed pin
  _pin = pin;
  init();
}

void Led007::init() {
  pinMode(_pin, OUTPUT);    // define our output pin
  off();                    // call the function that sets out LED to off initially
}

void Led007::update() {
  if (_blink) {                                                         // If in blinking mode look at timing first
    if ( millis() >= _nextTime) {                                       // It is time to do something.
      _state = !_state;                                                 // swap states
      _nextTime =  millis() + (_state == HIGH ? _onTime : _offTime);    // and calculate when next change of state is due
    }
  }
  digitalWrite(_pin, _state);                                           // update the actual output according to desired state
}

void Led007::onTime(long on) {
  // update the desired on time of the led
  _onTime = on;
}

void Led007::offTime(long off) {
  // update the desired off time of the led
  _offTime = off;
}

void Led007::off() {
  _blink = false;         // Turn off blink mode
  _state = LOW;           // Set the desired state - LED will turn off on next call to update
}

void Led007::on() {
  _blink = false; // Turn off blink mode
  _state = HIGH;  // Set desired state LED will turn on with next call to update
}

void Led007::blink() {
  _blink = true;                       // Turn on blink mode
  _nextTime =  millis() + _offTime;    // Next change of state will be when the off time has expired
}






//
// This sketch is using the class defined above.
//   o No '#include' statements are needed since the lines are all here in one place.
//
Led007 myLed1 = Led007(13);

void setup() {
  myLed1.onTime(250);       // Set LED onTime (250 ms)
  myLed1.offTime(750);      // Set LED offTime (750 ms)
  myLed1.blink();           // turn on blink mode
}

void loop()
{
  myLed1.update();              // call update frequently
}
