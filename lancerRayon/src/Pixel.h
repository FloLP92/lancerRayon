/*
 * Pixel.h
 *
 *  Created on: 28 Dec 2017
 *      Author: Florian
 */

#ifndef PIXEL_H_
#define PIXEL_H_
#include "Struct.h"
#include "Coord3.h"

class Pixel {
private :
	RGB color;
	Coord3 coord;
public:
	Pixel(RGB chColor,Coord3 chCoord) : color(chColor), coord(chCoord){}
	Pixel();
	virtual ~Pixel();
	friend std::ostream& operator<<(std::ostream &out, const Pixel &a);

	void setCoord3(Coord3 chCoord);
	void setColor(RGB chColor);
	RGB getColor();
	Coord3 getCoord3();
};

std::ostream& operator<<(std::ostream &out, const Pixel &a);
#endif /* PIXEL_H_ */
