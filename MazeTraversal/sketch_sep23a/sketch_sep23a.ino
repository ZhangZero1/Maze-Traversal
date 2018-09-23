class motor{
  public:
  int PosPin;
  int NegPin;
  bool isFlip;
  motor(int PosPin, int NegPin, bool isFlip){
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

class drivetrain{
  motor m1;
  motor m2;

  drivetrain(motor m1, motor m2){
   this->m1=m1;
   this->m2=m2;
  }

  void goForward(){
    m1.Forward();
    m2.Forward();
  }
  void turnRight(){
    m1.Forward();
    m2.Stop();
  }
  void turnLeft(){
    m1.Stop();
    m2.Forward();
  }

  void goBackward(){
    m1.Backward();
    m2.Backward();
  }

  void Stop(){
    m1.Stop();
    m2.Stop();
  }
};
void setup() {
  // put your setup code here, to run once:
  drivetrain dt(motor(5,6,true), motor(7,8,false));
}

void loop() {
  // put your main code here, to run repeatedly:

}
