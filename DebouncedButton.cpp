/*
Copyright 2020 Eric Dyke

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "DebouncedButton.h"

DebouncedButton::DebouncedButton(int pin) {
  pin = pin;
  lastState = LOW;
  debouncedState = LOW;
  lastDebounceTime = 0;
  transition = false;
  pinMode(pin, INPUT);
}

void DebouncedButton::read() {
  int reading = digitalRead(pin);
  transition = false;

  if (reading != lastState) {
    lastDebounceTime = millis();
    lastState = reading;
  }

  if ((millis() - lastDebounceTime) > DebouncedButton::DEBOUNCE_BUTTON_DELAY) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (lastState != debouncedState) {
      debouncedState = lastState;
      transition = true;
    }
  }
}

int DebouncedButton::getState() {
  return lastState;
}

boolean DebouncedButton::getTransition() {
  return transition;
}


