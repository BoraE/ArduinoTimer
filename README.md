# ArduinoTimer
A timer class to be to able to run multiple independent timed loops on Arduino.

To install, clone the repository in your Arduino's sketchbook (libraries) folder and include the Timer.h or Thread.h headers from the ArduinoTimer library.

## Non-blocking Blink
```c++
// Blink the on-board LED without blocking the main loop.
#include <Thread.h>

// User function to execute
bool state = false;
void on_off_fcn() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

// Construct the timer (500ms period)
Thread timer {500ul, on_off_fcn};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  timer.enable(); // Enable the timer
}

void loop() {
  // User function will run periodically without blocking the main loop
  timer.execute();
  // Your other code here
}

```

## On-Off Timer
```c++
// Turn the on-board LED on for 1s and turn it off for 2s, then repeat.
#include <Timer.h>

// User function to execute at each state change
void on_off_fcn(bool on_state) {
  digitalWrite(LED_BUILTIN, on_state);
}

// Construct the timer (1000ms on, 2000ms off)
Timer timer {1000ul, 2000ul, on_off_fcn};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  timer.enable();
}

void loop() {
  // User function will at each on and off transition
  timer.execute();
  // Your other code here
}
```
