/*
 * Screen.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#include "Screen.h"

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::calculBrCorner()
{
	Coord3 coord;
	coord.x = trCorner.x;
	coord.y = blCorner.y;
	coord.z = trCorner.z;
	brCorner = coord;
}


RGB Screen::getColor(){
	return color;
}
Coord3 Screen::getTrCorner(){
	return trCorner;
}
Coord3 Screen::getBlCorner(){
	return blCorner;
}
Coord3 Screen::getTlCorner(){
	return tlCorner;
}
Coord3 Screen::getBrCorner(){
	return brCorner;
}
float Screen::getHorResolution(){
	return horRes;
}
float Screen::getVerResolution(){
	return verRes;
}


void Screen::setColor(RGB c){
	color = c;
}
void Screen::setTrCorner(Coord3 c){
	trCorner = c;
}
void Screen::setBlCorner(Coord3 c){
	blCorner = c;
}
void Screen::setTlCorner(Coord3 c){
	tlCorner = c;
}
void Screen::setBrCorner(Coord3 c){
	brCorner = c;
}
void Screen::setHorResolution(float res){
	horRes = res;
}
void Screen::setVerResolution(float res){
	verRes = res;
}
