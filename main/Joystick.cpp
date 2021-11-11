#include <Arduino.h>
#include <Servo.h>

//Hello. Welcome to the spaghetti hidden in the can.
//Yellow - Signal
//Red - Positive
//Brown - Negative

#include "libraries/Joystick/Joystick.h"
#include "libraries/StepperControl/StepperControl.h"

StepperControl myStepper;
Joystick::Joystick(int left, int right, int up, int down, int servoZ, int servoClose, int buttonOne)
{
	this->left = left;
	this->right = right;
	this->up = up;
	this->down = down;
  this->servoZ = servoZ;
  this->servoClose = servoClose;
  this->buttonOne = buttonOne;
}

void Joystick::init(){
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(servoZ, OUTPUT);
  pinMode(servoClose, OUTPUT);
  pinMode(buttonOne, INPUT);
  servo1.attach(servoZ); //can add min and max values of the servo if feel like
  servo2.attach(servoClose);
  pinMode(LED_BUILTIN, OUTPUT);
  myStepper.init();
}

void Joystick::readInput(){
	myStepper.stepX(digitalRead(right)-digitalRead(left)); //fix to the correct function names later
	myStepper.stepZ(digitalRead(up)-digitalRead(down)); 
  if (digitalRead(buttonOne) == HIGH){
    this->dropClaw(120);//Note: the servo is continuous rotation
  }
  else{
    this->dropClaw(60);
  }
}

void Joystick::dropClaw(int angle){
  this->servo1.write(angle);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  //closeClaw();//put in the angle which it need to go to
  //servo1.write();//figure out how to reverse the movement
}

void Joystick::closeClaw(int angle){
  servo2.write(angle);
}
