//Encoders.cpp
#include <Arduino.h>
#include "../headers/Encoders.hpp"
#include "../headers/Motors.hpp"
#include "../headers/PID.hpp"
/*
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
*/

volatile int encValLeft = 0;
volatile int encValRight = 0;

int currLeftEncoder;
int currRightEncoder;

double encoderCountX;
int encoderCountW;
int leftEncoderCount;
int rightEncoderCount;

double encoderChange;
int leftEncoderChange;
int rightEncoderChange;

double oldEncoderCount;
int oldLeftEncoder; 
int oldRightEncoder; 

void encoderSetup() {
	pinMode(EncoderL_A, INPUT);
	pinMode(EncoderL_B, INPUT);
	pinMode(EncoderR_A, INPUT);
	pinMode(EncoderR_B, INPUT);
}

void setupInterrupts() {
	attachInterrupt(EncoderL_A, countLeftEncoderA, CHANGE);
	attachInterrupt(EncoderL_B, countLeftEncoderB, CHANGE);
	attachInterrupt(EncoderR_A, countRightEncoderA, CHANGE);
	attachInterrupt(EncoderR_B, countRightEncoderB, CHANGE);
}

void countLeftEncoderA() {
	if (digitalRead(EncoderL_B)) {
	   	if (digitalRead(EncoderL_A)) {
	   		encValLeft++;
	   	}
		else {
			encValLeft--;
		}
	}
	else {
		if (digitalRead(EncoderL_A)) {
			encValLeft--;
		}
		else {
			encValLeft++;
		}
	}
}

void countLeftEncoderB() {
	if (digitalRead(EncoderL_A)) {
		if (digitalRead(EncoderL_B)) { // If A leads B, CW
			encValLeft--;
		}
		else {
			encValLeft++;
		}
	}
	else {
		if (digitalRead(EncoderL_B)) {
			encValLeft++;
		}
		else {
			encValLeft--;
		}
	}
}

void countRightEncoderA() {
	if (digitalRead(EncoderR_A)) {
		if (digitalRead(EncoderR_B)) { // If A leads B, CW
			encValRight--;
		}
		else {
			encValRight++;
		}
	}
	else {
		if (digitalRead(EncoderR_B)) {
			encValRight++;
		}
		else {
			encValRight--;
		}
	}
}

void countRightEncoderB() {
	if (digitalRead(EncoderR_B)) {
		if (digitalRead(EncoderR_A)) {
			encValRight++;
		}
		else {
			encValRight--;
		}
	}
	else {
		if (digitalRead(EncoderR_A)) {
			encValRight--;
		}
		else {
			encValRight++;
		}
	}
}

void resetEncoders() {
	encValLeft = 0;
	encValRight = 0;

	currLeftEncoder = 0;
	currRightEncoder = 0;

	leftEncoderChange = 0;
	rightEncoderChange = 0;
	encoderChange = 0;

	oldLeftEncoder = 0;
	oldRightEncoder = 0;

	leftEncoderCount = 0;
	rightEncoderChange = 0;
	encoderCountX = 0;
	encoderCountW = 0;

	distanceLeftX = 0;
	distanceLeftW = 0;

	encLeftCounter = 0;
	encRightCounter = 0;
}

void printEncoders() {
	Serial.print("encVal: ");
	Serial.print(encValLeft);
	Serial.print(",");
	Serial.println(encValRight);
	Serial.print("encLeft/RightCounter: ");
	Serial.print(encLeftCounter);
	Serial.print(",");
	Serial.println(encRightCounter);

}


void updateEncoders() {
	currLeftEncoder = encValLeft;
	currRightEncoder = encValRight;

	leftEncoderChange = currLeftEncoder - oldLeftEncoder;
	rightEncoderChange = currRightEncoder - oldRightEncoder;
	encoderChange = (double)(leftEncoderChange + rightEncoderChange)/2;

	oldLeftEncoder = currLeftEncoder;
	oldRightEncoder = currRightEncoder;

	leftEncoderCount += leftEncoderChange;
	rightEncoderChange += rightEncoderChange;
	encoderCountX = (double)(leftEncoderCount + rightEncoderCount)/2;
	encoderCountW = rightEncoderCount - leftEncoderChange;

	distanceLeftX -= encoderChange;
	distanceLeftW -= rightEncoderChange - leftEncoderChange;
}
