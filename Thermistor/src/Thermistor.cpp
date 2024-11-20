#include "Thermistor.h"
#include <math.h>

Thermistor::Thermistor(double Rref, double R0, double Beta, unsigned samplingBitsNumber, double Vcc, double T0) 
{
    this->Rref = Rref;
    this->R0 = R0;
    this->Beta = Beta;
    this->T0 = T0;
    this->Vcc = Vcc;
    this->samplingBitsNumber = samplingBitsNumber;
}

// GET TEMPERATURE (unit : 'K' for Kelvin, 'C' for Celsius, 'F' for Fahrenheit)
double Thermistor::getTemperature(double adc, char unit) 
{
    
    double Vout = (adc / (pow(2, samplingBitsNumber) - 1)) * Vcc;
    double Rt = R0 * ((Vcc / Vout) - 1);
    double T = 1 / ((1 / T0) + (1 / Beta) * log(Rt / Rref));

    
    switch (unit) {
        case 'C': // Celsius
            return T - ZERO_CELSIUS;
        case 'F': // Fahrenheit
            return (T - ZERO_CELSIUS) * 9 / 5 + 32;
        case 'K': // Kelvin
        default:
            return T;
    }
}
