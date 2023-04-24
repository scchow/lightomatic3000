#include <Servo.h>

bool debug = true;
bool plot = true;
int baud_rate = 9600;

// Servo variables
Servo servo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int press_angle = 20; // how much the servo should turn to press the button

// Room state variables
bool switch_on = false; 
bool lights_dimming = false;
bool lights_off = false;

// Photoresistor light detection variables
// light levels calibrated based on 10k resistor running off of 5V
// Estimated based on 3.3V values (should be about 1.5x the 3.3V values)
int lightLevel = 0;
int threshold_dimming = 800; //threshold for the room lights to be considered dimming (525*1.515)
int threshold_off = 600; // threshold for the room lights to be considered off (400*1.515)

// Pin Inputs
const int switch_pin = 2; 
const int photoresistor_pin = A7;
// Pin Outputs
const int servo_pin = 3;
const int status_led = LED_BUILTIN; // 13 is built in LED

void setup() {
  servo_setup(servo_pin);
  photoresistor_setup(photoresistor_pin);
  switch_setup(switch_pin, status_led);
  if (debug){
    Serial.begin(baud_rate);
  }
  delay(1000*3); // wait 3 seconds before starting
}

void loop() {
  photoresistor_loop(photoresistor_pin, debug); // check room status
  switch_loop(switch_pin, status_led); // check if switch is on
  
  lights_dimming = lightLevel <= threshold_dimming;
  lights_off = lightLevel <= threshold_off;
  
  // if the switch is on, and the room is dark, press the button
  if (switch_on){
    if (debug){
      Serial.println("Switch on");
    }
    // if lights are dimming give it 1 second to see if it is actually off
    if (lights_dimming){
      delay(2);
      photoresistor_loop(photoresistor_pin, debug); // check room status
      lights_dimming = lightLevel <= threshold_dimming;
      lights_off = lightLevel <= threshold_off;
    }
    if (lights_dimming | lights_off){
      press_button(press_angle);

      // If the room is only dimming, double press to turn in back on
      if (!lights_off){
        delay(1000);
        press_button(press_angle);
        if (debug){
          Serial.println("Lights/Dimming: Double Press");
        }
      }
      else{
        if (debug){
          Serial.println("Lights/Off: Single Press");
        }
      }
      delay(1000*3); // wait 5 seconds
    }
  }
  delay(1000); // Run at 1Hz
}
