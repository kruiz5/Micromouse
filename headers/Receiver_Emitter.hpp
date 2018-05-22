//Receiver_Emitter header file
#ifndef RECEIVER_EMITTER_HEADER
#define RECEIVER_EMITTER_HEADER

#include "macros.hpp"

extern int frontLeft; 
extern int left;
extern int right;
extern int frontRight;

extern int frontLeftThreshold;
extern int frontRightThreshold;
extern int leftThreshold;
extern int rightThreshold;

extern bool frontWall;
extern bool leftWall;
extern bool rightWall;

void receiver_emitter_setup(); //declare pin connections for emiiters and receivers
void getFrontRight(); //R1,E1
void getRight(); //R2,E2
void getLeft(); //R3,E3
void getFrontLeft(); //R4,E4

void readSensors();
void detectWalls();

void printSensorValues();
void printWalls();

#endif