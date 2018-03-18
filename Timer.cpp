// Author(s): Bora Eryilmaz
// Copyright 2018

#include <Arduino.h>
#include <Timer.h>

Timer::Timer(unsigned long on_time, unsigned long off_time, FCN fcn)
  : _on_time(on_time), _off_time(off_time), _fcn(fcn) {
}

void Timer::execute() {
  unsigned long current_time = millis();
  unsigned long delta = current_time - _previous_time;

  if ((delta < _on_time) && !_on) {
    _on = true;
    // Serial.print("On time: "); Serial.println(current_time);
    if (_enabled) {
      _fcn(_on);
    }
  }

  if ((delta >= _on_time) && _on) {
    _on = false;
    // Serial.print("Off time: "); Serial.println(current_time);
    if (_enabled) {
      _fcn(_on);
    }
  }

  if (delta >= _on_time + _off_time) {
    _previous_time = current_time;
  }
}
