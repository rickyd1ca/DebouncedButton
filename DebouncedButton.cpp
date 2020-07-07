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
  this->pin = pin;

  debouncer.attach(pin, INPUT); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer.interval(DEBOUNCE_BUTTON_DELAY); // Use a debounce interval of 25 milliseconds
}

void DebouncedButton::read() {
  debouncer.update();
}

int DebouncedButton::getState() {
  return debouncer.read();
}

boolean DebouncedButton::getTransition() {
  return debouncer.fell() || debouncer.rose();
}


