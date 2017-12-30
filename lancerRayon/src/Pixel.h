//============================================================================
// Name        : Pixel.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Un des pixels de l'ecran (header)
//============================================================================

#ifndef PIXEL_H_
#define PIXEL_H_
#include "Coord3.h"
#include "RGB.h"

class Pixel {
private :
	RGB color; // Couleur du Pixel
	Coord3 coord; // Position du Pixel
public:
	Pixel(RGB chColor,Coord3 chCoord) : color(chColor), coord(chCoord){}
	Pixel();
	virtual ~Pixel();
	friend std::ostream& operator<<(std::ostream &out, const Pixel &a);
	//Getters and Setters
	void setCoord3(Coord3 chCoord);
	void setColor(RGB chColor);
	RGB getColor();
	Coord3 getCoord3();
};
//Surcharge Operateur en dehors de la classe
std::ostream& operator<<(std::ostream &out, const Pixel &a);
#endif /* PIXEL_H_ */
