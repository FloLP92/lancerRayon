//============================================================================
// Name        : Object.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Representation basique d'un objet, classe mere abstraite herite par les figures concretes
//============================================================================//

#include "Object.h"

Object::Object() {
}
Object::~Object() {
}
//Getter and Setters
RGB Object::getColor(){
	return color;
}
Coord3 Object::getCenter(){
	return center;
}
float Object::getReflexion(){
	return reflexion;
}
void Object::setColor(RGB chColor){
	color = chColor;
}
void Object::setCenter(Coord3 chCenter){
	center = chCenter;
}
void Object::setReflexion(float chReflexion){
	reflexion = chReflexion;
}
