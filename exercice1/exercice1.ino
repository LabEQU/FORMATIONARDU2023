/**
* fonction d'attente serie pour la saisie
* @param msTimeout ms de timeout pour l'attente
*/
void waitSerialUntilNotAvailable(uint16_t msTimeout=15000) {
  uint16_t counter=0;
  Serial.flush();
  while(Serial.available()==0 && counter < msTimeout) {
    counter+=300;
    delay(300);}
}
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.println("Demat Breizh, \n votre nom : ");
 waitSerialUntilNotAvailable();
char nameStr[10]="NONAME"; 
 if(Serial.available() > 0) {
  Serial.readBytesUntil('\n',nameStr,10);
} else{
  Serial.println("je n'ai pas votre nom");
 }
Serial.println(nameStr);
}

void loop() {
  // put your main code here, to run repeatedly:

}
