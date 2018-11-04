NewPing lSonar(2, 3, 200); // trigger, echo, max_distance
NewPing rSonar(9, 12, 200);
NewPing fSonar(13, 10, 200);

WallDetector wallDetector(&lSonar, &rSonar, &fSonar);
Motor m1(5,6, true);
Motor m2(8,7,false);
DriveTrain dt(&m1, &m2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // open the serial port at 9600 bps:
  
}
