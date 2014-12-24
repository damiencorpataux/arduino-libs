#include <Arduino.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h" 
#include "Debounce.h"

Button::Button(uint8_t pin, unsigned long interval_millis=50, int mode=INPUT_PULLUP) { 
  this->pin = pin;
  this->mode = mode;
  this->interval = interval_millis;
  // pin initialization
  pinMode(this->pin, this->mode);
}

boolean Button::edge(boolean sense=LOW) {
  boolean last_state = this->state;
  this->state = digitalRead(this->pin);
  if (last_state != this->state && this->state == sense) {
    // edge detected
    if ((millis() - this->time) > this->interval) {
      // ignore subsequent edge during interval
      this->time = millis();
      return true;
    }
  }
  return false;
}
