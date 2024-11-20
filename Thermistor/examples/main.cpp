#include <Arduino.h>
#include "Thermistor.h"

Thermistor thermistor(10000, 12000, 3950, 10, 5.0, 298.15); 

void setup() {
    Serial.begin(9600);
    Serial.println("Programme de mesure de température démarré.");
}

void loop() {
    int adcValue = analogRead(A0);

    double temperature = thermistor.getTemperature(adcValue, 'C');

    Serial.print("Température mesurée : ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(5000);
}