/*
 * Screen.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#include "Screen.h"


Screen::Screen(RGB chColor, Coord3 chTlCorner, Coord3 chTrCorner, Coord3 chBlCorner, float chHorRes, float chVerRes){
	color = chColor;
	tlCorner = chTlCorner;
	trCorner = chTrCorner;
	blCorner = chBlCorner;
	horRes = chHorRes;
	verRes = chVerRes;
	//calculBrCorner();
}
Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::calculBrCorner()
{
	Coord3 coord;
	coord.x = trCorner.x;
	coord.y = blCorner.y;
	coord.z = trCorner.z;
	brCorner = coord;
}
