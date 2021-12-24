#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include <Arduino.h>
#include "libraries/LED_Strips/LED_Strips.h"


//TODO: maybe do a chaseALL and chase methods where you choose how many led lights to turn on

/** Values of available colors **/
static RGB_t colors[NUM_COLORS] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}, {255, 128, 0}, {255, 0, 128},
{0, 128, 255}, {128, 64, 0}, {0, 0, 0}};


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
Lights::Lights(int numLEDs, int pin, int brightness){
  
  Adafruit_NeoPixel newStrip = Adafruit_NeoPixel(numLEDs, pin,  NEO_GRB + NEO_KHZ800);
  
  this->strip = newStrip;
  this->num_pixels = numLEDs;
  this->pin = pin;
  this->brightness = brightness;
}


/**
 * @name init
 * 
 * @brief initilizes LED strip, call in setup() 
 **/
void Lights::init(){
  this->strip.begin();
  this->strip.setBrightness(brightness);
  this->strip.clear();
  this->strip.show();
}

/** 
 * @name turnOn
 * 
 * @brief Turn on a specified number of initialized LEDs
 * 
 * @param numLEDs the number of initialized LEDs that will be turned on
 * @param color the desired color of the LEDs
 **/
void Lights::turnOn(uint8_t numLEDs, Color_t color){

  uint32_t ColorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i = 0; i < this->num_pixels; i++){
    if(i < numLEDs){
      strip.setPixelColor(i, ColorValue);
    }

    else{
      strip.setPixelColor(i, 0);
    }
  }
  strip.show();

}

/**
 * @name turnOnAll
 * 
 * @brief Turn on all initialized LEDs in strip 
 * 
 * @param color the desired color for the LEDs
 **/
void Lights::turnOnAll(Color_t color){

  uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i=0; i< this->num_pixels; i++){
    strip.setPixelColor(i, colorValue);
  }

  strip.show();
}


/**
 * @name turnOnLED
 * 
 * @brief turn on a specified LED to a specified color
 * 
 * @param color desired color
 * @param LEDIndex index of the LED
 * 
 **/
void Lights::turnOnLED(Color_t color, uint8_t LEDIndex){

  uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  strip.setPixelColor(LEDIndex, colorValue);

  strip.show();
}


/**
 * @name turnOffLED
 * 
 * @brief turn off a specified LED to a specified color
 * 
 * @param color desired color
 * @param LEDIndex index of the LED
 * 
 **/
void Lights::turnOffLED(uint8_t LEDIndex){
  
  uint32_t colorValue =  strip.Color(colors[OFF].red, colors[OFF].green, colors[OFF].blue);
  
  strip.setPixelColor(LEDIndex, colorValue);

  strip.show();
}

/**
 * @name turnOFF
 * 
 * @brief Turn off all LEDs in strip
 **/
void Lights::turnOff(){
  strip.clear();
  strip.show();
}


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
 void Lights::alternatingLightchase(Color_t color, int wait, int cycles, LED_Direction_t direction){

  /* get color value */
  uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  /* forward */
  if (direction == FORWARD) {
    for (int a = 0; a < cycles; a++) {
      for (int b = 0; b < 3; b++) {
        this->strip.clear();

        for (int c = b; c < this->num_pixels; c += 3) {
          this->strip.setPixelColor(c, colorValue);
        }
        this->strip.show();
        delay(wait);
      }
    }
  }

/* backward */
  else {
    for (int a = cycles; a > 0; a--) {
      for (int b = 3; b > 0; b--) {
        this->strip.clear();

        for (int c = b; c < this->num_pixels; c += 3) {
          this->strip.setPixelColor(c-1, colorValue);
        }
        this->strip.show();
        delay(wait);
      }
    }
  }
}

/**
 * @name solidRainbowChase
 * 
 * @brief Lines/bursts of the rainbow color go around the strip
 * 
 * @param wait the delay/rate at which the lines gfof around the strip
 **/
void Lights::solidRainbowChase(int wait){

  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {

    for (int i = 0; i < this->num_pixels; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / this->num_pixels);
      this->strip.setPixelColor(i, this->strip.gamma32(this->strip.ColorHSV(pixelHue)));
    }

    this->strip.show();
    delay(wait);
  }
}

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
void Lights::lightChase(uint32_t color, int wait, LED_Direction_t direction){

  /* turn off all leds in strip */
  this->strip.clear();

  /* Get the RGB color values for specified color */
  uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  /* make chase go forward */
  if (direction == FORWARD) {

    for (int i = 0; i < this->num_pixels; i++) {
      this->strip.setPixelColor(i, colorValue);        
      this->strip.show();                          
      delay(wait);    
    }                       
}

  /* make chase for backward */
  else {

    for (int i = this->num_pixels; i > -1; i--) {
      this->strip.setPixelColor(i, colorValue);      
      this->strip.show();                          
      delay(wait);
    }
  }

  this->strip.clear();
}

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
void Lights::lineChase(uint32_t color, int wait, LED_Direction_t direction){

  /* turn off all leds in strip */
  this->strip.clear();

  /* Get the RGB color values for specified color */
  uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  if (direction == FORWARD) {

    for (int i = 0; i < this->num_pixels; i++) { 
      this->strip.fill(colorValue, i, 5);
      this->strip.show();                          
      delay(wait);                           
      this->strip.clear();
    }
  }

  else {
    for (int i = this->num_pixels; i > 0; i--) {
      this->strip.fill(colorValue, i-1, 5);
      this->strip.show();                         
      delay(wait);
      this->strip.clear();
    }
  }
}


/**
 * @name splitChase
 * 
 * @brief Two lines of color move around the strip alternating towards and from each other 
 * 
 * @param color desired color
 * @param wait desired wait time/speed of the color lines 
 **/
void Lights::splitChase(uint32_t color, int wait){

  /* turn off all leds in strip */
  this->strip.clear();

  /* Get the RGB color values for specified color */
  uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i=0; i<this->num_pixels; i++){
    this->strip.fill(colorValue, i, 5);
    this->strip.fill(colorValue, this->num_pixels-1-i, 5);

    this->strip.show();
    delay(wait);
    this->strip.clear();
  }
}

/**
 * @brief sets the color for dynamicRainbowChase, theaterRainbowChase and rainbowCycle
 *
 * @param WheelPos current wheel position
 **/
uint32_t Lights::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return this->strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return this->strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return this->strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


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
void Lights::dynamicRainbowChase(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < this->strip.numPixels(); i++) {
      this->strip.setPixelColor(i, Wheel(((i * 256 / this->strip.numPixels()) + j) & 255));
    }
    this->strip.show();
    delay(wait);
  }
}

/**
 * @name rainbowCycle
 * 
 * @brief The strip changes colors at a given rate into the colors of the rainbow
 * 
 * @param wait the delay/rate at which the strip will change colors
 * 
 **/
void Lights::rainbowCycle(uint8_t wait){
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < this->num_pixels; i++) {
      this->strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    this->strip.show();
    delay(wait);
  }
}
