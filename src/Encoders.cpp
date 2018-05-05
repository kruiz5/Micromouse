//Encoders.cpp
#include <Arduino.h>
#include "../headers/Encoders.hpp"

void encoderSetup(){
	pinMode(left_encoder, INPUT);
	pinMode(right_encoder, INPUT);	
}

void incLeft(){
	encL += 1;
}

void incRight(){
	encR += 1;
}

void setupInterrupts() {
	attachInterrupt(left_encoder, incLeft, CHANGE);
	attachInterrupt(right_encoder, incRight, CHANGE);
}
