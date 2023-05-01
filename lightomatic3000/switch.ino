
/**
 * @brief Setus up the switch and status pins for turning on/off the lightomatic3000
 *
 * @param switch_pin the Digital pin number for the switch
 * @param status_led the Digital pin number for the status LED
 */
void switch_setup(int switch_pin, int status_led)
{
  pinMode(status_led, OUTPUT);
  pinMode(switch_pin, INPUT_PULLUP); // use internal pullup resistor
}

/**
 * @brief Checks if the switch is on and sets the global variable switch_on
 *
 * @param switch_pin the Digital pin number for the switch
 * @param status_led the Digital pin number for the status LED
 */
void switch_loop(int switch_pin, int status_led)
{
  // Check if switch is on
  switch_on = digitalRead(switch_pin) == LOW;
  // illuminate Arduino LED if switch is on
  digitalWrite(status_led, switch_on);
}
