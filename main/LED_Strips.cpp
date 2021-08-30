#include "libraries/LED_Strips/Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"
#include <Arduino.h>
#include "libraries/LED_Strips/LED_Strips.h"


static Color_t colors[NUM_COLORS] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0}};



Lights::Lights(int num_pixels, int pin, int brightness){
  
  Adafruit_NeoPixel newStrip = Adafruit_NeoPixel(num_pixels, pin,  NEO_GRB + NEO_KHZ800);
  
  this->strip = newStrip;
  this->num_pixels = num_pixels;
  this->pin = pin;
  this->brightness = brightness;

  this->strip.begin();
  this->strip.setBrightness(brightness);
  this->strip.show();
}

Lights::turnOn(uint8_t num_pixels, Color_t color){


  uint32_t ColorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i = 0; i < num_pixels; i++){
    strip.setPixelColor(i, ColorValue);
    strip.show();
  }
}

Lights::turnOnAll(Color_t color){

  uint32_t ColorValue = strip.Color(colors[color].red, colors[color].green, colors[color].blue);

  for(int i=0; i< this->num_pixels; i++){
    strip.setPixelColor(i, ColorValue);
    strip.show();
  }
}

Lights::turnOff(){
  strip.clear();
}


/*
Lights::Lights(Adafruit_NeoPixel strip, int num_pixels, int pin, int brightness){
  this->strip = strip;
  this->num_pixels = num_pixels;
  this->pin = pin;
  this->brightness = brightness;

  this->strip.begin();
  this->strip.getBrightness(brightness);
  this->strip.show();
}

 void Lights::chase(uint32_t color, int wait, int times, bool forward){
  if (forward == true) {
    for (int a = 0; a < times; a++) {
      for (int b = 0; b < 3; b++) {
        this->strip.clear();

        for (int c = b; c < this->num_pixels; c += 3) {
          this->strip.setPixelColor(c, color);
        }
        this->strip.show();
        delay(wait);
      }
    }
  }
  else {
    for (int a = times; a > 0; a--) {
      for (int b = 3; b > 0; b--) {
        this->strip.clear();

        for (int c = b; c < NUMPIXELS +1; c += 3) {
          this->strip.setPixelColor(c-1, color);
        }
        this->strip.show();
        delay(wait);
      }
    }
  }
}

void Lights::initializeStrip(Adafruit_NeoPixel strip, int num_pixels, int pin, int brightness){
    this->strip = strip;
    this->num_pixels = num_pixels;
    this->pin = pin;
    this->strip.begin();
    this->strip.getBrightness(brightness);
    this->strip.show();
}

void Lights::solidRainbowChase(int wait){

  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {

    for (int i = 0; i < this->num_pixels; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / this->num_pixels);
      pixel.setPixelColor(i, this->strip.gamma32(this->strip.ColorHSV(pixelHue)));
    }

    this->strip.show();
    delay(wait);
  }
}

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

void Lights::colorWipe3(uint32_t color, int wait){
  
  for(int i=0; i<this->num_pixels; i++){
    this->strip.fill(color, i, 5);
    this->strip.fill(color, NUMPIXELS-1-i, 5);

    this->strip.show();
    delay(wait);
    this->strip.clear();
  }
}


void Lights::colorWipe(uint32_t color, int wait, bool forward){
    if (forward == true) {

    for (int i = 0; i < this->num_pixels; i++) {
      this->strip.setPixelColor(i, color);        
      this->strip.show();                          
      delay(wait);                           
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


void Lights::colorWipe2((uint32_t color, int wait, bool forward){
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
}*/