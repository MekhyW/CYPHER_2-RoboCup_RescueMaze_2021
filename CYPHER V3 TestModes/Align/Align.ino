#include <Wire.h>
#include "ToFs.h"
#include "PID.h"
#include "Motors.h"
#include "Encoders.h"

void AlignFrontBack(){
  ResetEncoders();
  ReadToF();
  TargetEncAvg = map(ToFFrontCT - 150, -150, 150, -(TileDist/2), TileDist/2);
  if(ToFFrontCT <= 300 && TargetEncAvg > 0){
    while(EncPulseAvg < TargetEncAvg){
      UpdateEncoders();
      MoveForward(150);
    } 
  } else if(ToFFrontCT <= 300 && TargetEncAvg < 0){
    while(EncPulseAvg < abs(TargetEncAvg)){
      UpdateEncoders();
      MoveBackwards(150);
    } 
  }
  TargetEncAvg = map(ToFFrontCT - 450, -150, 150, -(TileDist/2), TileDist/2);
  if(ToFFrontCT <= 600 && ToFFrontCT>=300 && ToFFrontA <= 600 && ToFFrontA>=300 && ToFFrontB <= 600 && ToFFrontB>=300 && TargetEncAvg > 0){
    while(EncPulseAvg < TargetEncAvg){
      UpdateEncoders();
      MoveForward(150);
    } 
  } else if(ToFFrontCT <= 600 && ToFFrontCT>=300 && ToFFrontA <= 600 && ToFFrontA>=300 && ToFFrontB <= 600 && ToFFrontB>=300 && TargetEncAvg < 0){
    while(EncPulseAvg < abs(TargetEncAvg)){
      UpdateEncoders();
      MoveBackwards(150);
    } 
  }
  ResetEncoders();
  ReadToF();
  TargetEncAvg = map(150 - ToFBackCT, -150, 150, -(TileDist/2), TileDist/2);
  if(ToFBackCT <= 300 && TargetEncAvg > 0){
    while(EncPulseAvg < TargetEncAvg){
      UpdateEncoders();
      MoveForward(150);
    } 
  } else if(ToFBackCT <= 300 && TargetEncAvg < 0){
    while(EncPulseAvg < abs(TargetEncAvg)){
      UpdateEncoders();
      MoveBackwards(150);
    } 
  }
  TargetEncAvg = map(450 - ToFBackCT, -150, 150, -(TileDist/2), TileDist/2);
  if(ToFBackCT <= 600 && ToFBackCT>=300 && ToFBackA <= 600 && ToFBackA>=300 && ToFBackB <= 600 && ToFBackB>=300 && TargetEncAvg > 0){
    while(EncPulseAvg < TargetEncAvg){
      UpdateEncoders();
      MoveForward(150);
    } 
  } else if(ToFBackCT <= 600 && ToFBackCT>=300 && ToFBackA <= 600 && ToFBackA>=300 && ToFBackB <= 600 && ToFBackB>=300 && TargetEncAvg < 0){
    while(EncPulseAvg < abs(TargetEncAvg)){
      UpdateEncoders();
      MoveBackwards(150);
    } 
  }
}

void AlignAngle(){
  ReadToF();
  while((ToFFrontCT<150&&ToFFrontA<300&&ToFFrontB<300&&ToFFrontA>(ToFFrontB*1.2)) || (ToFBackCT<300&&ToFBackCT>150&&ToFBackA<300&&ToFBackB<300&&ToFBackA>(ToFBackB*1.2))){
    ReadToF();
    Introduce(2, -1, 200);
  }
  while((ToFFrontCT<150&&ToFFrontA<300&&ToFFrontB<300&&ToFFrontB>(ToFFrontA*1.2)) || (ToFBackCT<300&&ToFBackCT>150&&ToFBackA<300&&ToFBackB<300&&ToFBackB>(ToFBackA*1.2))){
    ReadToF();
    Introduce(1, -1, 200);
  }
  while((ToFFrontCT<300&&ToFFrontCT>150&&ToFFrontA<300&&ToFFrontB<300&&(ToFFrontA*1.2)<ToFFrontB) || (ToFBackCT<150&&ToFBackA<300&&ToFBackB<300&&(ToFBackA*1.2)<ToFBackB)){
    ReadToF();
    Introduce(2, 1, 200);
  }
  while((ToFFrontCT<300&&ToFFrontCT>150&&ToFFrontA<300&&ToFFrontB<300&&(ToFFrontB*1.2)<ToFFrontA) || (ToFBackCT<150&&ToFBackA<300&&ToFBackB<300&&(ToFBackB*1.2)<ToFBackA)){
    ReadToF();
    Introduce(1, 1, 200);
  }
  while((ToFRightCT<300&&ToFRightA<300&&ToFRightB<300&&ToFRightA>(ToFRightB*1.2)) || (ToFLeftCT<300&&ToFLeftA<300&&ToFLeftB<300&&ToFLeftB>(ToFLeftA*1.2))){
      ReadToF();
      Introduce(1, 1, 200);
  }
  while((ToFRightCT<300&&ToFRightA<300&&ToFRightB<300&&(ToFRightA*1.2)<ToFRightB) || (ToFLeftCT<300&&ToFLeftA<300&&ToFLeftB<300&&(ToFLeftB*1.2)<ToFLeftA)){
      ReadToF();
      Introduce(2, 1, 200);
  }
}

void Align(){
  AlignAngle();
  AlignFrontBack();
  AlignAngle();
  AlignFrontBack();
}

void setup() {
  Wire.begin();
  Wire.setClock(100000);
  Serial.begin(9600);
  ToFInitialize();
  MotorsInitialize();
  Align();
  MotorsStop();
}

void loop() {
  
}
