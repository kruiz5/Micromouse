//macros header file
#ifndef MACROS_HEADER
#define MACROS_HEADER

//pins for emitter and receiver pointing front right
#define R1 A1
#define E1 12

//pins for emitter and receiver pointing right
#define R2 A2 
#define E2 14

//pins for emitter and receiver pointing left
#define R3 A3
#define E3 23

//pins for emitter and receiver pointing front left
#define R4 A4
#define E4 0

//left motor pins
#define motorL_EN 1
#define motorL_Forward 3
#define motorL_Reverse 10

//right motor pins
#define motorR_EN 7
#define motorR_Forward 4
#define motorR_Reverse 9

//A and B channels for both encoders
#define EncoderL_A 2	
#define EncoderL_B 5
#define EncoderR_A 8
#define EncoderR_B 11

//speeds
#define moveSpeed 50
#define turnSpeed 50
#define maxSpeed 70

#endif