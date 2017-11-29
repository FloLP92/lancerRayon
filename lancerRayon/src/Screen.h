/*
 * Screen.h
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include "Struct.h"

class Screen {
private :
	Coord3 coord3;
	RGB color;
	float tpCorner;
	float blCorner;
	float horRes;
	float verRes;
public:
	Screen(Coord3 chCoord3, RGB chColor, float chTpCorner, float chBlCorner, float chHorRes, float chVerRes);
	virtual ~Screen();
	Coord3 getCoord3();
	RGB getColor();
	float getTpCorner();
	float getBlCorner();
	float getHorResolution();
	float getVerResolution();
};

#endif /* SCREEN_H_ */
