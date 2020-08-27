#define Kp 2
#define Ki 0
#define Kd 0
float previous_error=0;
float P=0;
float I=0;
float previous_I=0;
float D=0;
float PID_value=0;
float error=0;
bool ConservativePID=false;

void ResetPID(){
  previous_error=0;
  error=0;
  PID_value=0;
  P=0;
  I=0;
  D=0;
}

void CalculatePID(){
  error = 0;
  if(ToFLeftA<=300 && ToFRightA<=300){
    error += ToFLeftA-ToFRightA;
    ConservativePID=true;
  } 
  if(ToFLeftA<300 && ToFLeftB<300 && ToFLeftCT<300){
    error += ToFLeftA-ToFLeftB+(ToFLeftA-150);
    ConservativePID=true;
  } 
  if(ToFRightA<300 && ToFRightB<300 && ToFRightCT<300){
    error += ToFRightB-ToFRightA+(150-ToFRightA);
    ConservativePID=true;
  } 
  if(ToFBackA<300 && ToFBackB<300 && ToFBackCT<300){
    error += ToFBackB-ToFBackA;
    ConservativePID=true;
  } 
  if(ToFFrontA<300 && ToFFrontB<300 && ToFFrontCT<300){
    error += ToFFrontB-ToFFrontA;
    ConservativePID=true;
  } 
  if(ToFLeftA<300 && ToFLeftCT<300){
    error += ToFLeftA-ToFLeftCT;
    ConservativePID=true;
  } 
  if(ToFRightA<300 && ToFRightCT<300){
    error += ToFRightCT-ToFRightA;
    ConservativePID=true;
  } 
  if(abs(((ToFLeftA+ToFLeftB)/2)-ToFLeftCT) < 20){
    error += ToFLeftA-ToFLeftB;
    ConservativePID=true;
  } 
  if(abs(((ToFRightA+ToFRightB)/2)-ToFRightCT) < 20){
    error += ToFRightB-ToFRightA;
    ConservativePID=true;
  } 
  if(abs(((ToFBackA+ToFBackB)/2)-ToFBackCT) < 20){
    error += ToFBackB-ToFBackA;
    ConservativePID=true;
  } 
  if(abs(((ToFFrontA+ToFFrontB)/2)-ToFFrontCT) < 20){
    error += ToFFrontB-ToFFrontA;
    ConservativePID=true;
  } 
  if(ToFRightCT<300 && ToFRightB<300){
    error += ToFRightB-ToFRightCT;
    ConservativePID=true;
  } 
  if(ToFLeftCT<300 && ToFLeftB<300){
    error += ToFLeftCT-ToFLeftB;
    ConservativePID=true;
  }
  P = error;
  I = I + error;
  D = error - previous_error;
  PID_value = round((Kp*P)+(Ki*I)+(Kd*D));
  previous_error=error;
}
