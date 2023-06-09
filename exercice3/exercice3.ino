#define PIN_GREEN 4
#define PIN_YELLOW 5
#define PIN_RED 6
#define PIN_BUTTON 2

#define PIN_POT A5
/**
*temps minimum d'allumage du feux piéton
*/
#define TEMPS_MIN 2000
/**
*temps maximum d'allumage du feux piéton
*/
#define TEMPS_MAX 10000


/**
* get ration of DAC
* @param adcValue
* @param vRef
* @return ADCRatio
*/
float getADCRatio(uint16_t adcValue, float vRef = 5) {
  return (vRef / 1024.0F) * (float)adcValue;
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}



// the loop function runs over and over again forever
void loop() {
  int buttonState = digitalRead(PIN_BUTTON);
  if (buttonState > 0) {
    Serial.println("button activated");
    int potValue = analogRead(PIN_POT);
    long timeToWaitOnRed=map(potValue, 0, 1023, TEMPS_MIN, TEMPS_MAX);
    Serial.print("Time on red (ms) : ");
    Serial.println(timeToWaitOnRed);
    // float voltageValue = getADCRatio(potValue);
    // Serial.print("voltage value : ");
    // Serial.println(voltageValue);
    digitalWrite(PIN_GREEN, HIGH);
    delay(500);
    digitalWrite(PIN_GREEN, LOW);
    digitalWrite(PIN_YELLOW, HIGH);
    delay(500);
    digitalWrite(PIN_YELLOW, LOW);
    digitalWrite(PIN_RED, HIGH);
    delay(timeToWaitOnRed);
    digitalWrite(PIN_RED, LOW);
  } else {
    Serial.println("not activated");
  }
  delay(1000);
}
