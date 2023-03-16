#include <DS1307RTC.h>
#include <Timelib.h>

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
#include "tft_positions.h"

// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 8  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9

// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB);
  setupScreen();
  delay(900);
  readAndShowDateTime();
}

void loop() {
  makeBandeau();
  readAndShowDateTime();
  delay(1000);
}
