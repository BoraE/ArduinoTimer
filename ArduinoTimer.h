// Author(s): Bora Eryilmaz
// Copyright 2018

class Timer {
private:
  unsigned long _sample_time; // sample time in ms
  unsifned long _previous_time; // previous execution time in ms
  bool _active;
  void (*_fcn)();

public:
  Timer(unsigned long sample_time, void (*fcn)());
  void start() { _active = true; };
  void stop() { _active = false; };
  void update();
};
