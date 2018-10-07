#include <NewPing.h>







class WallDetector{
  public:
  NewPing* lSonar;
  NewPing* rSonar;
  NewPing* fSonar;

  const int collisionThreshold = 100;

  WallDetector(NewPing* lSonar, NewPing* rSonar, NewPing* fSonar){
    this->lSonar = lSonar;
    this->rSonar = rSonar;
    this->fSonar = fSonar;
  }

  bool isLeftCollide(){
    return lSonar->ping_cm() <= collisionThreshold;
  }

  bool isRightCollide(){
    return rSonar->ping_cm() <= collisionThreshold;
  }

  bool isFrontCollide(){
    return fSonar->ping_cm() <= collisionThreshold;
  }
  
};






class Motor{
  public:
  int PosPin;
  int NegPin;
  bool isFlip;
  Motor(int PosPin, int NegPin, bool isFlip){
    this->PosPin=PosPin;
    this->NegPin=NegPin;
    this->isFlip=isFlip;
  }
  void Forward(){
    if (isFlip){
      digitalWrite(PosPin, LOW);
      digitalWrite(NegPin, HIGH);
    }
    else{
      digitalWrite(PosPin, HIGH);
      digitalWrite(NegPin, LOW); 
    }
    
  }
  void Backwards(){
    if (isFlip){
      digitalWrite(PosPin, HIGH);
      digitalWrite(NegPin, LOW); 
    }
    else{
      digitalWrite(PosPin, LOW);
      digitalWrite(NegPin, HIGH);
    }
  }

  void Stop(){
    digitalWrite(PosPin, LOW);
    digitalWrite(NegPin, LOW); 
  }
};
/*
class GradedMotor(){
  public:
  Motor motor;
  double dutyCycle;
  
  GradedMotor(Motor* motor){
    this->motor = motor;
  }
  
  void setVelocity(double value){
    this->dutyCycle = abs(value);
  }
};*/

class DriveTrain{
  public:
  Motor* m1;
  Motor* m2;

  DriveTrain(Motor* m1,Motor* m2){
   this->m1 = m1;
   this->m2 = m2;
  }

  void goForward(){
    m1->Forward();
    m2->Forward();
  }
  void turnRight(){
    m1->Forward();
    m2->Stop();
  }
  void turnLeft(){
    m1->Stop();
    m2->Forward();
  }

  void goBackward(){
    m1->Backwards();
    m2->Backwards();
  }

  void Stop(){
    m1->Stop();
    m2->Stop();
  }
};

/*

class GradedDriveTrain{
  public:
  DriveTrain driveTrain;
  
  GradedDriveTrain(DriveTrain* driveTrain){
    this->driveTrain = driveTrain;
  }
  
  
};

class DriverScheduler{
  public:
  DriveTrain driveTrain;
  
  DriverScheduler(DriveTrain driveTrain){
    
  }
}*/


NewPing lSonar(2, 3, 200);
  NewPing rSonar(70, 80, 90);
  NewPing fSonar(70, 80, 90);

  WallDetector wallDetector(&lSonar, &rSonar, &fSonar);

void setup() {
  // put your setup code here, to run once:
  //Motor m1(5,6, true);
  //Motor m2(7,8,false);
  //DriveTrain dt(&m1, &m2);
  Serial.begin(9600);      // open the serial port at 9600 bps:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(wallDetector.isLeftCollide());
}
