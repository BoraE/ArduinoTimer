// Author(s): Bora Eryilmaz
// Copyright 2018

#ifndef _THREAD_H
#define _THREAD_H

class Thread {
  using FCN = void (*)();

public:
  Thread(unsigned long sample_time, FCN fcn);
  void enable() { _enabled = true; }
  void disable() { _enabled = false; }
  bool isEnabled() { return _enabled; }
  void execute();

private:
  unsigned long _sample_time; // sample time in ms
  unsigned long _previous_time { 0ul }; // previous update time in ms
  bool _enabled { false };
  FCN _fcn;
};

#endif