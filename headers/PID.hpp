//PID header file
#ifndef PID_HEADER
#define PID_HEADER

extern double encLeftCounter; //PID input
extern double newMotorSpeedL; //PID output
extern double encRightCounter; //PID setpoint

extern double kP, kI, kD;

void PIDsetup();
void runPID();
void turnOnPID();
void turnOffPID();

#endif