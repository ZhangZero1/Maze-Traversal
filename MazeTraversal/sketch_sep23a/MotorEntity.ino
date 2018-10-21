class MotorProp{
  /*
   * Gives Motor pins and flip direction
   * 
   */
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
  /*
   * Handles motor states and velocity
   */
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
  /*
   * Handles the voltage in each pin for each motor direction state
   */
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
  /*
   * Maintains the Voltage state for the desired direction
   */
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

class DriveTrain{
  public:
  DriveTrain (MotorDriver* motorLeft, MotorDriver* motorRight){}
  
}

class BasicDriveTrain{
    public:
    MotorDriver* motorLeft;
    MotorDriver* motorRight;

    BasicDriveTrain (MotorDriver* motorLeft, MotorDriver* motorRight){
      this->motorLeft = motorLeft;
      this->motorRight = motorRight;
    }

    void forward(){
      motorLeft->setForward();
      motorRight->setForward();
    }

    void reverse(){
      motorLeft->setBackward();
      motorRight->setBackward();
    }

    void stopPlease(){
      motorLeft->setStop()
      motorRight->setStop();
    }
    
    void turnRight(){
      motorLeft->setForward();
      motorRight->setStop();
    }

    void turnLeft(){
      motorLeft->setStop();
      motorRight->setForward();
    }
}

class MotorScheduler{
  public:
  
}
