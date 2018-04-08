// Copyright (c) 2018 Bora Eryilmaz

#include <Arduino.h>
#include <Thread.h>

Thread::Thread(unsigned long sample_time, FCN fcn)
  : _sample_time(sample_time), _fcn(fcn) {
}

void Thread::update() {
  unsigned long current_time = millis();
  unsigned long delta = current_time - _previous_time;

  if (delta >= _sample_time) {
    _previous_time = current_time;
    Serial.print("Thread call at "); Serial.println(current_time);
    if (_enabled) {
      _fcn();
    }
  }
}
