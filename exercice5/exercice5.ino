#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define R1 2000
#define R2 560
#define PIN_Volt A0

#define MAX_VOLTS_INPUT 22.857F
#define RATIO_VOLT (float)(22.857F / 5.0F)
#define RATIO_ADC (float)(5.0F / 1024.0F)

float calculateVin(uint16_t vADC) {
  return RATIO_ADC * (float)vADC * RATIO_VOLT;
}

byte Ohm[8] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,
  B11011,
};

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, Ohm);
  lcd.setCursor(5, 0);
  lcd.write(byte(0));
  lcd.print("RSYS");
  lcd.setCursor(0, 1);
  lcd.print("Voltmetre");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("         ");
  lcd.setCursor(0, 0);
  lcd.print("Tension en A0 : ");
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 1);
  lcd.print(calculateVin(analogRead(PIN_Volt)));
  lcd.print(" V");
  delay(900);
}
