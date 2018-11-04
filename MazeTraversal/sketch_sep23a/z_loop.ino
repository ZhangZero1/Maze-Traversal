int count = 0;
int trueCount = 0;
int maxCount = 23;



class TurnCorrection{
  public:
  bool isTurn;
  bool overrideStop;

  TurnCorrection(){
    this->isTurn = false;
    this->overrideStop = false;
  }

  bool flipTurn(){
    
    isTurn = !isTurn;
    return !isTurn;
  }

  void setOverrideStop(bool control){
    this->overrideStop = control;
  }

  bool correctIt(WallDetector* wallDetector, DriveTrain* dt){ // only from left 
    if(overrideStop){
      return false;
    }
    if(!isTurn){
      return flipTurn();
    }
    if(wallDetector->isLeftCollide()){
      // correct left: turn right
      dt->turnRight();
    }
    else if(wallDetector->isFrontCollide() && ! wallDetector->isRightCollide()){
      // then fix it: turn right
      dt->turnRight();
    }else{
      // turn left
      dt->turnLeft();
    }
    return flipTurn();
  }
};

TurnCorrection tc;

void loop() {
  /*
  Serial.print("front : ");
  Serial.println(wallDetector.getDistance("front"));

  Serial.print("right : ");
  Serial.println(wallDetector.getDistance("right"));

  Serial.print("left : ");
  Serial.println(wallDetector.getDistance("left"));
  */

  
  if(!tc.correctIt(&wallDetector, &dt)){
    if(wallDetector.isFrontCollide()){
      dt.Stop();
      tc.setOverrideStop(true);
    }else{
      tc.setOverrideStop(false);
      dt.goForward();
    }
  }
}
