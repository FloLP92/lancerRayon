/*
 * Object.h
 *
 *  Created on: 29 Dec 2017
 *      Author: Florian
 */

#ifndef OBJECT_H_
#define OBJECT_H_
#include "Struct.h"
#include "Coord3.h"

class Object {
private :
	Coord3 center;
	RGB color;
	float reflexion;
public:
	Object();
	Object(Coord3 chCenter, RGB chColor, float chRef) :
		center(chCenter),color(chColor),reflexion(chRef){}
	virtual ~Object();

	RGB getColor();
	Coord3 getCenter();
	float getReflexion();
	void setColor(RGB chColor);
	void setCenter(Coord3 chCenter);
	void setReflexion(float chReflexion);
};

#endif /* OBJECT_H_ */
