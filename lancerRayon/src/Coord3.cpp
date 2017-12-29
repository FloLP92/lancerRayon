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

Coord3 Coord3::operator+ (const Coord3& c) const{//Addition de 2 Coord3
	return Coord3(x + c.x, y + c.y, z + c.z);
}
Coord3 Coord3::operator/ (const int nb) const{//Division d un Coord3
	return Coord3(x/nb, y/nb, z/nb);
}
Coord3& Coord3::operator= (const Coord3& coord){
	x = coord.x;
	y = coord.y;
	z = coord.z;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Coord3 &a) {//Affichage Coord3
	return out << "x : " << a.x << " y : " << a.y << " z : " << a.z << std::endl;
}
