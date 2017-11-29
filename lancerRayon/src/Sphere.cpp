/*
 * Sphere.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */
#include <iostream>
#include "Sphere.h"

Sphere::Sphere(float chRadius, Coord3 chCoord3, float chSurface, float chReflexion) {
	radius = chRadius;
	coord3 = chCoord3;
	surface = chSurface;
	reflexion = chReflexion;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

float Sphere::getRadius(){
	return radius;
}
float Sphere::getSurface(){
	return surface;
}
Coord3 Sphere::getCoord3(){
	return coord3;
}
