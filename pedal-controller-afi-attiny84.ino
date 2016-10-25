int input_up = 10;
int input_dn = 9;

#define MODES_LENGTH 3
#define RELAYS_LENGTH 3

int relays[RELAYS_LENGTH] = {6, 7, 8};
int leds[MODES_LENGTH] = {5, 4, 3};

int modes[MODES_LENGTH][RELAYS_LENGTH] = {
  {LOW, LOW, HIGH}, // clean
  {HIGH, HIGH, HIGH}, // crunch
  {LOW, LOW, LOW}   // solo
};

int mode;


void setup() {
  //Serial.begin(9600);
  pinMode(input_up, INPUT_PULLUP);
  pinMode(input_dn, INPUT_PULLUP);
  for (int i = 0; i < RELAYS_LENGTH; i++) {
    pinMode(relays[i], OUTPUT);
  }
  for (int i = 0; i < MODES_LENGTH; i++) {
    pinMode(leds[i], OUTPUT);
  }
  mode = 0;
  set_mode(mode);
}


void set_mode(int mode) {
  // write relay pins
  for (int i = 0; i < RELAYS_LENGTH; i++) {
    //Serial.print(modes[mode][i]);
    digitalWrite(relays[i], modes[mode][i]);
  }
  // write led pins
  for (int i = 0; i < MODES_LENGTH; i++) {
    //Serial.print(modes[mode][i]);
    digitalWrite(leds[i], LOW);
  }
  digitalWrite(leds[mode], HIGH);
}

int input_up_state_last = HIGH, input_up_state, input_dn_state_last = HIGH, input_dn_state;
void loop() {
  // read the pushbuttons input pins
  input_up_state = digitalRead(input_up);
  input_dn_state = digitalRead(input_dn);
  if (input_up_state != input_up_state_last and input_up_state == LOW) {
    //Serial.println("UP pushed");
    mode++;
    mode = mode % (MODES_LENGTH);
    set_mode(mode);
  }
  if (input_dn_state != input_dn_state_last and input_dn_state == LOW) {
    //Serial.println("DOWN pushed");
    mode--;
    if (mode < 0) mode = MODES_LENGTH - 1;
    set_mode(mode);
  }
  input_up_state_last = input_up_state;
  input_dn_state_last = input_dn_state;
}
