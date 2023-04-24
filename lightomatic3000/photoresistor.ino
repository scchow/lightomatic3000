void photoresistor_setup(int pin){
  pinMode(pin, INPUT);// Set photorestor pin pin as an input
  Serial.begin(9600);
}

void photoresistor_loop(int pin, bool debug){
  lightLevel = analogRead(pin);
}
