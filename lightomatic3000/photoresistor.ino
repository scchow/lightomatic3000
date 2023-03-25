void photoresistor_setup(int pin){
   pinMode(pin, INPUT);// Set pResistor - A0 pin as an input (optional)
  Serial.begin(9600);
//   Serial.println("Test print");
}

void photoresistor_loop(int pin){
  lightLevel = analogRead(pin);
  Serial.println(lightLevel);
}
