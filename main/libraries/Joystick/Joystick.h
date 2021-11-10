//include any libraries that need to be imported
#include <Arduino.h>
#include <Servo.h>




#ifndef Joystick_h
#define Joystick_h

class Joystick
{
  public:
	Joystick(int left, int right, int up, int down, int servoZ, int servoClose, int buttonOne);
	void readInput();
	void init();
	void dropClaw(int angle);
	void closeClaw(int angle);
	int left, right, up, down , servoZ, servoClose, buttonOne;
	Servo servo1; //servo controlling up down motion
	Servo servo2; //servo controlling the opening and closing of the claw
};

#endif
