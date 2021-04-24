#include "libraries/StepperControl/StepperControl.h" 
#include "libraries/BigButton/BigButton.h"
#include "libraries/Sound/Sound.h"
#include "libraries/LED_Strips/LED_Strips.h"
#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"


StepperControl myStepper;
BigButton button;
Sound music;
Lights test(test, 10, 7, 50);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
