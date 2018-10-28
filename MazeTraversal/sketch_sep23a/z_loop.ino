int count = 0;
int trueCount = 0;
int maxCount = 23;

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(wallDetector.isLeftCollide());
  if(count == 1000){
    trueCount += 1;
    count = 0;
  }
  if(trueCount <= maxCount){
    dt.turnRight();
    count ++;
  }else{
    dt.Stop();
  }
}
