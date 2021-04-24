/**
 * Author: Dario Jimenez
 * Last Modified: 04/12/2021
 * Project: Talons of Acquisition
 * File: LED_Strips.h
 * Description: header file for LED strips for the Talons of Acquisition machine
 * Organization: UT IEEE RAS Demobots
 */

#ifndef LED_STRIPS_H
#define LED_STRIPS_H


#include "Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include <Arduino.h>



class Lights{
    Adafruit_NeoPixel strip;
    int num_pixels;
    int pin;
    int brightness;

    public:

    Lights(Adafruit_NeoPixel strip, int num_pixels, int pin, int brightness);

    //initializes the LED strip; call under setup
    //void initializeStrip(Adafruit_NeoPixel strip, int num_pixels, int pin, int brightness);

    void colorWipe(uint32_t color, int wait, bool forward);

    void colorWipe2(uint32_t color, int wait, bool forward);

    void colorWipe3(uint32_t color, int wait);

    //all leds are the same color and they cycle color every given seconds
    void rainbowCycle(uint8_t wait);

    //need to implement alongside wheel function
    void dynamicRainbowChase(uint8_t wait);

    //LEDs alternate between on and off making it look like they are chasing somthing in a certain direction
    void chase(uint32_t color, int wait, int times, bool forward);

    //LEDs change color along the strip
    void solidRainbowChase(int wait);
};


#endif // !LED_STRIPS_H