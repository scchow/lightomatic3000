void photoresistor_setup(int pin){
  pinMode(pin, INPUT);
}

void photoresistor_loop(int pin, bool debug){
  lightLevel = analogRead(pin);
  if (debug){
    Serial.println(lightLevel);
  }
}
