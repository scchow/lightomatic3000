const int sensorPin = A0;

int lightLevel;
// light levels calibrated based on 10k resistor
int threshold = 500; // lower than this the light is off
//bool room_lit = true; // defined in main

void photoresistor_setup(){
   pinMode(sensorPin, INPUT);// Set pResistor - A0 pin as an input (optional)
//   Serial.begin(9600);
//   Serial.println("Test print");
}

void photoresistor_loop(){
  lightLevel = analogRead(sensorPin);
  room_lit = lightLevel >= threshold;
}
