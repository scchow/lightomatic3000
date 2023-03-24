int switch_pin = 12;
int led = 13;
int switch_on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(switch_pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch_on = digitalRead(switch_pin) == LOW;
  digitalWrite(led, switch_on);
}
