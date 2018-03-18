// Author(s): Bora Eryilmaz
// Copyright 2018

#ifndef _TIMER_H
#define _TIMER_H

class Timer {
  using FCN = void (*)(bool);

public:
  Timer(unsigned long on_time, unsigned long off_time, FCN fcn);
  void enable() { _enabled = true; }
  void disable() { _enabled = false; }
  bool isEnabled() { return _enabled; }
  void execute();

private:
  unsigned long _on_time; // on time in ms
  unsigned long _off_time; // off time in ms
  unsigned long _previous_time { 0ul }; // previous update time in ms
  bool _enabled { false };
  bool _on { false };
  FCN _fcn;
};

#endif
