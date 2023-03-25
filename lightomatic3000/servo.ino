//https://docs.arduino.cc/learn/electronics/servo-motors

void servo_setup(int servo_pin) {
  // put your setup code here, to run once:
  servo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  servo.write(0); // start at home position
}

// move the servo by angle degrees
// uses global pos
void run_servo(int angle) {
  for (int i = 0; i <= angle; i++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if (angle < 0){
      pos -= 1;
    } else {
      pos += 1;
    }
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

// Presses the light switch
void press_button(int angle){
  // Move servo to specified angle
  run_servo(angle);
  // move servo back to start
  servo.write(0);
}

