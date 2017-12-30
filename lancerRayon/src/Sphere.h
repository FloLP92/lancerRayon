//============================================================================
// Name        : Sphere.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Objet de type sphere qui herite de Object (header)
//============================================================================

#ifndef SPHERE_H_
#define SPHERE_H_
#include "Coord3.h"
#include "RGB.h"
#include "Object.h"

class Sphere : public Object {
private :
	float radius; //rayon
public:
	Sphere() : Object(){}
	Sphere(float chRadius, Coord3 chCenter, float chReflexion,RGB color) : Object(chCenter,color,chReflexion), radius(chRadius){}
	virtual ~Sphere();
	friend std::ostream& operator<<(std::ostream &out, const Sphere &a);
	void afficher(){};
	//Getters and Setters
	float getRadius();
};
std::ostream& operator<<(std::ostream &out, const Sphere &a);
#endif /* SPHERE_H_ */
