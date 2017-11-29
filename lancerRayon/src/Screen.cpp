/*
 * Screen.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#include "Screen.h"


Screen::Screen(Coord3 chCoord3, RGB chColor, float chTpCorner, float chBlCorner, float chHorRes, float chVerRes){
	coord3 = chCoord3;
	color = chColor;
	tpCorner = chTpCorner;
	blCorner = chBlCorner;
	horRes = chHorRes;
	verRes = chVerRes;
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}
