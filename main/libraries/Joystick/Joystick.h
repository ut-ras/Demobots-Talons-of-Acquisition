//include any libraries that need to be imported
#include <Arduino.h>
#include <Servo.h>


#ifndef Joystick_h
#define Joystick_h

class Joystick
{
  public:
	void readInput();
	void init();
	void dropClaw();
	static void shift();
	Servo servo1; //servo controlling up down motion
	Servo servo2; //servo controlling the opening and closing of the claw
};

#endif
