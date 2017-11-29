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
	RGB color;
	Coord3 tlCorner;
	Coord3 trCorner;
	Coord3 blCorner;
	Coord3 brCorner;
	float horRes;
	float verRes;
public:
	Screen(RGB chColor, Coord3 chTlCorner, Coord3 chTrCorner, Coord3 chBlCorner, float chHorRes, float chVerRes);
	virtual ~Screen();
	void calculBrCorner();

	Coord3 getCoord3() const;
	RGB getColor() const;
	float getTpCorner() const;
	float getBlCorner() const;
	float getHorResolution() const;
	float getVerResolution() const;
};

#endif /* SCREEN_H_ */
