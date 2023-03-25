void photoresistor_setup(int pin){
    pinMode(pin, INPUT);
    Serial.begin(9600);
}

void photoresistor_loop(int pin){
    lightLevel = analogRead(pin);
    Serial.println(lightLevel);
}
