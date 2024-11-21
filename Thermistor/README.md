# Thermistor Library

## Author
**Maxence Liegeois**  

## Description
This library allows users to easily measure temperature using an NTC thermistor connected to a microcontroller, such as an Arduino. It provides methods for converting analog readings into temperature values in Celsius, Fahrenheit, or Kelvin.  

## Circuit Diagram

![image](https://github.com/user-attachments/assets/725b62f3-e7f8-4755-89b2-59d0849bc9de)


### Explanation of the Circuit  
1. **Thermistor (NTC)**: A resistor whose resistance decreases as temperature increases.  
2. **Fixed Resistor (\( R_0 \))**: Used in series with the thermistor to form a voltage divider.  
3. **Voltage Divider**: The midpoint voltage is read by the analog input of the Arduino.  

#### Key Points:  
- The thermistor is connected to \( V_{cc} \) and \( R_0 \), with the midpoint voltage sent to pin **A0** of the Arduino.  
- \( V_{out} \) is calculated as:  
  \[
  V_{out} = V_{cc} \times \frac{R_t}{R_t + R_0}
  \]  
  Where \( R_t \) is the resistance of the thermistor, dependent on the temperature.  

## Usage Example

### Example Code
Below is a sample program to measure and display the temperature every 5 seconds:  

```cpp
#include <Arduino.h>
#include "Thermistor.h"

// Configure the thermistor and circuit parameters
Thermistor thermistor(10000, 10000, 3950, 10, 5.0, 298.15);

void setup() {
    Serial.begin(9600);
    Serial.println("Thermistor temperature measurement program started.");
}

void loop() {
    // Read analog value from pin A0
    int adcValue = analogRead(A0);

    // Calculate temperature in Celsius
    double temperature = thermistor.getTemperature(adcValue, 'C');

    // Print temperature to the Serial Monitor
    Serial.print("Measured Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // Wait 5 seconds
    delay(5000);
}
