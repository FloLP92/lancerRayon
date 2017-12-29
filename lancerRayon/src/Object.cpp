/*
 * Object.cpp
 *
 *  Created on: 29 Dec 2017
 *      Author: Florian
 */

#include "Object.h"

Object::Object() {
	// TODO Auto-generated constructor stub
}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

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
