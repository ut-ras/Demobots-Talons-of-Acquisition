#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include <Arduino.h>
#include "libraries/LED_Strips/LED_Strips.h"


//TODO: maybe do a chaseALL and chase methods where you choose how many led lights to turn on

static RGB_t colors[NUM_COLORS] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}, {255, 128, 0}, {255, 0, 128},
{0, 128, 255}, {128, 64, 0}, {0, 0, 0}};



Lights::Lights(int num_pixels, int pin, int brightness){
  
  Adafruit_NeoPixel newStrip = Adafruit_NeoPixel(num_pixels, pin,  NEO_GRB + NEO_KHZ800);
  
  this->strip = newStrip;
  this->num_pixels = num_pixels;
  this->pin = pin;
  this->brightness = brightness;
}

void Lights::init(){
  this->strip.begin();
  this->strip.setBrightness(brightness);
  this->strip.show();
}

void Lights::turnOn(uint8_t num_leds, Color_t color){


  uint32_t ColorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i = 0; i < this->num_pixels; i++){
    if(i < num_leds){
      strip.setPixelColor(i, ColorValue);
    }

    else{
      strip.setPixelColor(i, 0);
    }
  }
  strip.show();

}


void Lights::turnOn(Color_t color){

  uint32_t ColorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i=0; i< this->num_pixels; i++){
    strip.setPixelColor(i, ColorValue);
  }

  strip.show();
}

void Lights::turnOff(){
  strip.clear();
}


//wait is in milliseconds
 void Lights::chase(Color_t color, int wait, int cycles, LED_Direction_t direction){

   uint32_t colorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

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


void Lights::colorWipe(uint32_t color, int wait, bool forward){
    if (forward == true) {

    for (int i = 0; i < this->num_pixels; i++) {
      this->strip.setPixelColor(i, color);        
      this->strip.show();                          
      delay(wait);    
    }                       
  }

  else {
    for (int i = this->num_pixels; i > -1; i--) {
      this->strip.setPixelColor(i, color);        
      this->strip.show();                          
      delay(wait);
    }
  }

  this->strip.clear();
}

void Lights::colorWipe2(uint32_t color, int wait, bool forward){
    if (forward == true) {

    for (int i = 0; i < this->num_pixels; i++) { 
      this->strip.fill(color, i, 5);
      this->strip.show();                          
      delay(wait);                           
      this->strip.clear();
    }
  }

  else {
    for (int i = this->num_pixels; i > 0; i--) {
      this->strip.fill(color, i-1, 5);
      this->strip.show();                         
      delay(wait);
      this->strip.clear();
    }
  }

  this->strip.clear();
}

void Lights::colorWipe3(uint32_t color, int wait){
  
  for(int i=0; i<this->num_pixels; i++){
    this->strip.fill(color, i, 5);
    this->strip.fill(color, this->num_pixels-1-i, 5);

    this->strip.show();
    delay(wait);
    this->strip.clear();
  }
}

//function that sets the color for dynamicRainbowChase, theaterRainbowChase and rainbowCycle
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


//chase but looks smoother and slower than the solidRainbowChase
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

/*
void Lights::rainbowCycle(uint8_t wait){
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < this->num_pixels; i++) {
      this->strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    this->strip.show();
    delay(wait);
  }*/
