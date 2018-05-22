//Receiver_Emitter.cpp
#include <Arduino.h>
#include "../headers/Receiver_Emitter.hpp"

int frontLeft, left, right, frontRight;

int frontLeftThreshold = 46;
int frontRightThreshold = 61;
int leftThreshold = 130;
int rightThreshold = 90;

bool frontWall = false;
bool leftWall = false;
bool rightWall = false;

void receiver_emitter_setup() {
  pinMode(R1, INPUT);
  pinMode(E1, OUTPUT);

  pinMode(R2, INPUT);
  pinMode(E2, OUTPUT);

  pinMode(R3, INPUT);
  pinMode(E3, OUTPUT);

  pinMode(R4, INPUT);
  pinMode(E4, OUTPUT);
}

void getFrontRight() {
  digitalWrite(E1, HIGH);
  delayMicroseconds(40);
  frontRight = analogRead(R1);
}

void getRight() {
  digitalWrite(E2, HIGH);
  delayMicroseconds(40);
  right = analogRead(R2);
}

void getLeft() {
  digitalWrite(E3, HIGH);
  delayMicroseconds(40);
  left = analogRead(R3);
}

void getFrontLeft() {
  digitalWrite(E4, HIGH);
  delayMicroseconds(40);
  frontLeft = analogRead(R4);
}

void readSensors() {
  getFrontRight();
  delayMicroseconds(25);
  getRight();
  delayMicroseconds(25);
  getLeft();
  delayMicroseconds(25);
  getFrontLeft();
}

void detectWalls() {
  if (frontLeft >= frontLeftThreshold && frontRight >= frontRightThreshold) {
    frontWall = true;
  } else{
    frontWall = false;
  }
  if (left >= leftThreshold) {
    leftWall = true;
  } else {
    leftWall = false;
  }
  if (right >= rightThreshold) {
    rightWall = true;
  } else {
    rightWall = false;
  }


}

void printSensorValues() {
  Serial.print("frontLeft = ");
  Serial.println(frontLeft);
  Serial.print("left = ");
  Serial.println(left);
  Serial.print("right = ");
  Serial.println(right);
  Serial.print("frontRight = ");
  Serial.println(frontRight);

}

void printWalls() {
  Serial.print("frontWall: ");
  if (frontWall == true)
    Serial.println("yes");
  else if (frontWall == false)
    Serial.println("no");

  Serial.print("leftWall: ");
  if (leftWall == true)
    Serial.println("yes");
  else if (leftWall == false)
    Serial.println("no");

  Serial.print("rightWall: ");
  if (rightWall == true)
    Serial.println("yes");
  else if (rightWall == false)
    Serial.println("no");
}



