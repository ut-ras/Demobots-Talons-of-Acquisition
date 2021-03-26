#include <Arduino.h>
#include <Servo.h>
#include "BigButton.h"

/*  BigButton.cpp - Library created for control of
    BigButton for Claws of Aquisition.
*/
#define clawPin 0
#define buttonPin 0
#define downPos 0
#define upPos 0
#define delay 0

Servo claw;

BigButton::BigButton()
{
	claw.attach(clawPin);
	pinMode(buttonPin, INPUT);
}

void BigButton::dropClaw(){
	claw.write(downPos);
	delayMicroseconds(delay);
	claw.write(upPos);
}
boolean BigButton::buttonPressed(){
	if (digitalRead(buttonPin) == 1){
		return true;
	}
	return false;
}
