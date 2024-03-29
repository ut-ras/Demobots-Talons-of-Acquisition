/**
 * Author: Dario Jimenez
 * Last Modified: 12/23/2021
 * Project: Talons of Acquisition
 * File: Lights.h
 * Description: header file for LED strips for the Talons of Acquisition machine
 * Organization: UT IEEE RAS Demobots
 */

#ifndef Lights_H
#define Lights_H

#include "LEDStrips/LEDStrips.h"



void idle(LEDStrips strip);

void inGame(LEDStrips strip);

void GameOver(LEDStrips strip);

void victory(LEDStrips strip);

void lost(LEDStrips strip);


#endif