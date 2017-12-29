/*
 * Sphere.h
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include "Struct.h"
#include "Coord3.h"

class Sphere {
private :
	float radius;
	Coord3 center;
	float reflexion;
	RGB color;
public:
	Sphere();
	Sphere(float chRadius, Coord3 chCenter, float chReflexion,RGB color);
	virtual ~Sphere();

	RGB getColor();
	void setColor(RGB chColor);
	float getRadius();
	Coord3 getCenter();
	float getReflexion();
};

#endif /* SPHERE_H_ */
