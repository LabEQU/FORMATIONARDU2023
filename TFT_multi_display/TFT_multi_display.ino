#include <DS1307RTC.h>
#include <Timelib.h>
#include "config.h"
#include "structure.h"

struct SensorsValues sensorsValues;


void setup() {
#ifdef OUTPUT_ACTIONNER
  setupOutput();
#endif
#ifdef PRESSURE_SENSOR
  setupPressureUnit();
#endif
#ifdef TEMPERATURE_SENSOR
  setupTemperature();
#endif
#ifdef HUMIDITY_SENSOR
  setupHumidity();
#endif
#ifdef SD_WRITE
  setupSD();
#endif
  delay(900);
  //tft.fillScreen(TFT_BACKGROUND_COLOR);
  readAndShowDatetime();
}

void loop() {
  readAndShowDatetime();
#ifdef PRESSURE_SENSOR
  readPressure();
#endif
#ifdef TEMPERATURE_SENSOR
  readTemperature();
#endif
#ifdef HUMIDITY_SENSOR
  readHumidity();
#endif
#ifdef OUTPUT_ACTIONNER
  loopOutput();
#endif
#ifdef SD_WRITE
  writeSD();
#endif
  delay(1000);
}
