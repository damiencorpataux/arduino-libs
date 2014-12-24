#include <Button.h>

int pin_led = 13;
int pin_button = 50;
Button button = Button(pin_button, 100);

void setup() {
  pinMode(pin_led, OUTPUT);
}

void loop() {
  if (button.edge(LOW)) {
    digitalWrite(pin_led, !digitalRead(pin_led));
  }
}
