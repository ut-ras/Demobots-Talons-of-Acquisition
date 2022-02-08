#include "Libraries/Lights/Lights.h"
#include "Libraries/LEDStrips/LEDStrips.h"
#include <Arduino.h>


void turnOnOff(Color_t color, int times, int delay){
   
    for(int i=0; i<times; i++){
        strip.turnOnAll(color);
        delay(delay);
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
    turnOnOff(GREEN, 6, 300);

    for(int i=0; i<15; i++){
        strip.lineChase(GREEN, 50, FORWARD);
    }

    for(int i=0; i<15){
        strip.lineChase(GREEN, 15, BACKWARD);
    }
}

void lost(LEDStrips strip){

    turnOnOff(RED, 6, 300);

    for(int i=0; i<15; i++){
        strip.lineChase(RED, 50, FORWARD);
    }

    for(int i=0; i<15){
        strip.lineChase(RED, 15, BACKWARD);
    }
}

