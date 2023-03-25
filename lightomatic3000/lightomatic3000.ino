#include <Servo.h>

// Servo variables
Servo servo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int press_angle = 10; // how much the servo should turn to press the button

// Room state variables
bool switch_on = false; 
bool lights_dimming = false;
bool lights_off = false;

// Photoresistor light detection variables
// light levels calibrated based on 10k resistor running off of 3.3v
int lightLevel;
int threshold_dimming = 500; //threshold for the room lights to be considered dimming
int threshold_off = 400; // threshold for the room lights to be considered off

// Pin Inputs
const int switch_pin = 8; 
const int photoresistor_pin = A0;
// Pin Outputs
const int status_led = LED_BUILTIN; // 13 is built in LED
const int servo_pin = 12;

void setup() {
  servo_setup(servo_pin);
  photoresistor_setup(photoresistor_pin);
  switch_setup(switch_pin, status_led);
}

void loop() {
  photoresistor_loop(photoresistor_pin); // check room status
  switch_loop(switch_pin, status_led); // check if switch is on
  
  lights_dimming = lightLevel <= threshold_dimming;
  lights_off = lightLevel <= threshold_off;
  
  // if the switch is on, and the room is dark, press the button
  if (switch_on){
    Serial.println("Switch on");
    if (lights_dimming | lights_off){
      press_button(press_angle);
      Serial.println("Dimming/Off: Pressed button once");
      // If the room is only dimming, double press to turn in back on
      if (!lights_off){
          delay(1000);
          press_button(press_angle);
          Serial.println("Dimming: Pressed button second");
      }
    }
  }
  delay(1000*5); // wait 5 seconds
}
