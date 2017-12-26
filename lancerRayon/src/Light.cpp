/*
 * Light.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#include <iostream>
#include "Light.h"


Light::Light(RGB chColor,Coord3 chPosition) {
	color = chColor;
	position = chPosition;
}

Light::Light(){

}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

void Light::toString(){
	std::cout<<"hello"<<std::endl;
}

RGB Light::getColor(){
	return color;
}
void Light::setColor(RGB c){
	color = c;
}

Coord3 Light::getPosition(){
	return position;
}
void Light::setPosition(Coord3 p){
	position = p;
}
