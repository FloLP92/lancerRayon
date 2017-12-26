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
	Screen(RGB chColor, Coord3 chTlCorner, Coord3 chTrCorner, Coord3 chBlCorner, float chHorRes, float chVerRes): color(chColor),
		tlCorner(chTlCorner), trCorner(chTrCorner), blCorner(chBlCorner), horRes(chHorRes), verRes(chVerRes){}
	Screen(){horRes = 0; verRes = 0;}
	virtual ~Screen();
	void calculBrCorner();

	RGB getColor();
	Coord3 getTrCorner();
	Coord3 getBlCorner();
	Coord3 getTlCorner();
	Coord3 getBrCorner();
	float getHorResolution();
	float getVerResolution();

	void setColor(RGB c);
	void setTrCorner(Coord3 c);
	void setBlCorner(Coord3 c);
	void setTlCorner(Coord3 c);
	void setBrCorner(Coord3 c);
	void setHorResolution(float res);
	void setVerResolution(float res);
};

#endif /* SCREEN_H_ */
