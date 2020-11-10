#include <Servo.h>
#define DeployerPin 26
Servo Deployer;

void setup() {
  Serial.begin(9600);
  Deployer.attach(DeployerPin);
  Deployer.write(100);
  delay(1000);
}

void DeployKitLeft(){
  Deployer.write(170);
  delay(400);
  Deployer.write(85);
  delay(300);
  Deployer.write(100);
  delay(300);
}

void DeployKitRight(){
  Deployer.write(30);
  delay(400);
  Deployer.write(115);
  delay(300);
  Deployer.write(100);
  delay(300);
}


void loop() {
  Serial.println("here");
  DeployKitRight();
  delay(2000);
  DeployKitRight();
  delay(2000);
}
