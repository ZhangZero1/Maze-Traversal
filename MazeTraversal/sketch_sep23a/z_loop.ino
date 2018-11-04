int count = 0;
int trueCount = 0;
int maxCount = 23;

int turningPhase = -1;

void loop() {
  /*
  Serial.print("front : ");
  Serial.println(wallDetector.getDistance("front"));

  Serial.print("right : ");
  Serial.println(wallDetector.getDistance("right"));

  Serial.print("left : ");
  Serial.println(wallDetector.getDistance("left"));
  */

  
  if(wallDetector.getDistance("front") <= 30 && wallDetector.getDistance("front") > 0){
    // run away
    dt.Stop();
  }
  else if(wallDetector.getDistance("right") <= 30 && wallDetector.getDistance("right") > 0 && turningPhase==-1 ){
    // run away
    dt.turnLeft();
    if(turningPhase == -1){
      turningPhase = 1;
    }
    
  }
  else if(wallDetector.getDistance("left") <= 30 && wallDetector.getDistance("left") > 0 && turningPhase == -1){
    // run away
    dt.turnRight();
    if(turningPhase == -1){
      turningPhase = 1;
    }
  }
  else {
    // stop
    dt.goForward();
    turningPhase = -1;
  }
}
