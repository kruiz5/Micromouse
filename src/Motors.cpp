//Motor.cpp
#include <Arduino.h>
#include "../headers/Motors.hpp"
#include "../headers/macros.hpp"

void motorSetup() {
  motorSpeedL = 127;
  motorSpeedR = 127;

  pinMode(motorL_EN, OUTPUT);
  pinMode(motorL_Forward, OUTPUT);
  pinMode(motorL_Reverse, OUTPUT);

  pinMode(motorR_EN, OUTPUT);
  pinMode(motorR_Forward, OUTPUT);
  pinMode(motorR_Reverse, OUTPUT);
}

void turnRight() {
  digitalWrite(motorL_EN, HIGH);
  analogWrite(motorL_Forward, motorSpeedL);
  analogWrite(motorL_Reverse, 0);
  digitalWrite(motorR_EN, LOW);
  analogWrite(motorR_Forward, 0);
  analogWrite(motorR_Reverse, 0);  
}

void moveForward() {
  digitalWrite(motorL_EN, HIGH);
  analogWrite(motorL_Forward, motorSpeedL);
  analogWrite(motorL_Reverse, 0);
  digitalWrite(motorR_EN, HIGH);
  analogWrite(motorR_Forward, motorSpeedR);
  analogWrite(motorR_Reverse, 0);

}

void turnLeft() {
  digitalWrite(motorL_EN, HIGH);
  analogWrite(motorL_Forward, 0);
  analogWrite(motorL_Reverse, 0);
  digitalWrite(motorR_EN, LOW);
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
  
}