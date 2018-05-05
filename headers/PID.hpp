//PID header
#pragma once

double encLeftCounter; //PID input
double newMotorSpeedL; //PID output
double encRightCounter; //PID setpoint

void PIDsetup();
void runPID();