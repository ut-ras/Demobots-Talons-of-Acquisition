#include <Arduino.h>
#include <Servo.h>

//Yellow - Signal
//Red - Positive
//Brown - Negative

//Vertical movement - servo1
//Claw movement - servo2
#include "libraries/Joystick/Joystick.h"
#include "libraries/StepperControl/StepperControl.h"

#define servoOneAngle 60
#define servoOneAngleReverse -60
#define servoTwoAngle 60
#define servoTwoAngleReverse -60

#define left 49
#define right 47
#define up 27
#define down 25
#define servoZ 9
#define servoClose 5
#define buttonOne 6

StepperControl myStepper;

void Joystick::init() {
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(servoZ, OUTPUT);
  pinMode(servoClose, OUTPUT);
  pinMode(buttonOne, INPUT);
  servo1.attach(servoZ, -90, 90);
  servo2.attach(servoClose, -90, 90);
  pinMode(LED_BUILTIN, OUTPUT);
  myStepper.init();
}

void Joystick::readInput() {
  myStepper.stepX(digitalRead(right) - digitalRead(left));
  myStepper.stepZ(digitalRead(up) - digitalRead(down));
  if (digitalRead(buttonOne) == HIGH) {             //wired-or interrupts, periodic interrupt if buttons get out of hand
    dropClaw();
    myStepper.returnOrigin();
    servo2.write(servoTwoAngleReverse);
    delay(500);                                     //possible addition of a start button to reset
  }
}

void Joystick::dropClaw() {
  servo1.write(servoOneAngle);
  delay(1000);
  servo2.write(servoTwoAngle);
  delay(500);
  servo2.write(servoOneAngleReverse);
  delay(1000);
}
