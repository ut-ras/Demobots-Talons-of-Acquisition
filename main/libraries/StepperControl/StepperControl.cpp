#include <Arduino.h>
#include "StepperControl.h"
#include <Stepper.h>

/*  StepperControl.cpp - Library created for control of
    Steppers for Claws of Aquisition.
*/
#define motorPinOneX 0
#define motorPinTwoX 0
#define motorPinThreeX 0
#define motorPinFourX 0
#define motorPinOneZ 0
#define motorPinTwoZ 0
#define motorPinThreeZ 0
#define motorPinFourZ 0
#define stepsPerRevolutionX  0
#define stepsPerRevolutionZ  0
#define stepNeg 0
#define limXPin 0
#define limZPin 0
Stepper xStepper(stepsPerRevolutionX, motorPinOneX, motorPinTwoX, motorPinThreeX, motorPinFourX);
Stepper zStepper(stepsPerRevolutionZ, motorPinOneZ, motorPinTwoZ, motorPinThreeZ, motorPinFourZ);

StepperControl::StepperControl()
{
	pinMode(motorPinOneX, OUTPUT);
	pinMode(motorPinTwoX, OUTPUT);
	pinMode(motorPinThreeX, OUTPUT);
	pinMode(motorPinFourX, OUTPUT);
	pinMode(motorPinOneZ, OUTPUT);
	pinMode(motorPinTwoZ, OUTPUT);
	pinMode(motorPinThreeZ, OUTPUT);
	pinMode(motorPinFourZ, OUTPUT);
	pinMode(limXPin, OUTPUT);
	pinMode(limZPin, OUTPUT);
}

void StepperControl::stepX(int steps){
	xStepper.step(steps);
}
void StepperControl::stepZ(int steps){
	zStepper.step(steps);
}
void StepperControl::returnOrigin(){
	while (digitalRead(limXPin) == 0){
		xStepper.step(stepNeg);
	}
	while (digitalRead(limZPin) == 0){
		zStepper.step(stepNeg);
	}
}