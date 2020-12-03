#include <Servo.h>
#define DeployerPin 26
Servo Deployer;
#define motorUR 9
#define motorURdirA 8
#define motorURdirB 7
#define motorLR 4
#define motorLRdirA 5
#define motorLRdirB 6
#define motorUL 10
#define motorULdirA 11
#define motorULdirB 12
#define motorLL 3
#define motorLLdirA 28
#define motorLLdirB 2
#define motorUR_ENABLE 52
#define motorLR_ENABLE 24
#define motorUL_ENABLE 39
#define motorLL_ENABLE 33
int KitCounter=12;

void MotorsRelease(){
  digitalWrite(motorULdirA, LOW);
  digitalWrite(motorULdirB, LOW);
  digitalWrite(motorURdirA, LOW);
  digitalWrite(motorURdirB, LOW);
  digitalWrite(motorLLdirA, LOW);
  digitalWrite(motorLLdirB, LOW);
  digitalWrite(motorLRdirA, LOW);
  digitalWrite(motorLRdirB, LOW);
}

void MotorsStop(){
  digitalWrite(motorULdirA, HIGH);
  digitalWrite(motorULdirB, HIGH);
  digitalWrite(motorURdirA, HIGH);
  digitalWrite(motorURdirB, HIGH);
  digitalWrite(motorLLdirA, HIGH);
  digitalWrite(motorLLdirB, HIGH);
  digitalWrite(motorLRdirA, HIGH);
  digitalWrite(motorLRdirB, HIGH);
}

void MotorsInitialize(){
  Deployer.attach(DeployerPin);
  Deployer.write(100);
  pinMode(motorUL, OUTPUT);
  pinMode(motorULdirA, OUTPUT);
  pinMode(motorULdirB, OUTPUT);
  pinMode(motorLL, OUTPUT);
  pinMode(motorLLdirA, OUTPUT);
  pinMode(motorLLdirB, OUTPUT);
  pinMode(motorUR, OUTPUT);
  pinMode(motorURdirA, OUTPUT);
  pinMode(motorURdirB, OUTPUT);
  pinMode(motorLR, OUTPUT);
  pinMode(motorLRdirA, OUTPUT);
  pinMode(motorLRdirB, OUTPUT);
  pinMode(motorUR_ENABLE, OUTPUT);
  pinMode(motorLR_ENABLE, OUTPUT);
  pinMode(motorUL_ENABLE, OUTPUT);
  pinMode(motorLL_ENABLE, OUTPUT);
  digitalWrite(motorUR_ENABLE, HIGH);
  digitalWrite(motorLR_ENABLE, HIGH);
  digitalWrite(motorUL_ENABLE, HIGH);
  digitalWrite(motorLL_ENABLE, HIGH);
  MotorsStop();
}

void URForward(){
  digitalWrite(motorURdirA, HIGH);
  digitalWrite(motorURdirB, LOW);
}

void URBackwards(){
  digitalWrite(motorURdirA, LOW);
  digitalWrite(motorURdirB, HIGH);
}

void ULForward(){
  digitalWrite(motorULdirA, HIGH);
  digitalWrite(motorULdirB, LOW);
}

void ULBackwards(){
  digitalWrite(motorULdirA, LOW);
  digitalWrite(motorULdirB, HIGH);
}

void LRForward(){
  digitalWrite(motorLRdirA, HIGH);
  digitalWrite(motorLRdirB, LOW);
}

void LRBackwards(){
  digitalWrite(motorLRdirA, LOW);
  digitalWrite(motorLRdirB, HIGH);
}

void LLForward(){
  digitalWrite(motorLLdirA, HIGH);
  digitalWrite(motorLLdirB, LOW);
}

void LLBackwards(){
  digitalWrite(motorLLdirA, LOW);
  digitalWrite(motorLLdirB, HIGH);
}


void MoveForward(int speed){
  ULForward();
  LLForward();
  URForward();
  LRForward();
  analogWrite(motorUL, speed);
  analogWrite(motorLL, speed);
  analogWrite(motorUR, speed);
  analogWrite(motorLR, speed);
}

void MoveForwardPID(int speed){
  ULForward();
  LLForward();
  URForward();
  LRForward();
  CalculatePID();
  if(ConservativePID==false){
    analogWrite(motorUL, constrain(speed-PID_value, 0, 250));
    analogWrite(motorLL, constrain(speed-PID_value, 0, 250));
    analogWrite(motorUR, constrain(speed+PID_value, 0, 250));
    analogWrite(motorLR, constrain(speed+PID_value, 0, 250));
  } else if(ConservativePID==true){
    analogWrite(motorUL, constrain(speed-PID_value, 130, 250));
    analogWrite(motorLL, constrain(speed-PID_value, 130, 250));
    analogWrite(motorUR, constrain(speed+PID_value, 130, 250));
    analogWrite(motorLR, constrain(speed+PID_value, 130, 250));
  }
}


void MoveBackwards(int speed){
  ULBackwards();
  LLBackwards();
  URBackwards();
  LRBackwards();
  analogWrite(motorUL, speed);
  analogWrite(motorLL, speed);
  analogWrite(motorUR, speed);
  analogWrite(motorLR, speed);
}

void MoveBackwardsPID(int speed){
  ULBackwards();
  LLBackwards();
  URBackwards();
  LRBackwards();
  CalculatePID();
  if(ConservativePID==false){
    analogWrite(motorUL, constrain(speed+PID_value, 0, 250));
    analogWrite(motorLL, constrain(speed+PID_value, 0, 250));
    analogWrite(motorUR, constrain(speed-PID_value, 0, 250));
    analogWrite(motorLR, constrain(speed-PID_value, 0, 250));
  } else if(ConservativePID==true){
    analogWrite(motorUL, constrain(speed+PID_value, 120, 250));
    analogWrite(motorLL, constrain(speed+PID_value, 120, 250));
    analogWrite(motorUR, constrain(speed-PID_value, 120, 250));
    analogWrite(motorLR, constrain(speed-PID_value, 120, 250));
  }
}


void RotateLeft(int speed){
  ULBackwards();
  LLBackwards();
  URForward();
  LRForward();
  analogWrite(motorUL, constrain(speed, 130, 250));
  analogWrite(motorLL, constrain(speed, 130, 250));
  analogWrite(motorUR, constrain(speed, 130, 250));
  analogWrite(motorLR, constrain(speed, 130, 250));
}


void RotateRight(int speed){
  ULForward();
  LLForward();
  URBackwards();
  LRBackwards();
  analogWrite(motorUL, constrain(speed, 130, 250));
  analogWrite(motorLL, constrain(speed, 130, 250));
  analogWrite(motorUR, constrain(speed, 130, 250));
  analogWrite(motorLR, constrain(speed, 130, 250));
}


void DeployKitLeft(){
  //Deployer.write(170);
  //delay(400);
  //Deployer.write(85);
  //delay(300);
  //Deployer.write(100);
  //delay(300);
  //KitCounter--;
}

void DeployKitRight(){
  //Deployer.write(30);
  //delay(400);
  //Deployer.write(115);
  //delay(300);
  //Deployer.write(100);
  //delay(300);
  //KitCounter--;
}
