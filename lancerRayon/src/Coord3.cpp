//============================================================================
// Name        : Coord3.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Coordonnee d'un point sur l'axe x,y,z
//============================================================================

#include "Coord3.h"

Coord3::Coord3() {}
Coord3::~Coord3() {}

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

//Getters and Setters
float Coord3::getX() const{
	return x;
}
float Coord3::getY() const{
	return y;
}
float Coord3::getZ() const{
	return z;
}
void Coord3::setX(float xx){
	x = xx;
}
void Coord3::setY(float yy){
	y = yy;
}
void Coord3::setZ(float zz){
	z = zz;
}

//Surcharge Operateurs
Coord3 Coord3::operator+ (const Coord3& c) const{//Addition de 2 Coord3
	return Coord3(x + c.x, y + c.y, z + c.z);
}
Coord3 Coord3::operator/ (const int nb) const{//Division Coord3 par un entier
	return Coord3(x/nb, y/nb, z/nb);
}
Coord3& Coord3::operator= (const Coord3& coord){//Affectation Coord3
	x = coord.x;
	y = coord.y;
	z = coord.z;
	return *this;
}
std::ostream& operator<<(std::ostream &out, const Coord3 &a) {//Affichage Coord3
	return out << "x : " << a.x << " y : " << a.y << " z : " << a.z << std::endl;
}
