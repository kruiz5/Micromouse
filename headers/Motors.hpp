//Motor header file
#ifndef MOTORS_HEADER
#define MOTORS_HEADER

extern int motorSpeedL;
extern int motorSpeedR;

void motorSetup(); //declare motor pin connections
void turnRight();
void moveForward();
void turnLeft();
void halt();
void moveBackwards();
void turnAround();

#endif