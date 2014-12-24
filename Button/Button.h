#ifndef Button_H
#define Button_H

#include <Arduino.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h" 

class Button {
  public:
    // properties
    int pin; // pin number
    int mode; // pin mode (INPUT or INPUT_PULLUP)
    unsigned long interval; // lock-out interval
    boolean state; // button last read state
    unsigned long time; // button last read timestamp
    // methods
    DebounceButton(uint8_t pin, unsigned long interval_millis, int mode);
    boolean edge(boolean sense);
};
