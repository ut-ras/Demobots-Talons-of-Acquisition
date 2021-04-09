#include <Arduino.h>

#ifndef BigButton_h
#define BigButton_h
/*  BigButton.h - Library created for control of
    BigButton for Claws of Aquisition.
*/

class BigButton
{
  public:
    BigButton();
    void dropClaw();
	boolean buttonPressed();
};

#endif
