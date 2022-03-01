#include "Libraries/Lights/Lights.h"
#include "Libraries/Lights/LEDStrips/LEDStrips.h"
#include <Arduino.h>


void turnOnOff(LEDStrips strip, Color_t color, int times, int msDelay){
   
    for(int i=0; i<times; i++){
        //strip.turnOnAll(color);
        delay(msDelay);
        strip.turnOff();
    }

}


void idle(LEDStrips strip){

    /* wait until a signal is received */
    while(true){
        strip.solidRainbowChase(10);

    }
}

void inGame(LEDStrips strip){

    strip.dynamicRainbowChase(50);
    
}


void victory(LEDStrips strip){

    /* turn lights on and off with green color */
    turnOnOff(strip, LEDSTRIPS_GREEN, 6, 300);

    for(int i=0; i<15; i++){
        strip.lineChase(LEDSTRIPS_GREEN, 50, LEDSTRIPS_FORWARD);
    }

    for(int i=0; i<15; i++){
        strip.lineChase(LEDSTRIPS_GREEN, 15, LEDSTRIPS_BACKWARD);
    }
}

void lost(LEDStrips strip){

    turnOnOff(strip, LEDSTRIPS_RED, 6, 300);

    for(int i=0; i<15; i++){
        strip.lineChase(LEDSTRIPS_RED, 50, LEDSTRIPS_FORWARD);
    }

    for(int i=0; i<15; i++){
        strip.lineChase(LEDSTRIPS_RED, 15, LEDSTRIPS_BACKWARD);
    }
}
