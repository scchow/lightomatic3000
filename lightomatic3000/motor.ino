//https://docs.arduino.cc/learn/electronics/servo-motors
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int press_angle = 10;
const int servo_pin = A0;

void servo_setup() {
  // put your setup code here, to run once:
  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  myservo.write(0); // start at home position
}

// move the servo by angle degrees
void run_servo(int angle) {
  for (int i = 0; i <= angle; i++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if (angle < 0){
      pos -= 1;
    } else {
      pos += 1;
    }
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

// Presses the light switch
void press_button(){
  // Move servo to pressed position
  run_servo(press_angle);
  // move servo back to start
  myservo.write(0);
  
}

