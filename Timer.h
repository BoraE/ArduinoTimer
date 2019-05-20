// Copyright (c) 2018-2019 Bora Eryilmaz

#ifndef _TIMER_H
#define _TIMER_H

class Timer {
  using FCN = void (*)(bool); // Current state is the input argument

public:
  Timer(unsigned long on_time, unsigned long off_time, FCN fcn);

  void enable() { _enabled = true; }
  void disable() { _enabled = false; }
  bool isEnabled() { return _enabled; }

  bool isOn() { return _on; }
  void update();

private:
  unsigned long _on_time; // on time in ms
  unsigned long _off_time; // off time in ms

  bool _enabled { true };
  bool _on { false };
  FCN _fcn;
};

#endif
