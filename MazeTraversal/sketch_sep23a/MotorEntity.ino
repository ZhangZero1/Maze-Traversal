class MotorProp{
  public:
  int posPin;
  int negPin;
  bool isFlip;

  MotorProp(int posPin, int negPin, bool isFlip){
    this->posPin = posPin;
    this->negPin = negPin;
    this->isFlip = isFlip;
  }

  int getPosPin(){
    return posPin;
  }

  int getNegPin(){
    return negPin;
  }

  bool getIsFlip(){
    return isFlip;
  }
}

class MotorState{
  public:
  MotorProp* props;
  float velocity;

  MotorState(MotorProp* props){
    this->props = props;
    this->velocity = 0;
  }

  void setVelocity(float velocity){
    this->velocity = velocity;
  }
  
};

class MotorDriverState{
  public:
  bool posState;
  bool negState;

  MotorDriverState(bool posState, bool negState){
    this->posState = posState;
    this->negState = negState;
  }

  bool getPosState(){
    return this->posState;
  }

  bool getNegState(){
    return this->negState;
  }

  MotorDriverState reverse(){
    MotorDriverState reversed(negState, posState);
    return reversed;
  }
};

class MotorDriver{
  public:
  MotorProp* props;
  int directionCode;

  const int FORWARD = 0;
  const int BACKWARD = 1;
  const int STOP = 2;

  MotorDriver(MotorProps* props){
    this->props = props;
    this->directionCode = STOP;
  }

  void setForward(){
    directionCode = FORWARD;
  }

  void setBackward(){
    directionCode = BACKWARD;
  }

  void setStop(){
    directionCode = STOP;
  }

  MotorDriverState getDriverState(){
    if(directionCode == STOP){
      MotorDriverState state(false, false);
      return state;
    }
    else if(directionCode == FORWARD){
      MotorDriverState state(true, false);
      if(props->getIsFlip()){
        return state.reverse();
      }
      return state;
    }
    else if(directionCode == REVERSE){
      MotorDriverState state(false, true);
      if(props->getIsFlip()){
        return state.reverse();
      }
      return state;
    }
  }
};
