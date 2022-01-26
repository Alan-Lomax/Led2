#include "Servo2.h"

Servo2::Servo2(int interval) {
  _updateInterval = interval;
  _increment = 1;
  _posMax = 180;               // Maximum servo position (default = 180)
  _posMin = 0;                 // Minimum servo position (default = 0)
  _pos = _posMin;              // Start Servo off at Minimum servo position
}

Servo2::Servo2(int interval , int PosMin, int PosMax) {
  _updateInterval = interval;
  _increment = 1;
  _posMax = PosMax;            // Set Maximum servo position
  _posMin = PosMin;            // Set Minimum servo position
  _pos = _posMin;              // Start Servo off at Minimum servo position
}

void Servo2::attach(int pin) {
  _servo.attach(pin);
}

void Servo2::detach() {
  _servo.detach();
}

int Servo2::pos() {
  return _pos;
}

void Servo2::update() {
  if ((millis() - _lastUpdate) > _updateInterval) // time to update
  {
    _lastUpdate = millis();
    _pos += _increment;
    _servo.write(_pos);
#ifdef DEBUG
    Serial.println(_pos);
#endif
    if ((_pos >= _posMax) || (_pos <= _posMin)) // end of sweep
    {
      // reverse direction
      _increment = -_increment;
    }
  }
}
