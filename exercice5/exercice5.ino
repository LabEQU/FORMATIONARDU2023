// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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
  lcd.createChar(0, Ohm);
  // put your setup code here, to run once:
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
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
  delay(900);
}
