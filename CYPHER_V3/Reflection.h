#define ReflectionAPin A6
#define ReflectionBPin A7
#define TrapLimit 1000
float ReflectLeft=100;
float ReflectRight=100;

void ReflectionInitialize(){
	pinMode(ReflectionAPin, INPUT);
	pinMode(ReflectionBPin, INPUT);
}

void ReadReflection(){
  ReflectLeft = (analogRead(ReflectionAPin)*0.7)+(ReflectRight*0.3);
  ReflectRight = (analogRead(ReflectionBPin)*0.7)+(ReflectLeft*0.3);
}
