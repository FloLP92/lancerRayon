/*
 * Coord3.h
 *
 *  Created on: 28 Dec 2017
 *      Author: Florian
 */

#ifndef COORD3_H_
#define COORD3_H_
#include <iostream>
#include<valarray>

class Coord3 {
private:
	float x,y,z;
public:
	Coord3(float chX,float chY,float chZ) : x(chX), y(chY), z(chZ){}
	Coord3();
	virtual ~Coord3();
	friend std::ostream& operator<<(std::ostream &out, const Coord3 &a);

	static Coord3 paralleleCoord3(const Coord3 c1, const Coord3 middle);

	//Surcharge operateurs
	Coord3 operator+ (const Coord3& c) const;//Addition de 2 Coord3
	Coord3 operator/ (const int nb) const;//Division d un Coord3
	Coord3& operator= (const Coord3&);

	float getX() const;
	float getY() const;
	float getZ() const;
	void setX(float xx);
	void setY(float yy);
	void setZ(float zz);
};

std::ostream& operator<<(std::ostream &out, const Coord3 &a);
#endif /* COORD3_H_ */
