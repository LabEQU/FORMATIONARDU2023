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

#define R1 2000
#define R2 560
#define PIN_Volt A0

#define MAX_VOLTS_INPUT 22.857F
#define RATIO_VOLT (float)(MAX_VOLTS_INPUT / 5.0F)
#define RATIO_ADC (float)(5.0F / 1024.0F)

float calculateVin(uint16_t vADC) {
  float r = 5.0F / 1024.0F * (float)vADC * RATIO_VOLT;
  return r;
}

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

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  setupScreen();
  delay(1000);
  tft.fillScreen(TFT_BACK_COLOR);
  makeCadre(CADRE_A0_X,CADRE_A0_Y,CADRE_GENERIC_W,CADRE_GENERIC_H,"V en A0");
  makeCadre(CADRE_A1_X,CADRE_A1_Y,CADRE_GENERIC_W,CADRE_GENERIC_H,"V en A0");
}
void loop() {
 setFloatValueInCadre(CADRE_A0_X,CADRE_A0_Y,CADRE_GENERIC_W,CADRE_GENERIC_H, calculateVin(analogRead(PIN_Volt)), CADRE_GENERIC_VALUE_PRECISION);
 setFloatValueInCadre(CADRE_A1_X,CADRE_A1_Y,CADRE_GENERIC_W,CADRE_GENERIC_H, calculateVin(analogRead(A1)), CADRE_GENERIC_VALUE_PRECISION);
  delay(900);
}