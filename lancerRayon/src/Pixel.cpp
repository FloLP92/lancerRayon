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

RGB Pixel::getColor(){
  return color;
}
Coord3 Pixel::getCoord3(){
  return coord;
}

std::ostream& operator<<(std::ostream &out, const Pixel &a) {//Affichage Coord3
	return out << "Coord : " << a.coord << " color : " << a.color << std::endl;
}
