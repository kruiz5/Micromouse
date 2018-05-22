//PID.cpp
//adjusts left motor to match with right motor

#include <Arduino.h>
#include <PID_v1.h>
#include "../headers/Motors.hpp"
#include "../headers/macros.hpp"
#include "../headers/Encoders.hpp"
#include "../headers/PID.hpp"

double encLeftCounter, encRightCounter, newMotorSpeedL;
double kP = 3; //ok 3
double kI = .25; // kI < .25 goes left. kI > .25 goes right 
double kD = .05; // idk 
PID encPID = PID(&encLeftCounter, &newMotorSpeedL, &encRightCounter, kP, kI, kD, DIRECT);


void PIDsetup() {
	encLeftCounter = encValLeft;
	encRightCounter = encValRight;
	encPID.SetMode(AUTOMATIC);
}

void runPID() {
	encLeftCounter = encValLeft;
	encRightCounter = encValRight;
	encPID.Compute();
	motorSpeedL = (int)newMotorSpeedL;
}

void turnOnPID() {
	encPID.SetMode(AUTOMATIC);
}

void turnOffPID() {
	encPID.SetMode(MANUAL);
}