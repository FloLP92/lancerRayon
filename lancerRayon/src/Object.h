//============================================================================
// Name        : Object.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Representation basique d'un objet, classe mere abstraite herite par les figures concretes (header)
//============================================================================//

#ifndef OBJECT_H_
#define OBJECT_H_
#include "Struct.h"
#include "Coord3.h"

class Object {
private :
	Coord3 center; // Centre de l'objet
	RGB color; // Couleur de l'objet
	float reflexion; // Coefficient de reflexion de l'objet
public:
	Object();
	Object(Coord3 chCenter, RGB chColor, float chRef) :
		center(chCenter),color(chColor),reflexion(chRef){}
	virtual ~Object();
	virtual void afficher() = 0;
	//Getters and Setters
	RGB getColor();
	Coord3 getCenter();
	float getReflexion();
	void setColor(RGB chColor);
	void setCenter(Coord3 chCenter);
	void setReflexion(float chReflexion);
};

#endif /* OBJECT_H_ */
