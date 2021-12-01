#include "libraries/Joystick/Joystick.h"
#include "libraries/LED_Strips/LED_Strips.h"
#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include "libraries/StepperControl/StepperControl.h"
#include "pins_RAMPS.h"


#define joyNegX 49
#define joyPosX 47
#define joyNegY 27
#define joyPosY 25

Lights strip(40, 6, 10);
Joystick myJoystick(joyNegX,joyPosX,joyPosY,joyNegY,9,5,6);

void setup() {
  // put your setup code here, to run once:
  strip.init();
  myJoystick.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  strip.chase(PINK, 200, 10, FORWARD);
  myJoystick.readInput();
}
