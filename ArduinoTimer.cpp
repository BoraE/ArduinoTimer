#include <Timer.h>
#include <Arduino.h>

Timer::Timer(long int sample_time, void (*fcn)())
  : _sample_time(sample_time), _fcn(fcn) {
}

void Timer::update() {
  long int current_time = millis();
  if ((current_time - _previous_time) >= _sample_time) {
    _previous_time = current_time;
    if (_active) {
      _fcn();
    }
  }
}
