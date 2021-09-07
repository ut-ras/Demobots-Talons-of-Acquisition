//#include "libraries/StepperControl/StepperControl.h" 
//#include "libraries/BigButton/BigButton.h"
//#include "libraries/Sound/Sound.h"
#include "libraries/LED_Strips/LED_Strips.h"
#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"

/*
StepperControl myStepper;
BigButton button;
Sound music;*/

Lights strip(40, 6, 10);


void setup() {
  // put your setup code here, to run once:
  strip.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  strip.chase(PINK, 200, 10, FORWARD);
}
