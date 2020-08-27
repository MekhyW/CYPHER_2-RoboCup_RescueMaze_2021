#include <DueFlashStorage.h>
DueFlashStorage dueFlashStorage;
byte x = 0;

void setup() {
  Serial.begin(9600);
  x = dueFlashStorage.read(0);
}

void loop() {
  for(int i = 0; i < 7202 ; i++){
    //dueFlashStorage.write(i, x);
    x = dueFlashStorage.read(i); 
  }
  //Serial.println(x);
  //x += 5;
  Serial.println("OK");
  delay(500);
}
