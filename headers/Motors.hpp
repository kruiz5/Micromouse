//Motor header file
#ifndef MOTORS_HEADER
#define MOTORS_HEADER

extern int motorSpeedL;
extern int motorSpeedR;

extern double distanceLeftX;
extern double distanceLeftW;

extern int oneCellLength;
extern int oneTurnLength;

void motorSetup(); //declare motor pin connections
void turnDecision();
void moveOneCell();
void moveForwardSetting();
void turnRight();
void turnRightSetting();
void turnLeft();
void turnLeftSetting();
void halt();
void moveBackwards();
void turnAround();
void setMoveSpeed();
void setTurnSpeed();

#endif