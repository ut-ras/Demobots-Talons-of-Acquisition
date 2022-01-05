#include <Arduino.h>
#include "libraries/StepperControl/StepperControl.h"

/*  StepperControl.cpp - Library created for control of
    Steppers for Claws of Aquisition.
*/


//Stepper Driver takes two inputs: a direction and a step
#define xDirPin 32 //Pin numbers are not finalized
#define xStepPin 40
#define yDirPin 30
#define yStepPin 36

#define negXLim 51
#define posXLim 45
#define negYLim 29
#define posYLim 23


void StepperControl::init() {
  pinMode(xDirPin, OUTPUT);
  pinMode(xStepPin, OUTPUT);
  pinMode(yDirPin, OUTPUT);
  pinMode(yStepPin, OUTPUT);
  pinMode(negXLim, INPUT);
  pinMode(posXLim, INPUT);
  pinMode(negYLim, INPUT);
  pinMode(posYLim, INPUT);
}

void StepperControl::stepX(int steps) {
  if (steps < 0 && digitalRead(negXLim) == LOW) {
    // Set motor direction -x (counterclockwise spin)
    digitalWrite(xDirPin, LOW);
    //Spin Motor
    digitalWrite(xStepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(xStepPin, LOW);
    delayMicroseconds(2000);
  } else if (steps > 0 && digitalRead(posXLim) == LOW) {
    // Set motor direction +x (clockwise spin)
    digitalWrite(xDirPin, HIGH);
    //Spin Motor
    digitalWrite(xStepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(xStepPin, LOW);
    delayMicroseconds(2000);
  }
}
void StepperControl::stepZ(int steps) {
  if (steps > 0 && digitalRead(posYLim) == LOW) {
    // Set motor direction +y (clockwise spin)
    digitalWrite(yDirPin, HIGH);
    //Spin Motor
    digitalWrite(yStepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(yStepPin, LOW);
    delayMicroseconds(2000);
  } else if (steps < 0 && digitalRead(negYLim) == LOW) {
    // Set motor direction -y (counterclockwise spin)
    digitalWrite(yDirPin, LOW);
    //Spin Motor
    digitalWrite(yStepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(yStepPin, LOW);
    delayMicroseconds(2000);
  }
}
void StepperControl::returnOrigin() {
  while (digitalRead(negXLim) == LOW) {
    stepX(-1);
    if (digitalRead(negYLim) == LOW) {
      stepZ(-1);
    }
  }
  while (digitalRead(negYLim) == LOW) {
    stepZ(-1);
  }
}
