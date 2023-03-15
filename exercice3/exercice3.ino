#define PIN_GREEN 4
#define PIN_YELLOW 5
#define PIN_RED 6
#define PIN_BUTTON 2

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  bool buttonState=digitalRead(PIN_BUTTON);
  if(buttonState>0){
  digitalWrite(PIN_GREEN, HIGH); 
  delay(500);                 
  digitalWrite(PIN_GREEN, LOW); 
  digitalWrite(PIN_YELLOW, HIGH); 
  delay(500);                 
  digitalWrite(PIN_YELLOW, LOW); 
  digitalWrite(PIN_RED, HIGH); 
  delay(1000);                 
  digitalWrite(PIN_RED, LOW);      
  }
  else{
  Serial.println("not activated");
  }
delay(1000);
}
