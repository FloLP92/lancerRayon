/*
 * Pixel.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: Florian
 */

#include "Pixel.h"

Pixel::Pixel() {
}

Pixel::~Pixel() {
}


void Pixel::setCoord3(Coord3 chCoord){
  coord = chCoord;
}
void Pixel::setColor(RGB chColor){
  color = chColor;
}
