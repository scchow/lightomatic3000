#include <Servo.h>

// Serial Comms variables
bool debug = true;
bool plot = true;
int baud_rate = 9600;

// Servo variables
Servo servo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int press_angle = 40; // how much the servo should turn to press the button

// Room state variables
static bool switch_on = false; 
static bool lights_dimming = false;
static bool lights_off = false;

// Photoresistor light detection variables
// light levels calibrated based on 10k resistor running off of 5V
// Estimated based on 3.3V values (should be about 1.5x the 3.3V values)
int lightLevel = 0;
int threshold_dimming = 825; //threshold for the room lights to be considered dimming (525*1.515)
int threshold_off = 600; // threshold for the room lights to be considered off (400*1.515)

// Pin Inputs
const int switch_pin = 2; 
const int photoresistor_pin = A7;
// Pin Outputs
const int servo_pin = 3;
const int status_led = LED_BUILTIN; // 13 is built in LED

void update_light_status(){
  photoresistor_loop(photoresistor_pin, debug); // check room status
  lights_off = lightLevel <= threshold_off;
  lights_dimming = !lights_off & (lightLevel <= threshold_dimming);
  if (plot){
    Serial.print("lights_off:");
    Serial.print(1000 * (int) lights_off);
    Serial.print(",");
    Serial.print("lights_dimming:");
    Serial.println(1000 * (int) lights_dimming);
  }
}

void update_switch_status(){
  switch_loop(switch_pin, status_led); // check if switch is on
  // If we are plotting, print switch status in 
  // plottable format
  if (plot){
    // Multiply by 1000 to make switch show up on plot with light level
    Serial.print("switch:");
    Serial.println(1000 * (int)switch_on);
  }
  // Otherwise just print status message as normal
  else if (debug) {
    Serial.print("switch: ");
    Serial.println(switch_on ? "on" : "off");
  }
}

void setup() {
  servo_setup(servo_pin);
  photoresistor_setup(photoresistor_pin);
  switch_setup(switch_pin, status_led);
  if (debug | plot){
    Serial.begin(baud_rate);
  }
  delay(1000*3); // wait 3 seconds before starting
}

void loop() {
  update_switch_status();
  update_light_status();

  // if the switch is on, and the room is dark, press the button
  if (switch_on){
    // if lights are dimming give it 2 seconds to see if it is actually off
    // because someone pressed the light switch
    if (lights_dimming){
      delay(2000);
      update_light_status();
    }
    if (lights_dimming | lights_off){
      press_button(press_angle);

      // If the room is only dimming, double press to turn in back on
      if (lights_dimming){
        delay(1.5*1000);
        press_button(press_angle);
        // Only print light status message if we are not plotting
        if (debug & !plot){
          Serial.println("Lights/Dimming: Double Press");
        }
      }
      else{
        // Only print light status message if we are not plotting
        if (debug & !plot){
          Serial.println("Lights/Off: Single Press");
        }
      }
      // delay(1000*3); // wait 5 seconds
    }
  }
  delay(1000); // Run at 1Hz
}
