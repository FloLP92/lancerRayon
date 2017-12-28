/*
 * Coord3.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: Florian
 */

#include "Coord3.h"

Coord3::Coord3() {
	// TODO Auto-generated constructor stub

}

Coord3::~Coord3() {
	// TODO Auto-generated destructor stub
}

//On cherche le point parallele a c1 par rapport a middle
Coord3 Coord3::paralleleCoord3(const Coord3 c1, const Coord3 middle)
{
	Coord3 c2;
	c2.x = c1.x == middle.x ? c1.x :
			(c1.x > middle.x ? middle.x - (c1.x - middle.x) :
					middle.x + (middle.x - c1.x) );
	c2.y = c1.y == middle.y ? c1.x :
				(c1.y > middle.y ? middle.y - (c1.y - middle.y) :
						middle.y + (middle.y - c1.y) );
	c2.z = c1.z == middle.z ? c1.z :
				(c1.z > middle.z ? middle.z - (c1.z - middle.z) :
						middle.z + (middle.z - c1.z) );
	return c2;
}



