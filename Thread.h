// Copyright (c) 2018-2019 Bora Eryilmaz

#ifndef _THREAD_H
#define _THREAD_H

class Thread {
public:
  using FCN = void (*)();
  Thread(unsigned long sample_time, FCN fcn) : _sample_time{sample_time}, _fcn{fcn} {}
  virtual ~Thread() {}

  void enable() { _enabled = true; }
  void disable() { _enabled = false; }
  bool isEnabled() { return _enabled; }

  void update();

protected:
  unsigned long _sample_time;
  unsigned long _previous_time { 0ul };

  bool _enabled { true };
  FCN _fcn;

  virtual unsigned long get_current_time() = 0;
};


class MillisecondThread : public Thread {
public:
  MillisecondThread(unsigned long sample_time, FCN fcn);
  ~MillisecondThread() {}
  unsigned long get_current_time() override;
};


class MicrosecondThread : public Thread {
public:
  MicrosecondThread(unsigned long sample_time, FCN fcn);
  ~MicrosecondThread() {}
  unsigned long get_current_time() override;
};

#endif
