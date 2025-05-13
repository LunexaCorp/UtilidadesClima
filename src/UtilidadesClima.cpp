#include "UtilidadesClima.h"
#include <math.h>

String convertirDeCelsiusA(int unidad, bool incluirGrado, float temperatura){
  String grado;
  float conversion;

  if(unidad == FAHRENHEIT){
    conversion = temperatura * 9.0 / 5.0 + 32;
    grado = "°F";
  } else {
    conversion = temperatura + 273.15;
    if(unidad == KELVIN) grado = "K";
    else if(unidad == RANKINE){
      conversion *= 9.0 / 5.0;
      grado = "°R";
    }
  }

  if(incluirGrado) return String(conversion) + " " + grado;
  else return String(conversion);
}

float calcularPuntoRocio(float tempC, float humedadRel) {
  float a = 17.62;
  float b = 243.12;
  float gamma = (a * tempC) / (b + tempC) + log(humedadRel / 100.0);
  return (b * gamma) / (a - gamma);
}

float calcularPresionSaturacion(float tempC) {
  return 6.112 * exp((17.67 * tempC) / (tempC + 243.5));
}

float calcularPresionVapor(float tempC, float humedadRel) {
  return calcularPresionSaturacion(tempC) * (humedadRel / 100.0);
}

float calcularHumedadAbsoluta(float tempC, float humedadRel) {
  float Pv = calcularPresionVapor(tempC, humedadRel);
  return (Pv * 2.1674) / (273.15 + tempC); // g/m³
}

float calcularSensacionTermica(float tempC, float humedadRel) {
  float tempF = tempC * 9.0 / 5.0 + 32;
  float HI = -42.379 + 2.04901523 * tempF + 10.14333127 * humedadRel
             - 0.22475541 * tempF * humedadRel - 0.00683783 * pow(tempF, 2)
             - 0.05481717 * pow(humedadRel, 2) + 0.00122874 * pow(tempF, 2) * humedadRel
             + 0.00085282 * tempF * pow(humedadRel, 2) - 0.00000199 * pow(tempF, 2) * pow(humedadRel, 2);
  return (HI - 32) * 5.0 / 9.0; // °C
}

float calcularBulboHumedo(float tempC, float humedadRel) {
  return tempC * atan(0.151977 * sqrt(humedadRel + 8.313659)) +
         atan(tempC + humedadRel) - atan(humedadRel - 1.676331) +
         0.00391838 * pow(humedadRel, 1.5) * atan(0.023101 * humedadRel) -
         4.686035;
}
