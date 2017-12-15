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
	float surface;
	float reflexion;
public:
	Sphere(float chRadius, Coord3 chCenter, float chSurface, float chReflexion);
	virtual ~Sphere();
	float getRadius();
	Coord3 getCenter();
	float getSurface();
};

#endif /* SPHERE_H_ */
