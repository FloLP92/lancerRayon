/*
 * Sphere.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */
#include <iostream>
#include "Sphere.h"

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

float Sphere::getRadius(){
	return radius;
}

std::ostream& operator<<(std::ostream &out, const Sphere &a) {//Affichage Coord3
	return out << "Sphere - Center : " << a.center << " Color : " << a.color << " Radius " << a.radius << " Reflexion " << a.reflexion << std::endl;
}






