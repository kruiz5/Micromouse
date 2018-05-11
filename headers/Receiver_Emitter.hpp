//Receiver_Emitter header file
#ifndef RECEIVER_EMITTER_HEADER
#define RECEIVER_EMITTER_HEADER

#include "macros.hpp"
#include <stdbool.h>

void receiver_emitter_setup(); //declare pin connections for emiiters and receivers
int getFrontRight(); //R1,E1
int getRight(); //R2,E2
int getLeft(); //R3,E3
int getFrontLeft(); //R4,E4

bool rightWall();
bool leftWall();
bool frontWall();

#endif