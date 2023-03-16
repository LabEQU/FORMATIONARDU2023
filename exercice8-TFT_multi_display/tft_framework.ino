#include "tft_positions.h"


void makeBandeau() {
  tft.fillScreen(TFT_BACK_COLOR);
  tft.fillRect(0, 0, tft.width(), 10, ST77XX_PINK);
  tft.fillRect(tft.width() / 2 - 20, 0, 40, 10, ST77XX_PINK);
}

void writeDateTime(tmElements_t tm) {
  char buffer[11];
  tft.setCursor(2, 10);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  sprintf(buffer, "%02d/%02d/%d", tm.Day, tm.Month, tmYearToCalendar(tm.Year));
  tft.setCursor(tft.width() / 2 - 2, 16);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  sprintf(buffer, "%02d:%02d", tm.Hour, tm.Minute);
}

void setupScreen() {
  tft.fillScreen(TFT_BACK_COLOR);
  tft.setCursor(20, 30);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_BLUE);
  tft.print("ORSYS");
  tft.setCursor(30, 80);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_RED);
  tft.print("Demo");
  tft.setCursor(40, 150);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_GREEN);
  tft.print("copyright 2023");
}
void makeCadre(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *title) {
  tft.setCursor(x + CADRE_FROMREF_TITLE_X, y + CADRE_FROMREF_TITLE_Y);
  tft.setTextSize(CADRE_TITLE_SIZE);
  tft.setTextColor(CADRE_TITLE_COLOR);
  tft.print(title);
  tft.drawRect(
    x + CADRE_FROMREF_VALUE_RECT_X,
    y + CADRE_FROMREF_VALUE_RECT_Y,
    w - CADRE_FROMREF_VALUE_RECT_X * 2,
    h - CADRE_FROMREF_VALUE_RECT_Y - 2,
    CADRE_TITLE_COLOR);
  setFloatValueInCadre(x, y, w, h, 0.0F, 2);
}
void setFloatValueInCadre(uint8_t x, uint8_t y, uint8_t w, uint8_t h, float value, uint8_t precision) {
  char buffer[precision + 4];
  tft.fillRect(
    x + CADRE_FROMREF_VALUE_RECT_X,
    y + CADRE_FROMREF_VALUE_RECT_Y,
    w - CADRE_FROMREF_VALUE_RECT_X * 2,
    h - CADRE_FROMREF_VALUE_RECT_Y - 2,
    CADRE_TITLE_COLOR);
  tft.setCursor(x + CADRE_FROMREF_VALUE_X, y + CADRE_FROMREF_VALUE_Y);
  tft.setTextSize(CADRE_VALUE_SIZE);
  tft.setTextColor(CADRE_VALUE_COLOR);
  tft.print(dtostrf(value, 2, precision, buffer));
}
