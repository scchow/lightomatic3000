/**
 * @file motor_test.ino
 * @author Scott Chow
 * @brief Testing the servo motor actuation
 *
 * Based on
 * https://docs.arduino.cc/learn/electronics/servo-motors
 *
 */

#include <Servo.h>

Servo myservo; // create servo object to control a servo
int pos = 0;   // variable to store the servo position
int press_angle = 10;

void setup()
{
  // put your setup code here, to run once:
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
}

void loop()
{
  press_button();
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'

  //  // put your main code here, to run repeatedly:
  //  for (pos = 0; pos <= 0; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(15);                       // waits 15ms for the servo to reach the position
  //  }
  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(15);                       // waits 15ms for the servo to reach the position
  //  }
}
// move the servo by angle degrees
void run_servo(int angle)
{
  for (int i = 0; i <= angle; i++)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if (angle < 0)
    {
      pos -= 1;
    }
    else
    {
      pos += 1;
    }
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
  }
}

void press_button()
{
  run_servo(press_angle);
  myservo.write(0);
  run_servo(-press_angle);
  delay(1000 * 2.5); // wait 5 seconds
}
