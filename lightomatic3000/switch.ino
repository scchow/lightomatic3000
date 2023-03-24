int switch_pin = 12; // Switch center is connected to D12, On end is connected to ground
int status_led = 13; // 13 is built in LED
//int switch_on = false; // defined in main

void switch_setup() {
  pinMode(status_led, OUTPUT);
  pinMode(switch_pin, INPUT_PULLUP); // use internal pullup resistor
}

void switch_loop() {
  // Check if switch is on
  switch_on = digitalRead(switch_pin) == LOW;
  // illuminate Arduino LED if switch is on
  digitalWrite(status_led, switch_on);
}
