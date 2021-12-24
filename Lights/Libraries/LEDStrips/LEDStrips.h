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
#include <stdint.h>

#define NUM_COLORS 12

typedef struct RGBValues{
    uint32_t red;
    uint32_t green;
    uint32_t blue;
}RGB_t;


typedef enum colors{
    RED,
    GREEN,
    BLUE,
    WHITE,
    PURPLE,
    YELLOW,
    CYAN,
    ORANGE,
    PINK,
    LIGHT_BLUE,
    BROWN,
    OFF
}Color_t;

typedef enum direction{
    FORWARD,
    BACKWARD
}LED_Direction_t;


class LEDStrips{

    /* private fields*/
    Adafruit_NeoPixel strip;
    int num_pixels;
    int pin;
    int brightness;

    /**
     * @brief sets the color for dynamicRainbowChase, theaterRainbowChase and rainbowCycle
     *
     * @param WheelPos current wheel position
     **/
    uint32_t Wheel(byte WheelPos);

    public:

    /** Available Methods **/

    /**
     * @name Lights constructor
     * 
     * @brief initializes strip with given parameters
     *
     * @param numLEDs number of LEDs from the strip to initialize
     * @param pin the pin to where the LED strip will be connected to
     * @param brightness desired brightness of the LEDs
     *  
     **/
    LEDStrips(int numLEDs, int pin, int brightness);

    /**
     * @name init
     * 
     * @brief initilizes LED strip, call in setup() 
     **/
    void init();

    /** 
     * @name turnOn
     * 
     * @brief Turn on a specified number of initialized LEDs
     * 
     * @param numLEDs the number of initialized LEDs that will be turned on
     * @param color the desired color of the LEDs
     **/
    void turnOn(uint8_t numLEDs, Color_t color);

    /**
     * @name turnOnAll
     * 
     * @brief Turn on all initialized LEDs in strip 
     * 
     * @param color the desired color for the LEDs
     **/
    void turnOnAll(Color_t color);

    /**
     * @name turnOnLED
     * 
     * @brief turn on a specified LED to a specified color
     * 
     * @param color desired color
     * @param LEDIndex index of the LED
     * 
     **/
    void turnOnLED(Color_t color, uint8_t LEDIndex);

    /**
     * @name turnOffLED
     * 
     * @brief turn off a specified LED to a specified color
     * 
     * @param color desired color
     * @param LEDIndex index of the LED
     * 
     **/
    void turnOffLED(uint8_t LEDIndex);

    /**
     * @name turnOFF
     * 
     * @brief Turn off all LEDs in strip
     **/
    void turnOff();

    /**
     * @name alternatingLightChase
     * 
     * @brief Turns on one LED followed by two OFF LEDs and again one repeated LED, then
     *        creates movement of those LED pattern
     * 
     * @param color desired color
     * @param wait desired interval/speed at which the LEDs will turn on and off
     * @param cycles the number of desired cycles for this effect
     * @param direction desired direction of the LED movement
     **/
    void alternatingLightchase(Color_t color, int wait, int cycles, LED_Direction_t direction);

    /**
     * @name lightChase 
     * 
     * @brief LEDs turn on in order in a given direction
     * 
     * @param color desired color
     * @param wait desired interval/speed at which the LEDs will turn on
     * @param direction desired direction for the LEDs to turn on,
     *                  either 'FORWARD' (from first LED to last LED) 
     *                  'BACKWARD' (from last LEd to first LED)
     **/
    void lightChase(uint32_t color, int wait, LED_Direction_t direction);

    /**
     * @name lineChase
     * 
     * @brief One line of color moves around the strip ina given direction
     * 
     * @param color desired color
     * @param wait desired delay/speed of the line of color
     * @param direction desired direction of the line of color's movement,
     *                  either 'FORWARD' (from first LED to last LED) 
     *                  'BACKWARD' (from last LEd to first LED)
     **/
    void lineChase(uint32_t color, int wait,LED_Direction_t direction);

    /**
     * @name splitChase
     * 
     * @brief Two lines of color move around the strip alternating towards and from each other 
     * 
     * @param color desired color
     * @param wait desired wait time/speed of the color lines 
     **/
    void splitChase(uint32_t color, int wait);

    /**
     * @name rainbowCycle
     * 
     * @brief The strip changes colors at a given rate into the colors of the rainbow
     * 
     * @param wait the delay/rate at which the strip will change colors
     * 
     **/
    void rainbowCycle(uint8_t wait);

    /**
     * @name solidRainbowChase
     * 
     * @brief Lines/bursts of the rainbow color go around the strip
     * 
     * @param wait the delay/rate at which the lines gfof around the strip
     **/
    void solidRainbowChase(int wait);

    /**
     * @name dynamicRainbowChase
     * 
     * @brief Lines/bursts of the rainbow color go around the strip
     * 
     * @param wait the delay/rate at which the lines gfof around the strip
     * 
     * @note very similar to solidRainbowChase but the way the colors change is
     *       slightly different
     **/
    void dynamicRainbowChase(uint8_t wait);
};


#endif // !LED_STRIPS_H