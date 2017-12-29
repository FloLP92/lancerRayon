/*
 * Sphere.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */
#include <iostream>
#include "Sphere.h"

Sphere::Sphere(){}
Sphere::Sphere(float chRadius, Coord3 chCoord3, float chReflexion,RGB c) {
	radius = chRadius;
	center = chCoord3;
	reflexion = chReflexion;
	color = c;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

RGB Sphere::getColor(){
	return color;
}
void Sphere::setColor(RGB chColor){
	color = chColor;
}
float Sphere::getRadius(){
	return radius;
}

Coord3 Sphere::getCenter(){
	return center;
}
float Sphere::getReflexion(){
	return reflexion;
}

std::ostream& operator<<(std::ostream &out, const Sphere &a) {//Affichage Coord3
	return out << "Sphere - Center : " << a.center << " Color : " << a.color << " Radius " << a.radius << " Reflexion " << a.reflexion << std::endl;
}






