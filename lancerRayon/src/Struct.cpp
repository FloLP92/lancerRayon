/*
 * Struct.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: vdoisne
 */


#include <iostream>
#include "Struct.h"



Coord3 Struct::createCoord3(float x,float y,float z){
	Coord3 c;
	c.x = x;
	c.y = y;
	c.z = z;
	return c;
}
void Struct::coutCoord3(Coord3 c){
	std::cout << c.x << " " << c.y << " " << c.z << std::endl;
}



