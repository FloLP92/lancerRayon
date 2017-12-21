/*
 * Screen.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#include "Screen.h"

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
