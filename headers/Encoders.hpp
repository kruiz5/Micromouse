//Encoder header 
#ifndef ENCODERS_HEADER
#define ENCODERS_HEADER

#include "macros.hpp"

extern int encL;
extern int encR;

void encoderSetup(); //connect encoders
void incLeft(); //increment counnter for left encoder
void incRight(); //increment counter for right encoder

void setupInterrupts(); //connect the interrupt service routine pins

#endif