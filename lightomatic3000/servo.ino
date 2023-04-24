//https://docs.arduino.cc/learn/electronics/servo-motors

void servo_setup(int servo_pin) {
  // put your setup code here, to run once:
  servo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  servo.write(0); // start at home position
  delay(250);
}

// Presses the light switch
void press_button(int angle){
  // Move servo to specified angle
  // run_servo(angle);
  servo.write(angle);
  delay(250); // wait 0.25 second
  // move servo back to start
  servo.write(0);
}
