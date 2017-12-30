//============================================================================
// Name        : RGB.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Code couleur RGB
//============================================================================

#include <iostream>

#include "RGB.h"

RGB::RGB() {}
RGB::~RGB() {}

//Getters and Setters
int RGB::getRed() const{
	return red;
}
int RGB::getGreen() const{
	return green;
}
int RGB::getBlue() const{
	return blue;
}
void RGB::setRed(int chRed){
	red = chRed;
}
void RGB::setGreen(int chGreen){
	green = chGreen;
}
void RGB::setBlue(int chBlue){
	blue = chBlue;
}

std::ostream& operator<<(std::ostream &out, const RGB &a) {//Affichage Coord3
	return out << "Red : " << a.red << " Blue : " << a.blue << " Green " << a.green << std::endl;
}


