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
	Coord3 coord3;
	float surface;
	float reflexion;
public:
	Sphere(float chRadius, Coord3 chCoord3, float chSurface, float chReflexion);
	virtual ~Sphere();
	float getRadius();
	Coord3 getCoord3();
	float getSurface();
};

#endif /* SPHERE_H_ */
