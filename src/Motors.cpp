//Motor.cpp
#include <stdio.h>
#include <time.h>
#include <Arduino.h>
#include "../headers/Motors.hpp"
#include "../headers/macros.hpp"
#include "../headers/Receiver_Emitter.hpp"
#include "../headers/PID.hpp"
#include "../headers/Encoders.hpp"

int motorSpeedL, motorSpeedR; 

double distanceLeftX, distanceLeftW;

int oneCellLength = 350; //520 //test this out
int oneTurnLength = 1250; //340 * 4//test this out 

void motorSetup() {
  motorSpeedL = moveSpeed;
  motorSpeedR = moveSpeed;

  pinMode(motorL_EN, OUTPUT);
  pinMode(motorL_Forward, OUTPUT);
  pinMode(motorL_Reverse, OUTPUT);

  pinMode(motorR_EN, OUTPUT);
  pinMode(motorR_Forward, OUTPUT);
  pinMode(motorR_Reverse, OUTPUT);
}

void turnDecision() {
  int r;

  //turn off PID when about to make a turn
  turnOffPID();

  // no wall on right only
  if (frontWall == true && leftWall == true && rightWall == false) {
    turnRight();
  }
  //no wall on left only
  else if (frontWall == true && leftWall == false && rightWall == true) {
    turnLeft();
  }
  //wall in front; no wall on right and no wall on left
  else if (frontWall == true && leftWall == false && rightWall == false) {
    //turn right or left
    r = rand() % (2); 
    if (r == 0) {
      turnRight();
    }
    else {
      turnLeft();
    }
  }
  //wall on left; no wall on right and no wall in front
  else if (frontWall == false && leftWall == true && rightWall == false) {
    //move forward or turn right
    r = rand() % (2);
    if (r == 0){
      //moveforward
    }
    else {
      turnRight();  
    }
  }
  //wall on right; no wall forward and no wall left
  else if (frontWall == false && leftWall == false && rightWall == true) {
    //move forward or turn right
    r = rand() % (2);
    if (r == 0) {
      //move forward
    }
    else {
      turnLeft();  
    }
  }

}

void moveOneCell() {
  //turn on PID 
  turnOnPID();
  while ((encoderCountX-oldEncoderCount) < oneCellLength) {
    Serial.println(encoderCountX-oldEncoderCount);
    moveForwardSetting();
    runPID();
    updateEncoders();
    printEncoders();
    Serial.println(motorSpeedL);
  }
  halt();
  oldEncoderCount = encoderCountX;
}

void moveForwardSetting() {
  setMoveSpeed();
  digitalWrite(motorL_EN, HIGH);
  analogWrite(motorL_Forward, motorSpeedL);
  analogWrite(motorL_Reverse, 0);
  digitalWrite(motorR_EN, HIGH);
  analogWrite(motorR_Forward, motorSpeedR);
  analogWrite(motorR_Reverse, 0);

}

void turnRight() {
  distanceLeftW = -oneTurnLength;
  while(distanceLeftW < 0) {
    Serial.println(distanceLeftW);
    turnRightSetting();
    updateEncoders();
  }
  halt();
  resetEncoders();
}

void turnRightSetting() {
  setTurnSpeed();
  digitalWrite(motorL_EN, HIGH);
  analogWrite(motorL_Forward, motorSpeedL);
  analogWrite(motorL_Reverse, 0);
  digitalWrite(motorR_EN, LOW);
  analogWrite(motorR_Forward, 0);
  analogWrite(motorR_Reverse, 0); 
}

void turnLeft() {
  distanceLeftW = oneTurnLength;
  while( distanceLeftW > 0) {
    turnLeftSetting();  
    Serial.println(distanceLeftW);
    updateEncoders();
  }
  halt();
  resetEncoders();  
}

void turnLeftSetting() {
  setTurnSpeed();
    digitalWrite(motorL_EN, LOW);
    analogWrite(motorL_Forward, 0);
    analogWrite(motorL_Reverse, 0);
    digitalWrite(motorR_EN, HIGH);
    analogWrite(motorR_Forward, motorSpeedR);
    analogWrite(motorR_Reverse, 0);
}

void halt() {
  digitalWrite(motorL_EN, LOW);
  analogWrite(motorL_Forward, 0);
  analogWrite(motorL_Reverse, 0);
  digitalWrite(motorR_EN, LOW);
  analogWrite(motorR_Forward, 0);
  analogWrite(motorR_Reverse, 0);
  delay(500);
}

void moveBackwards() {
  digitalWrite(motorL_EN, HIGH);
  analogWrite(motorL_Forward, 0);
  analogWrite(motorL_Reverse, motorSpeedL);
  digitalWrite(motorR_EN, HIGH);
  analogWrite(motorR_Forward, 0);
  analogWrite(motorR_Reverse, motorSpeedR);
}

void turnAround() {
  turnRight();
  turnRight();
}

void setMoveSpeed() {
  motorSpeedR = moveSpeed;
  motorSpeedL = moveSpeed;
}

void setTurnSpeed() {
  motorSpeedR = turnSpeed;
  motorSpeedL = turnSpeed;
}