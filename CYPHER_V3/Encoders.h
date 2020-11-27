#include <Encoder.h>
#define TileDist 4550
#define TurnDist 2420
Encoder EB(29, 27);
Encoder DB(25, 23);
Encoder EA(30, 32);
Encoder DA(44, 42);
//E=left , D=right
//A=front , B=back
int TileDistLocal=5100;
int TargetEncAvg = 0;
int EncPulseEB=0;
int EncPulseDB=0;
int EncPulseEA=0;
int EncPulseDA=0;
int EncPulseAvg=0;
bool Locked=false;
int EncPulseEBbackup=0;
int EncPulseDBbackup=0;
int EncPulseEAbackup=0;
int EncPulseDAbackup=0;


void UpdateEncoders(){
  if(Locked==false){
    EncPulseEB=abs(EB.read());
    EncPulseEA=abs(EA.read());
    EncPulseDA=abs(DA.read());
    EncPulseAvg=(EncPulseEB+EncPulseEA+EncPulseDA)/3;
  }
}

void LockEncoders(){
  Locked=true;
  EncPulseEBbackup = EB.read();
  EncPulseEAbackup = EA.read();
  EncPulseDAbackup = DA.read();
}

void UnlockEncoders(){
  Locked=false;
  EB.write(EncPulseEBbackup);
  EA.write(EncPulseEAbackup);
  DA.write(EncPulseDAbackup);
  UpdateEncoders();
}

void ResetEncoders(){
  EB.write(0);
  EA.write(0);
  DA.write(0);
  EncPulseEB=0;
  EncPulseEA=0;
  EncPulseDA=0;
  EncPulseAvg=0;
}
