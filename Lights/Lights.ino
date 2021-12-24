#include "libraries/LEDStrips/LEDStrips.h"
#include "libraries/LEDStrips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include "libraries/Lights/Lights.h"

#define LED_PIN 6
#define LED_COUNT 40
#define LED_BRIGHTNESS 10

LEDStrips strip(LED_COUNT, LED_PIN, LED_BRIGHTNESS);

void setup() {
  // put your setup code here, to run once:
  strip.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  idle(strip);
}
