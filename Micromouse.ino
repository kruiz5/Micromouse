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
  Serial.begin(9600);
}
/*
//main
void loop() {
  readSensors();
  detectWalls();
  turnDecision();
  moveOneCell();
}
*/

/*
//test sensor readings and walls
void loop() {
  readSensors();
  printSensorValues();
  printWalls();
}
*/

//test PID and cell movement
void loop() {  
 moveOneCell();
 delay(3000);
}


/*
//test wheel turn with encoder print values
void loop() {
  turnLeft();
}
*/
