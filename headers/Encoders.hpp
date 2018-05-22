//Encoder header 
#ifndef ENCODERS_HEADER
#define ENCODERS_HEADER

#include "macros.hpp"
/*
extern int encL;
extern int encR;

void encoderSetup(); //connect encoders
void incLeft(); //increment counnter for left encoder
void incRight(); //increment counter for right encoder

void setupInterrupts(); //connect the interrupt service routine pins
*/

//values that will increase/decrease depending on if channel A leads channel B (vice-versa) for both encoders
extern volatile int encValLeft;
extern volatile int encValRight;

//updated encoder values 
extern int currLeftEncoder;
extern int currRightEncoder;

extern double encoderCountX;
extern int encoderCountW;
extern int leftEncoderCount;
extern int rightEncoderCount;

//values to store changes and differnce between encoders and encoder states (current val and old val)
extern double encoderChange;//average between left encoder change and right encoder change
extern int leftEncoderChange;// difference between current left encoder and old left encoder
extern int rightEncoderChange; //difference between current rightEncoder and old right encoder

//last encoder values
//extern double oldEncoderCount; 
extern double oldEncoderCount;
extern int oldLeftEncoder; //last value of left encoder
extern int oldRightEncoder; //last value of right encoder


void encoderSetup(); //connect encoders
void setupInterrupts(); //connect the interrupt service routine pins

//methods to increment/decrement the right and left encoder count
void countLeftEncoderA();
void countLeftEncoderB();
void countRightEncoderA();
void countRightEncoderB();

void resetEncoders();

void updateEncoders();

void printEncoders();



#endif