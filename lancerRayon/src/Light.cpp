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

