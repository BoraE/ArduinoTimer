/*
 * Blink the on-board LED without blocking the main loop.
 */

// Copyright (c) 2018 Bora Eryilmaz

#include <Thread.h>

// User function to execute at each time interval
bool on_state = false;
void on_off_fcn() {
  on_state = !on_state;
  digitalWrite(LED_BUILTIN, on_state);
}

// Construct the thread (1000ms period)
Thread thread {1000ul, on_off_fcn};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // on_off_fcn() will run periodically without blocking the main loop
  thread.update();

  // Your other code here
}
