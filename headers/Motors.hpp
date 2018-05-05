//Motor header file
#pragma once

int motorSpeedL = 127;
int motorSpeedR = 127;

void motorSetup(); //declare motor pin connections
void turnRight();
void moveForward();
void turnLeft();
void halt();
void moveBackwards();
void turnAround();
