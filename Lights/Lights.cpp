#include "Libraries/Lights/Lights.h"
#include "Libraries/LEDStrips/LEDStrips.h"



void idle(LEDStrips strip){

    /* wait until a signal is received */
    while(true){
        strip.solidRainbowChase(10);

    }
}
