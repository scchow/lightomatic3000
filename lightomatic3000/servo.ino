/**
 * @brief Code for interfacing with the servo
 *
 * Based on the Arduino Servo library example:
 * https://docs.arduino.cc/learn/electronics/servo-motors
 *
 */

/**
 * @brief Sets the pin provided as a servo pin,
 *        sets the angle to zero, and waits 0.25 seconds
 *
 * @param servo_pin the Digital pin number for the servo
 */
void servo_setup(int servo_pin)
{
  // put your setup code here, to run once:
  servo.attach(servo_pin); // attaches the servo on pin 9 to the servo object
  servo.write(0);          // start at home position
  delay(250);
}

/**
 * @brief Presses the light switch by moving the servo to the specified angle
 *
 * @param angle the angle (in degrees) to move the servo
 */
void press_button(int angle)
{
  // Move servo to specified angle
  // run_servo(angle);
  servo.write(angle);
  delay(250); // wait 0.25 second
  // move servo back to start
  servo.write(0);
}
