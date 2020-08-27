#define ReflectionAPin A6
#define ReflectionBPin A7
float ReflectLeft=100;
float ReflectRight=100;
#include <Nextion.h>
NexNumber n0 = NexNumber(0, 2, "n0");

void ReadReflection(){
  ReflectLeft = (ReflectLeft*0)+(ReflectRight*0.3)+(analogRead(ReflectionAPin)*0.7);
  ReflectRight = (ReflectRight*0)+(ReflectLeft*0.3)+(analogRead(ReflectionBPin)*0.7);
}

void setup() {
  Serial.begin(9600);
  pinMode(ReflectionAPin, INPUT);
  pinMode(ReflectionBPin, INPUT);
  nexInit();
}

void loop() {
  ReadReflection();
  Serial.print(ReflectLeft);
  Serial.print("   ");
  Serial.print(ReflectRight);
  Serial.print("   ");
  Serial.println((ReflectLeft+ReflectRight)/2);
  n0.setValue((ReflectLeft+ReflectRight)/2);
}
