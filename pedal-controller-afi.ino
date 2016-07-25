#include <Arduino.h>

int input_up = 3;
int input_dn = 4;
int relays[3] = {0, 1, 2};

#define MODES_LENGTH 3 
#define RELAYS_LENGTH 3 
int modes[MODES_LENGTH][RELAYS_LENGTH] = {
  {LOW, LOW, HIGH}, // clean
  {HIGH, HIGH, HIGH}, // crunch
  {LOW, LOW, LOW}   // solo
};

int mode;


void setup() {
  //Serial.begin(9600);
  pinMode(input_up, INPUT);
  pinMode(input_up, OUTPUT);
  pinMode(input_dn, INPUT);
  pinMode(input_dn, OUTPUT);
  for (int i=0; i < RELAYS_LENGTH; i++) {
    //Serial.println(relays[i]);
    pinMode(relays[i], OUTPUT);
  }
  mode = 0;
  set_mode(mode);
  //Serial.println("Initialized!");
}


void set_mode(int mode) {
  //Serial.println("Mode: " + mode);
  for (int i = 0; i < RELAYS_LENGTH; i++) {
    //Serial.print(modes[mode][i]);
    digitalWrite(relays[i], modes[mode][i]);
  }
  //Serial.println();
}

int input_up_state_last=LOW, input_up_state, input_dn_state_last=LOW, input_dn_state;
void loop() {
  // read the pushbuttons input pins
  input_up_state = digitalRead(input_up);
  input_dn_state = digitalRead(input_dn);
  if (input_up_state != input_up_state_last and input_up_state == HIGH) {
    //Serial.println("UP pushed");
    mode++;
    mode = mode % (MODES_LENGTH);
    set_mode(mode);
  }
  if (input_dn_state != input_dn_state_last and input_dn_state == HIGH) {
    //Serial.println("DOWN pushed");
    mode--;
    if (mode < 0) mode = MODES_LENGTH - 1;
    set_mode(mode);
  }
  input_up_state_last = input_up_state;
  input_dn_state_last = input_dn_state;
}
