#include <Adafruit_NeoPixel.h>

int LEDPIN = 6;

int NUMPIXELS = 50;

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

uint32_t green = pixel.Color(0, 100, 0);

uint32_t red = pixel.Color(100, 0, 0);

uint32_t blue = pixel.Color(0, 0, 100);

uint32_t off = pixel.Color(0, 0, 0);

void setup() {
  pixel.begin();
  pixel.setBrightness(50);
  pixel.show();

}

void loop() {
  //idle();
  //startup();
  //victory();
  game();
  //victory();
  //defeat();
}


//turns leds in order along the led strip
//forward = False, lEDs go backwards
void colorWipe(uint32_t color, int wait, bool forward) {
  if (forward == true) {

    for (int i = 0; i < NUMPIXELS; i++) { // For each pixel in strip...
      pixel.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      pixel.show();                          //  Update strip to match
      delay(wait);                           //  Pause for a moment
    }
  }

  else {
    for (int i = NUMPIXELS; i > -1; i--) {
      pixel.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      pixel.show();                          //  Update strip to match
      delay(wait);
    }
  }

  pixel.clear();
}

//3 LEDs turn on along the strip
void colorWipe2(uint32_t color, int wait, bool forward) {
  if (forward == true) {

    for (int i = 0; i < NUMPIXELS; i++) { // For each pixel in strip...
      pixel.fill(color, i, 5);
      pixel.show();                          //  Update strip to match
      delay(wait);                           //  Pause for a moment
      pixel.clear();
    }
  }

  else {
    for (int i = NUMPIXELS; i > 0; i--) {
      pixel.fill(color, i-1, 5);
      pixel.show();                          //  Update strip to match
      delay(wait);
      pixel.clear();
    }
  }

  pixel.clear();
}

void colorWipe3(uint32_t color, int wait){
  for(int i=0; i<NUMPIXELS; i++){
    pixel.fill(color, i, 5);
    pixel.fill(color, NUMPIXELS-1-i, 5);

    pixel.show();
    delay(wait);
    pixel.clear();
  }
  
}

//LEDs change color along the strip
void solidRainbowChase(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < pixel.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / pixel.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      pixel.setPixelColor(i, pixel.gamma32(pixel.ColorHSV(pixelHue)));
    }
    pixel.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

//Chase that has different colors on each LED
void theaterChaseRainbow(int wait, int times, bool forward) {
  if(forward == true){
    int firstPixelHue = 0;     // First pixel starts at red (hue 0)
    for (int a = 0; a < times; a++) { // Repeat 30 times...
      for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
        pixel.clear();         //   Set all pixels in RAM to 0 (off)
        // 'c' counts up from 'b' to end of strip in increments of 3...
        for (int c = b; c < NUMPIXELS; c += 3) {
          // hue of pixel 'c' is offset by an amount to make one full
          // revolution of the color wheel (range 65536) along the length
          // of the strip (strip.numPixels() steps):
          int      hue   = firstPixelHue + c * 65536L / pixel.numPixels();
          uint32_t color = pixel.gamma32(pixel.ColorHSV(hue)); // hue -> RGB
          pixel.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        }
        pixel.show();                // Update strip with new contents
        delay(wait);                 // Pause for a moment
        firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
      }
    }
  }

  else{
    int firstPixelHue = 0;     // First pixel starts at red (hue 0)
    for (int a = times; a > 0; a--) { // Repeat 30 times...
      for (int b = 3; b > 0; b--) { //  'b' counts from 0 to 2...
        pixel.clear();         //   Set all pixels in RAM to 0 (off)
        // 'c' counts up from 'b' to end of strip in increments of 3...
        for (int c = b; c < NUMPIXELS+1 ; c += 3) {
          // hue of pixel 'c' is offset by an amount to make one full
          // revolution of the color wheel (range 65536) along the length
          // of the strip (strip.numPixels() steps):
          int      hue   = firstPixelHue + c * 65536L / pixel.numPixels();
          uint32_t color = pixel.gamma32(pixel.ColorHSV(hue)); // hue -> RGB
          pixel.setPixelColor(c-1, color); // Set pixel 'c' to value 'color'
        }
        pixel.show();                // Update strip with new contents
        delay(wait);                 // Pause for a moment
        firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
      }
    }
  }
}

//all leds are the same color and they cycle color every given seconds
//wait parameter is the time interval for the leds to change color
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < pixel.numPixels(); i++) {
      pixel.setPixelColor(i, Wheel((i + j) & 255));
    }
    pixel.show();
    delay(wait);
  }
}

//chase but looks smoother and slower than the solidRainbowChase
void dynamicRainbowChase(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < pixel.numPixels(); i++) {
      pixel.setPixelColor(i, Wheel(((i * 256 / pixel.numPixels()) + j) & 255));
    }
    pixel.show();
    delay(wait);
  }
}


//function that sets the color for dynamicRainbowChase, theaterRainbowChase and rainbowCycle
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixel.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixel.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixel.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


//LEDs alternate between on and off making it look like they are chasing somthing in a certain direction
void chase(uint32_t color, int wait, int times, bool forward) {
  if (forward == true) {
    for (int a = 0; a < times; a++) {
      for (int b = 0; b < 3; b++) {
        pixel.clear();

        for (int c = b; c < NUMPIXELS; c += 3) {
          pixel.setPixelColor(c, color);
        }
        pixel.show();
        delay(wait);
      }
    }
  }
  else {
    for (int a = times; a > 0; a--) {
      for (int b = 3; b > 0; b--) {
        pixel.clear();

        for (int c = b; c < NUMPIXELS +1; c += 3) {
          pixel.setPixelColor(c-1, color);
        }
        pixel.show();
        delay(wait);
      }
    }
  }
}


//Effects used when victory is achieved
void victory() {

  for (int i = 0; i < 6; i++) {
    pixel.fill(green, 0, NUMPIXELS);
    pixel.show();
    delay(300);

    pixel.fill(off, 0, NUMPIXELS);
    pixel.show();
    delay(300);
  }

  chase(green, 50, 15, true);
  chase(green, 50, 15, false);

}


int counterDefeat = 0;
//effects used when user loses
void defeat() {

  if (counterDefeat == 0) {
    pixel.fill(red, 0, NUMPIXELS);
    pixel.show();
    delay(5000);
    counterDefeat = 1;
  }

  else {
    pixel.fill(red, 0, NUMPIXELS);
    pixel.show();
    delay(1000);

    pixel.fill(off, 0, NUMPIXELS);
    pixel.show();
    delay(1000);
  }
}

//LED effects used whenever the machine is idle/not being used.
void idle() {
  
  solidRainbowChase(10);

}

uint32_t violet = pixel.Color(240, 240, 255);

//LED effects whenever the machine is starting up
void startup(){
  pixel.clear();
  
  theaterChaseRainbow(40, 15, true);
  theaterChaseRainbow(40, 15, false);
  
}

//LED effects while user is playing the game.
void game(){
  theaterChaseRainbow(50, 35, true);


}
