/*
 * Sphere.h
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include "Struct.h"

class Sphere {
private :
	float radius;
	Coord3 center;
	float reflexion;
	RGB color;
public:
	Sphere(float chRadius, Coord3 chCenter, float chReflexion,RGB color);
	virtual ~Sphere();
	float getRadius();
	Coord3 getCenter();
};

#endif /* SPHERE_H_ */
