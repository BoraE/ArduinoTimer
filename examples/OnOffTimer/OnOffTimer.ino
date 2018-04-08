/*
 * Turn the on-board LED on for 1s and off for 2s, then repeat.
 */

// Copyright (c) 2018 Bora Eryilmaz

#include <Timer.h>

// User function to execute at each state change
void on_off_fcn(bool on_state) {
  digitalWrite(LED_BUILTIN, on_state);
}

// Construct the timer (1000ms on, 2000ms off)
Timer timer {1000ul, 2000ul, on_off_fcn};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // on_off_fcn() will run at each on and off transition
  timer.update();

  // Your other code here
}
