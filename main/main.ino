#include "libraries/Joystick/Joystick.h"
#include "libraries/LED_Strips/LED_Strips.h"
#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"


Lights strip(40, 6, 10);
Joystick myJoystick(0,1,2,4,9,5,6);
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
