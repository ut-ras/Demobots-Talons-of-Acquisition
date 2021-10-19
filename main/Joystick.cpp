//include any libraries that need to be imported
#include <Arduino.h>
#include <Servo.h>

//Compiles but not tested at all

#include "libraries/Joystick/Joystick.h"
#include "libraries/StepperControl/StepperControl.h"

int leftInput, rightInput, upInput, downInput, servoDown, servoClaw, bigRedButton;
Servo servo1; //servo controlling up down motion
Servo servo2; //servo controlling the opening and closing of the claw
Joystick::Joystick(int left, int right, int up, int down, int servoZ, int servoClose, int buttonOne)
{
	leftInput = left;
	rightInput = right;
	upInput = up;
	downInput = down;
  servoDown = servoZ;
  servoClaw = servoClose;
  bigRedButton = buttonOne;
	pinMode(leftInput, INPUT);
	pinMode(rightInput, INPUT);
	pinMode(upInput, INPUT);
	pinMode(downInput, INPUT);
  pinMode(servoZ, INPUT);
  pinMode(servoClose, INPUT);
  pinMode(bigRedButton, INPUT);
  servo1.attach(servoZ); //can add min and max values of the servo if feel like
  servo2.attach(servoClose);
}

void Joystick::readInput(){
	//dirX(digitalRead(rightInput)-digitalRead(leftInput));
	//dirY(digitalRead(upInput)-digitalRead(downInput));
  if (digitalRead(bigRedButton) == 1){
    dropClaw(0);//put in the angle which it need to go to
  }
}

void Joystick::dropClaw(int angle){
  //servo1.write(angle);
  //closeClaw();//put in the angle which it need to go to
  //servo1.write();//figure out how to reverse the movement
}

void Joystick::closeClaw(int angle){
  //servo2.write(angle);//put in the angle which it need to go to
}
