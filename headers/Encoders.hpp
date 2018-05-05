//Encoder header 
#pragma once

#include "macros.hpp"

//variables to keep track of "change" in encoder
int encL = 0;
int encR = 0;

void encoderSetup(); //connect encoders
void incLeft(); //increment counnter for left encoder
void incRight(); //increment counter for right encoder

void setupInterrupts(); //connect the interrupt service routine pins