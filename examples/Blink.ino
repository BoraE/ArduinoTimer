/*
  Bora Eryilmaz, 2018
*/

#include <Timer.h>

class Timer1 {
public:
  Timer1(int pin = 13, unsigned long period = 1000ul, unsigned long onTime = 500ul);
  void execute();
  ~Timer1() {}
private:
  int _pin;
  int _state;
  unsigned long _period;
  unsigned long _onTime;
  unsigned long _previousMillis;
  unsigned long _currentMillis;
};

Timer1::Timer1(int pin, unsigned long period, unsigned long onTime)
  : _pin(pin), _period(period), _onTime(onTime) {
  _previousMillis = 0ul;
  _state = LOW;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _state);
}

void Timer1::execute() {
  _currentMillis = millis();
  if (_currentMillis > _previousMillis + _onTime) {
    _state = LOW;
  } else {
    _state = HIGH;
  }
  digitalWrite(_pin, _state);

  // Reset previous time at the end of the period
  if (_currentMillis > _previousMillis + _period) {
    _previousMillis = _currentMillis;
  }
}


Timer1 motorTimer(12, 1800000ul,    900000ul); // 15 min on every 30 min
Timer1 lightTimer(11, 86400000ul, 57600000ul); // 16 hr on every day

void setup() {
  Serial.begin(9600);
}

void loop() {
  motorTimer.execute();
  lightTimer.execute();
}
