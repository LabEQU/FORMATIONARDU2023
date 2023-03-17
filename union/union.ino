#include "struct.h"
struct Datas sdata;
void setup() {
  Serial.begin(9600);
// put your setup code here, to run once:
#ifdef EMITTER
  setupValues();
#endif
}

void loop() {
// put your main code here, to run repeatedly:
#ifdef EMITTER

  emit();
#endif
#ifdef RECIEVER
  recieve();
#endif
}
#ifdef EMITTER
void setupValues() {
  sdata.humidity = 70;
  sdata.temperature = 26.2F;
  strcpy(sdata.message, "Hello Lucas");
}

void emit() {
  while (!Serial.available()) { delay(50); }
  char c = Serial.read();
  if (c == 'o') {
    U_Datas ud;
    ud.datas = sdata;
    for (int i = 0; i < sizeof(struct Datas); i++) {
      Serial.write(ud.data8[i]);
    }
    delay(1000);
  };
  Serial.flush();
}
#endif
#ifdef RECIEVER
void recieve() {
  // while (!Serial.available()) { Serial.read(); }
  //delay(100);
  uint8_t i = 0;
  while(!Serial.available() &&i<sizeof(struct Datas) ;
}
{
  ud.data8[i] = Serial.read();
  i++;
};
Serial.print("humidite : ");
Serial.println(ud.datas.humidity);
Serial.print("temperature : ");
Serial.println(ud.datas.temperature);
Serial.print("message : ");
Serial.println(ud.datas.message);
}
#endif