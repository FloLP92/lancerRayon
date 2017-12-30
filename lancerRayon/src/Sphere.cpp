//============================================================================
// Name        : Sphere.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Objet de type sphere heritant de Object
//============================================================================
#include <iostream>
#include "Sphere.h"

Sphere::~Sphere() {}

float Sphere::getRadius(){
	return radius;
}
//Affichage d'une sphere
std::ostream& operator<<(std::ostream &out, const Sphere &a) {//Affichage Coord3
	return out << "Sphere - Center : " << a.center << " Color : " << a.color << " Radius " << a.radius << " Reflexion " << a.reflexion << std::endl;
}






