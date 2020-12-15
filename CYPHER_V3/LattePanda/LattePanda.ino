int Command = 0;
int LastCommand = 99;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0){
    Command = Serial.read();
  }
  if(Command != LastCommand){
    if(Command == 0){
        for(int i=2; i<=13; i++){
          pinMode(i, OUTPUT);
          digitalWrite(i, LOW);
        }
    } else if (Command == 1){
        for(int i=2; i<=13; i++){
          pinMode(i, OUTPUT);
          digitalWrite(i, HIGH);
        }
    }
  }
  LastCommand = Command;
}
