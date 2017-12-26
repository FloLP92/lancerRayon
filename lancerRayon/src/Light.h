/*
 * Light.h
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#ifndef LIGHT_H_
#define LIGHT_H_
#include "Struct.h"

class Light {

private:
	RGB color;
	Coord3 position;


public:
	Light(RGB chColor,Coord3 chPosition);
	Light();
	virtual ~Light();
	void toString();

	void setPosition(Coord3 position);
	Coord3 getPosition();
	void setColor(RGB color);
	RGB getColor();
};

#endif /* LIGHT_H_ */
