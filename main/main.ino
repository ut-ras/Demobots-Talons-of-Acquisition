#include "libraries/Joystick/Joystick.h"
#include "libraries/LED_Strips/LED_Strips.h"
#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include "libraries/StepperControl/StepperControl.h"

#define LED_PIN 6
#define LED_COUNT 40
#define LED_BRIGHTNESS 10

Lights strip(LED_COUNT, LED_PIN, LED_BRIGHTNESS);
Joystick myJoystick;

void setup() {
  // put your setup code here, to run once:
  strip.init();
  //myJoystick.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //myJoystick.readInput();
  strip.turnOnAll(RED);
  //delay(2000);
  //strip.turnOnLED(RED, 2);
  delay(2000);
  strip.turnOffLED(10);
  delay(2000);
}
