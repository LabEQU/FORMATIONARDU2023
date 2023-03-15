#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 8  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9

// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setupScreen() {
  tft.setCursor(20, 30);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_BLUE);
  tft.print("ORSYS");
  tft.setCursor(30, 80);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_RED);
  tft.print("Volt");
  tft.setCursor(25, 100);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_RED);
  tft.print("metre");
  tft.setCursor(40, 150);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_GREEN);
  tft.print("copyright 2023");
}

void displayScreen() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(20, 30);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_RED);
  tft.print("TENSION");
  tft.setCursor(30, 50);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_RED);
  tft.print("en A0");
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  setupScreen();
  delay(1000);
  displayScreen();
}
void loop() {
}