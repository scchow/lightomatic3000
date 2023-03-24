int switch_on = false; // 
bool room_lit = true;

void setup() {
  // put your setup code here, to run once:
  servo_setup();
  photoresistor_setup();
  switch_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  photoresistor_loop(); // check room status
  switch_loop(); // check if switch is on
  // if the switch is on, and the room is dark, press the button
  if (switch_on & !room_lit){
      press_button();
  }
  delay(1000*5); // wait 5 seconds
}
