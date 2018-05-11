//Encoders.cpp
#include <Arduino.h>
#include "../headers/Encoders.hpp"

int encL, encR ;

void encoderSetup(){
	pinMode(left_encoder, INPUT);
	pinMode(right_encoder, INPUT);	
	encL = 0;
	encR = 0;
}

void incLeft(){
	encL ++;
}

void incRight(){
	encR ++;
}

void setupInterrupts() {
	attachInterrupt(left_encoder, incLeft, CHANGE);
	attachInterrupt(right_encoder, incRight, CHANGE);
}
