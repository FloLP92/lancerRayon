/*
 * Sphere.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */
#include <iostream>
#include "Sphere.h"

Sphere::Sphere(float chRadius, Coord3 chCoord3, float chReflexion,RGB c) {
	radius = chRadius;
	center = chCoord3;
	reflexion = chReflexion;
	color = c;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

float Sphere::getRadius(){
	return radius;
}

Coord3 Sphere::getCenter(){
	return center;
}
