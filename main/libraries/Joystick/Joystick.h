//include any libraries that need to be imported
#include <Arduino.h>



#ifndef Joystick_h
#define Joystick_h

class Joystick
{
  public:
	Joystick(int left, int right, int up, int down, int servoZ, int servoClose, int buttonOne);
	void readInput();
	void dropClaw(int angle);
	void closeClaw(int angle);
};

#endif
