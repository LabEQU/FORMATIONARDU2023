#ifdef HUMIDITY_SENSOR
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setupHumidity() {
  Serial.begin(9600);
  dht.begin();
}


bool readHumidity() {
  sensorsValues.humidity = dht.readHumidity();
  return true;
}
#endif