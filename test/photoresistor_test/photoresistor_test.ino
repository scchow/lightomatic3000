/**
 * @file photoresistor_test.ino
 * @author Scott Chow
 * @brief Adapted from SparkFun Inventor's Kit
 * Example sketch 06
 * PHOTORESISTOR
 *  Use a photoresistor (light sensor) to control the brightness
 *  of a LED.
 *
 * Hardware connections:
 *  Photo resistor:
 *
 *  Connect one side of the photoresistor to 5 Volts (5V).
 *  Connect the other side of the photoresistor to ANALOG pin 0.
 *  Connect a 10K resistor between ANALOG pin 0 and GND.
 *
 *  This creates a voltage divider, with the photoresistor one
 *  of the two resistors. The output of the voltage divider
 *  (connected to A0) will vary with the light level.
 *
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * This code is completely free for any use.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 *
 * Version 2.0 6/2012 MDG
 */

const int sensorPin = A0;

// We'll also set up some global variables for the light level:

int lightLevel;
// light levels calibrated based on 10k resistor
int high = 0;  // lower than this the light is off
int low = 550; // greater than this the light is on

// room light off
// room light on 670

void setup()
{
  //   pinMode(sensorPin, INPUT);// Set pResistor - A0 pin as an input (optional)
  Serial.begin(9600);
  //   Serial.println("Test print");
}

void loop()
{
  lightLevel = analogRead(sensorPin);
  Serial.println(lightLevel);
  delay(1000);
}
