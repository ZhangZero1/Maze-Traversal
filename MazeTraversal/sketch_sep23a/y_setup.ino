NewPing lSonar(2, 3, 200); // trigger, echo, max_distance
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
