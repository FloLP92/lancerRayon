//============================================================================
// Name        : Pixel.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Un des pixels de l'ecran
//============================================================================//

#include "Pixel.h"

Pixel::Pixel() {
}
Pixel::~Pixel() {
}

//Getters and Setters
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
//Surcharge Operateur
std::ostream& operator<<(std::ostream &out, const Pixel &a) {//Affichage Coord3
	return out << "Coord : " << a.coord << " color : " << a.color << std::endl;
}
