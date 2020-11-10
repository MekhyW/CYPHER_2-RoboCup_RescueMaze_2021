void setup() {
  Serial.begin(9600);
  for(int i=2; i<=13; i++){
    pinMode(i, OUTPUT);
    analogWrite(i, 150);
  }
}

void loop() {
  
}
