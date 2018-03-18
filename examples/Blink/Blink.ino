/*
 * Blink the on-board LED without blocking the main loop.
 */

// Author(s): Bora Eryilmaz
// Copyright 2018

#include <Thread.h>

// User function to execute
bool LED_state = false;
void on_off_fcn() {
  LED_state = !LED_state;
  digitalWrite(LED_BUILTIN, LED_state);
}

// Construct the timer (500ms period)
Thread timer {500ul, on_off_fcn};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  timer.enable();
}

void loop() {
  // on_off_fcn() will run periodically without blocking the main loop
  timer.execute();

  // Your other code here
}
