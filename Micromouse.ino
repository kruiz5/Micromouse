#include "headers/Receiver_Emitter.hpp"
#include "headers/Motors.hpp"
#include "headers/Encoders.hpp"
#include "headers/PID.hpp"

void setup() {
  receiver_emitter_setup();
  motorSetup();
  encoderSetup();
  setupInterrupts();
  PIDsetup();  
}

void loop() {
  int frontLeft, left, right, frontRight;
  moveForward();
  runPID();
  
  frontLeft = getFrontLeft();
  left = getLeft();
  right = getRight();
  frontRight = getFrontRight();

  //wall in front and right ===> turn left
  if (frontLeft >= 35 && frontRight >= 120 && right >= 120 && left < 170) {
    turnLeft();
    delay(3000);
    halt();
  }
  //wall in front and left ====> turn right
  else if (frontLeft >= 35 && frontRight >= 120 && right < 120 && left >= 170) {
    turnRight();
    delay(3000);
    halt();
  }
  //wall in front and left and right  ====> turnAround
  else if  (frontLeft >= 35 && frontRight >= 120 && right >= 120 && left >= 170) {
    turnAround();
    delay(3000);
    halt();
  }
  //wall only in front ===> default turn right
  else if (frontLeft >= 35 && frontRight >= 120 && right < 120 && left < 170 {
    turnRight();
    delay(3000);
    halt();
  }
}
