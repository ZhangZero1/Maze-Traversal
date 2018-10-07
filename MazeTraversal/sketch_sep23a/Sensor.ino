
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
