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
  //to be filled  
}
