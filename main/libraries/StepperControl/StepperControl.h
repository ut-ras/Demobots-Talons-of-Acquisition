#include <Arduino.h>

#ifndef StepperControl_h
#define StepperControl_h
/*  StepperControl.h - Library created for control of
    StepperControl for Claws of Aquisition.
*/

class StepperControl
{
  public:
    	void stepX(int steps);
    	void stepZ(int steps);
	void returnOrigin();
	void init();
};

#endif
