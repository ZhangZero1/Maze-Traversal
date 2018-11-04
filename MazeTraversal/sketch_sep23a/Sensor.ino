
class WallDetector{
  public:
  NewPing* lSonar;
  NewPing* rSonar;
  NewPing* fSonar;

  const int collisionThreshold = 30;

  WallDetector(NewPing* lSonar, NewPing* rSonar, NewPing* fSonar){
    this->lSonar = lSonar;
    this->rSonar = rSonar;
    this->fSonar = fSonar;
  }

  bool isLeftCollide(){
    return lSonar->ping_cm() <= collisionThreshold && lSonar->ping_cm() > 0;
  }

  bool isRightCollide(){
    return rSonar->ping_cm() <= collisionThreshold && rSonar->ping_cm() > 0;
  }

  bool isFrontCollide(){
    return fSonar->ping_cm() <= collisionThreshold && fSonar->ping_cm() > 0;
  }

  int getDistance(String name){
    if(name == "left"){
      return lSonar->ping_cm();
    }
    else if(name == "right"){
      return rSonar->ping_cm();
    }
    else if(name == "front"){
      return fSonar->ping_cm();
    }
    return -1;
  }
  
};
