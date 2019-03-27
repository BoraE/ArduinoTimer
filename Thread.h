// Copyright (c) 2018-2019 Bora Eryilmaz

#ifndef _THREAD_H
#define _THREAD_H

class Thread {
  using FCN = void (*)();

public:
  Thread(unsigned long sample_time, FCN fcn);

  void enable() { _enabled = true; }
  void disable() { _enabled = false; }
  bool isEnabled() { return _enabled; }

  void update();

private:
  unsigned long _sample_time; // sample time in microseconds
  unsigned long _previous_time { 0ul }; // previous update time in microseconds
  bool _enabled { true };
  FCN _fcn;
};

#endif
