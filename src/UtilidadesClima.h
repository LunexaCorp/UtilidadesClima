#ifndef UTILIDADES_CLIMA_H
#define UTILIDADES_CLIMA_H

#include <Arduino.h>

String convertirDeCelsiusA(int unidad, bool incluirGrado, float temperatura);
float calcularPuntoRocio(float tempC, float humedadRel);
float calcularHumedadAbsoluta(float tempC, float humedadRel);
float calcularSensacionTermica(float tempC, float humedadRel);
float calcularBulboHumedo(float tempC, float humedadRel);
float calcularPresionVapor(float tempC, float humedadRel);
float calcularPresionSaturacion(float tempC);

// Códigos para conversión de temperatura
#define FAHRENHEIT 1
#define KELVIN 2
#define RANKINE 3

#endif
