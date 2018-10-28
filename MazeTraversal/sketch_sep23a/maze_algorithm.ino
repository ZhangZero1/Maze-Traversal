void setup() {
  bool right = false;
  bool left = false;
  string next;
  

  while(right == true) {
    next = "left";
    //left sensor is scanning
  }

  while(left == true) {
    //right sensor is scanning
    next = "right";
  }
}

void loop() {
  // move forward until a wall is dected by the north sensor
  while(front sensor > 10 cm) {
    moveForward();
  }

  // turn 90 deg right/left
  if(next == "right") {
    turnRight();
    next = "left";
  } else {
    turnLeft();
    next = "right";
  }
  

  // move forward until opening is detected by the side sensor facing north
  while(front sensor > 10 cm) {
    moveForward();
  }
  

  // turn 90 deg right/left (opposite of the drection on the previous turn)
  if
  
}
  
  
 
  
