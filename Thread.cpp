// Copyright (c) 2018-2019 Bora Eryilmaz

#include <Arduino.h>
#include <Thread.h>

void Thread::update() {
  unsigned long current_time = get_current_time();
  unsigned long delta = current_time - _previous_time;

  if (delta >= _sample_time) {
    _previous_time = current_time;

    if (_enabled) {
      _fcn();
    }
  }
}

MillisecondThread::MillisecondThread(unsigned long sample_time, FCN fcn)
  : Thread{sample_time, fcn} {
  _previous_time = get_current_time();
}

unsigned long MillisecondThread::get_current_time() {
  return millis();
}

MicrosecondThread::MicrosecondThread(unsigned long sample_time, FCN fcn)
  : Thread{sample_time, fcn}{
  _previous_time = get_current_time();
}

unsigned long MicrosecondThread::get_current_time() {
  return micros();
}
