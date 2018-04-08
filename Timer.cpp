// Copyright (c) 2018 Bora Eryilmaz

#include <Arduino.h>
#include <Timer.h>

Timer::Timer(unsigned long on_time, unsigned long off_time, FCN fcn)
  : _on_time(on_time), _off_time(off_time), _fcn(fcn) {
}

void Timer::update() {
  unsigned long current_time = millis();
  unsigned long delta = current_time % (_on_time + _off_time);

  if ((delta < _on_time) && !_on) {
    _on = true;
    Serial.print("Switching on at "); Serial.println(current_time);
    if (_enabled) {
      _fcn(_on);
    }
  }

  if ((delta >= _on_time) && _on) {
    _on = false;
    Serial.print("Switching off at "); Serial.println(current_time);
    if (_enabled) {
      _fcn(_on);
    }
  }
}
