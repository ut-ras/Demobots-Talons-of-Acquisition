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
#define buttonTwo 7

#define sucPin 2 //only pins 2, 3, 18, 19, 20, 21 can be used for interrupts (pins 20 and 21 are unavailable while needed for I2C comm)

StepperControl myStepper;
extern bool resetWait;

volatile bool success = false;

void Joystick::shift(){
  success = !success;  
}

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
  pinMode(sucPin, INPUT_PULLUP); // change to whatever it is
  attachInterrupt(digitalPinToInterrupt(sucPin), shift, FALLING);
  myStepper.init();
}

void Joystick::readInput() {
  myStepper.stepX(digitalRead(right) - digitalRead(left));
  myStepper.stepZ(digitalRead(up) - digitalRead(down));
  if (digitalRead(buttonOne) == HIGH) {             //wired-or interrupts, periodic interrupt if buttons get out of hand
    dropClaw();
    myStepper.returnOrigin();
    servo2.write(servoTwoAngleReverse);
    delayMicroseconds(50000); //normal delay wouldnt work
    if (success == true){
      resetWait = true;
    }
  }
}

void Joystick::dropClaw() {
  servo1.write(servoOneAngle);
  delay(500);
  servo2.write(servoTwoAngle);
  delay(500);
  servo1.write(servoOneAngleReverse);
}
