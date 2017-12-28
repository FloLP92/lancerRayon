/*
 * Screen.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#include "Screen.h"
#include "Coord3.h"
#include <cmath>

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::calculBrCorner()
{
	Coord3 midPointTrBl,a;
	/*coord.x = trCorner.x;
	coord.y = blCorner.y;
	coord.z = trCorner.z;
	brCorner = coord;*/
	midPointTrBl = (trCorner + blCorner)/2;
	brCorner = Coord3::paralleleCoord3(tlCorner,midPointTrBl);
}
void Screen::calculResVer() //Calcul res verticale selon les bords
{

	int longueurHorizontale = sqrt(
			pow((brCorner.x - blCorner.x), 2)
			+ pow((brCorner.y - blCorner.y), 2)
			+ pow((brCorner.z - blCorner.z), 2));

	int longueurVerticale = sqrt(
			pow((tlCorner.x - blCorner.x), 2)
			+ pow((tlCorner.y - blCorner.y), 2)
			+ pow((tlCorner.z - blCorner.z),2));

	verRes = (horRes/longueurHorizontale)*longueurVerticale;
}
void Screen::creationPixels()
{
	tabPixels.resize(verRes);
	for (unsigned int i(0); i < verRes; ++i)
		tabPixels[i].resize(horRes);

	for (unsigned int j(0); j < verRes; ++j)
	{
		for(unsigned int k(0); k < horRes; ++k)
		{
			tabPixels[j][k].setCoord3(Coord3(
						tlCorner.x + ((double)j/verRes)*(trCorner.x - tlCorner.x) + ((double)k/horRes)* (blCorner.x - tlCorner.x),
						tlCorner.y + ((double)j/verRes)*(trCorner.y - tlCorner.y) + ((double)k/horRes)* (blCorner.y - tlCorner.y),
						tlCorner.z + ((double)j/verRes)*(trCorner.z - tlCorner.z) + ((double)k/horRes)* (blCorner.z - tlCorner.z)));
		}
	}
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
