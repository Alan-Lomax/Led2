#include "Led2.h"

Led2::Led2(byte pin) {
  // Save the passed pin
  _pin = pin;
  init();
}

Led2::Led2(byte pin, unsigned long on, unsigned long off) {
  // Save the passed pin and timing values into the equivelent local variables (with underscore)
  _pin = pin;
  _onTime = on;
  _offTime = off;
  // Initializion code is kept seperate just for clarity.
  init();
}

void Led2::init() {
  pinMode(_pin, OUTPUT);    // define our output pin
  off();                    // call the function that sets out LED to off initially
}

void Led2::update() {
  if (_blink) {                                                         // If in blinking mode look at timing first
    if ( millis() >= _nextTime) {                                       // It is time to do something.
      _state = !_state;                                                 // swap states
      _nextTime =  millis() + (_state == HIGH ? _onTime : _offTime);    // and calculate when next
                                                                        // change of state is due 
    }
  }
  digitalWrite(_pin, _state);                                           // update the actual output according to desired state
}

bool Led2::getState() {
  // return the current state of the led (True or False)
  return _state;
}

bool Led2::getBlink() {
  // return the current blink state of the led (True or False)
  return _blink;
}

void Led2::onTime(long on) {
  // update the desired on time of the led
  _onTime = on;
}

long Led2::onTime() {
  // return the current on time of the led
  return _onTime;
}

void Led2::offTime(long off) {
  // update the desired off time of the led
  _offTime = off;
}

long Led2::offTime() {
  // return the current off time of the led
  return _offTime;
}

void Led2::off() {
  _blink = false;         // Turn off blink mode
  _state = LOW;           // Set the desired state - LED will turn off on next call to update
}

void Led2::on() {
  _blink = false; // Turn off blink mode
  _state = HIGH;  // Set desired state LED will turn on with next call to update
}

void Led2::blink() {
  _blink = true;                       // Turn on blink mode
  _nextTime =  millis() + _offTime;    // Next change of state will be when the off time has expired
}
