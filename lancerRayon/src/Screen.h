//============================================================================
// Name        : Screen.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Ecran de quatre bords avec un ensemble de pixels (header)
//============================================================================
#ifndef SCREEN_H_
#define SCREEN_H_
#include <vector>
#include "Coord3.h"
#include "Pixel.h"
#include "RGB.h"

class Screen {
private:
	RGB color;
	Coord3 tlCorner;
	Coord3 trCorner;
	Coord3 blCorner;
	Coord3 brCorner;
	unsigned int horRes;
	unsigned int verRes;
	std::vector<std::vector<Pixel>> tabPixels;
public:
	Screen(RGB chColor, Coord3 chTlCorner, Coord3 chTrCorner, Coord3 chBlCorner, unsigned int chHorRes, unsigned int chVerRes): color(chColor),
		tlCorner(chTlCorner), trCorner(chTrCorner), blCorner(chBlCorner), horRes(chHorRes), verRes(chVerRes){}
	Screen(){}
	virtual ~Screen();
	void calculBrCorner();
	void calculResVer();
	void creationPixels();
	//Getters and Setters
	RGB getColor();
	Coord3 getTrCorner();
	Coord3 getBlCorner();
	Coord3 getTlCorner();
	Coord3 getBrCorner();
	unsigned int getHorResolution();
	unsigned int getVerResolution();
	std::vector<std::vector<Pixel>> getTabPixels();
	void setColor(RGB c);
	void setTrCorner(const Coord3& c);
	void setBlCorner(const Coord3& c);
	void setTlCorner(const Coord3& c);
	void setBrCorner(const Coord3& c);
	void setHorResolution(const unsigned int& res);
	void setVerResolution(const unsigned int res);
	void setTabPixels(std::vector<std::vector<Pixel>> chTabPixels);
};

#endif /* SCREEN_H_ */
