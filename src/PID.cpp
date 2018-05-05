//PID.cpp
//adjusts left motor to match with right motor

#include <Arduino.h>
#include <PID_v1.h>
#include "../headers/Motors.hpp"
#include "../headers/macros.hpp"
#include "../headers/PID.hpp"
#include "../headers/Encoders.hpp"

PID encPID = PID(&encLeftCounter, &newMotorSpeedL, &encRightCounter, 1, .05, .25, DIRECT);

void PIDsetup() {
	encLeftCounter = encL;
	encRightCounter = encR;
	encPID.SetMode(AUTOMATIC);
}

void runPID() {
	encLeftCounter = encL;
	encRightCounter = encR;
	encPID.Compute();
	motorSpeedL = newMotorSpeedL;
}