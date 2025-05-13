# 🌤️ UtilidadesClima

**UtilidadesClima** es una librería para Arduino que permite realizar cálculos climáticos comunes basados en la temperatura y humedad relativa.

## 📦 Instalación

1. Descarga este repositorio como ZIP o clónalo.
2. Copia la carpeta `UtilidadesClima` en el directorio de librerías de tu Arduino:
   - Windows: `Documentos/Arduino/libraries/`
   - macOS/Linux: `~/Arduino/libraries/`
3. Reinicia el IDE de Arduino si estaba abierto.

---

## 📚 [Funciones disponibles](#funciones-disponibles)

| Función                                                    | Descripción                                                |
|------------------------------------------------------------|------------------------------------------------------------|
| `float calcularPuntoRocio(float tempC, float humedadRel)`   | Devuelve el punto de rocío en °C                             |
| `float calcularSensacionTermica(float tempC, float humedadRel)` | Calcula el índice de calor en °C                          |
| `float calcularHumedadAbsoluta(float tempC, float humedadRel)` | Devuelve la humedad absoluta en g/m³                        |
| `float calcularBulboHumedo(float tempC, float humedadRel)`  | Calcula la temperatura de bulbo húmedo en °C               |
| `float calcularPresionSaturacion(float tempC)`             | Devuelve la presión de saturación en hPa                    |
| `float calcularPresionVapor(float tempC, float humedadRel)` | Devuelve la presión de vapor en hPa                         |
| `String convertirDeCelsiusA(int unidad, bool incluirGrado, float temperatura)` | Convierte la temperatura de °C a otra unidad              |

## 🧾 [Constantes disponibles](#constantes-disponibles)

Puedes usar las siguientes constantes para la función `convertirDeCelsiusA()`:

```cpp
#define FAHRENHEIT 1
#define KELVIN     2
#define RANKINE    3
```

👤 **Autor principal:** Yohan Nikel  
🚀 **Proyecto desarrollado dentro de la organización** [LunexaCorp](https://github.com/LunexaCorp)