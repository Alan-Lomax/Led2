#ifndef MY_Servo2_H
#define MY_Servo2_H
#include <Arduino.h>
#include <Servo.h> 
#define DEBUG

class Servo2{
private:
  Servo _servo;              // the servo object
  int _pos;                  // current servo position
  int _posMax;               // Maximum servo position (default = 180)
  int _posMin;               // Minimum servo position (default = 0)
  int _increment;            // increment to move for each interval
  unsigned long  _updateInterval;      // interval between updates in milliseconds.
  unsigned long _lastUpdate;           // last update of position

public: 
  Servo2(int interval);                                       // use default min = 0, max = 180
  Servo2(int interval , int PosMin, int PosMax);              // overide default values as specified
  void attach(int pin);
  void detach();
  void update();
  int pos();
};
#endif
