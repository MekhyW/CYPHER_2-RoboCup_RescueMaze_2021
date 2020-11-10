#define ReflectionAPin A6
#define ReflectionBPin A7
float ReflectLeft=100;
float ReflectRight=100;

void ReadReflection(){
  ReflectLeft = (ReflectRight*0.5)+(analogRead(ReflectionAPin)*0.5);
  ReflectRight = (ReflectLeft*0.5)+(analogRead(ReflectionBPin)*0.5);
}

void setup() {
  Serial.begin(9600);
  pinMode(ReflectionAPin, INPUT);
  pinMode(ReflectionBPin, INPUT);
}

void loop() {
  ReadReflection();
  Serial.print(ReflectLeft);
  Serial.print("   ");
  Serial.println(ReflectRight);
}
