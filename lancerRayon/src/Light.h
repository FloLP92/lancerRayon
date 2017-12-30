//============================================================================
// Name        : Light.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Source de lumiere (header)
//============================================================================//

#ifndef LIGHT_H_
#define LIGHT_H_
#include "Coord3.h"
#include "RGB.h"

class Light {
private:
	RGB color; // Couleur de la lumiere
	Coord3 position; // Position de la lumiere
public:
	Light(RGB chColor,Coord3 chPosition);
	Light();
	virtual ~Light();
	//Getters and Setters
	void toString();
	void setPosition(Coord3 position);
	Coord3 getPosition();
	void setColor(RGB color);
	RGB getColor();
};

#endif /* LIGHT_H_ */
