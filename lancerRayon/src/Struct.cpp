/*
 * Struct.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: vincent.doisneau
 */

#include "Struct.h"
#include <iostream>

#ifndef Struct_CPP
#define Struct_CPP

using namespace std;

struct Coord3{
	float x;
	float y;
	float z;

};

Coord3 createCoord3(float x,float y,float z){
	Coord3 c = new Coord3();
	c.x = x;
	c.y = y;
	c.z = z;
	return c;
}


