//include any libraries that need to be imported
#include <Arduino.h>



#ifndef Sound_h
#define Sound_h

/*  Sound.h - Library created for control of
    Music for Claws of Aquisition.
*/

class Sound
{
  public:
    Sound();
	void playSound();
	void stopSound();
};

#endif
