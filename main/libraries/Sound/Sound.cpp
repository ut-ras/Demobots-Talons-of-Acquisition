//include any libraries that need to be imported
#include <Arduino.h>
#include "Sound.h"

/*  Sound.cpp - Library created for control of
    Music for Claws of Aquisition.
*/
#define soundPin 0
Sound::Sound()
{
	pinMode(soundPin, OUTPUT);
}

void Sound::playSound(){		
	digitalWrite(soundPin, HIGH);
}

void Sound::stopSound(){		
	digitalWrite(soundPin, LOW);
}
