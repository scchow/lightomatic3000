/**
 * @brief Code for interfacing with the photoresistor.
 */

/**
 * @brief Sets the pin for the photoresistor
 *
 * @param pin the Analog pin number for the photoresistor
 */
void photoresistor_setup(int pin)
{
  pinMode(pin, INPUT); // Set photorestor pin as an input
}

/**
 * @brief Reads and stores the light level into the global variable lightLevel
 *
 * @param pin the Analog pin number for the photoresistor (Must be the same as passed into setup)
 */
void photoresistor_loop(int pin)
{
  lightLevel = analogRead(pin);
}
