#include <UtilidadesClima.h>
#include <DHT.h>

// Configuración del sensor DHT
#define DHT_PIN 19
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000); // Esperar al inicio
}

void loop() {
  float tempC = dht.readTemperature();
  float humedad = dht.readHumidity();

  if (isnan(tempC) || isnan(humedad)) {
    Serial.println("Error al leer del sensor DHT");
    delay(2000);
    return;
  }

  Serial.println("📡 Datos del sensor:");
  Serial.printf("  - Temperatura: %.2f °C\n", tempC);
  Serial.printf("  - Humedad relativa: %.2f %%\n", humedad);

  float puntoRocio = calcularPuntoRocio(tempC, humedad);
  float sensTermica = calcularSensacionTermica(tempC, humedad);
  float humedadAbs = calcularHumedadAbsoluta(tempC, humedad);
  float presionSat = calcularPresionSaturacion(tempC);
  float presionVap = calcularPresionVapor(tempC, humedad);
  float bulboHumedo = calcularBulboHumedo(tempC, humedad);

  Serial.println("🧪 Cálculos climáticos:");
  Serial.printf("  - Punto de rocío: %.2f °C\n", puntoRocio);
  Serial.printf("  - Sensación térmica: %.2f °C\n", sensTermica);
  Serial.printf("  - Humedad absoluta: %.2f g/m³\n", humedadAbs);
  Serial.printf("  - Presión de saturación: %.2f hPa\n", presionSat);
  Serial.printf("  - Presión de vapor: %.2f hPa\n", presionVap);
  Serial.printf("  - Temperatura de bulbo húmedo: %.2f °C\n", bulboHumedo);

  Serial.println("🌡️ Conversiones de temperatura:");
  Serial.println("  - Fahrenheit: " + convertirDeCelsiusA(FAHRENHEIT, true, tempC));
  Serial.println("  - Kelvin: " + convertirDeCelsiusA(KELVIN, true, tempC));
  Serial.println("  - Rankine: " + convertirDeCelsiusA(RANKINE, true, tempC));

  Serial.println("\n------------------------------\n");

  delay(5000); // Esperar antes de la siguiente lectura
}
