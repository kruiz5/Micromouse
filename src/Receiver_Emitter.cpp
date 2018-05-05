//Receiver_Emitter.cpp
#include <Arduino.h>
#include "../headers/Receiver_Emitter.hpp"

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

int getFrontRight() {
  int reading;
  digitalWrite(E1, HIGH);
  delayMicroseconds(125);
  reading = analogRead(R1);
  delay(500);
  return reading;
}

int getRight() {
  int reading;
  digitalWrite(E2, HIGH);
  delayMicroseconds(125);
  reading = analogRead(R2);
  delay(500);
  return reading;
}

int getLeft() {
  int reading;
  digitalWrite(E3, HIGH);
  delayMicroseconds(125);
  reading = analogRead(R3);
  delay(500);
  return reading;
}

int getFrontLeft() {
  int reading;
  digitalWrite(E4, HIGH);
  delayMicroseconds(125);
  reading = analogRead(R4);
  delay(500);
  return reading;
}