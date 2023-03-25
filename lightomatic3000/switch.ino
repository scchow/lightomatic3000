void switch_setup(int switch_pin, int status_led) {
  pinMode(status_led, OUTPUT);
  pinMode(switch_pin, INPUT_PULLUP); // use internal pullup resistor
}

void switch_loop(int switch_pin, int status_led) {
  // Check if switch is on
  switch_on = digitalRead(switch_pin) == LOW;
  // illuminate Arduino LED if switch is on
  digitalWrite(status_led, switch_on);
}
