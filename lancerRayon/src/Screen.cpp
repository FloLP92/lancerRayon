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

	unsigned int longueurHorizontale = sqrt(
			pow((brCorner.getX() - blCorner.getX()), 2)
			+ pow((brCorner.getY() - blCorner.getY()), 2)
			+ pow((brCorner.getZ() - blCorner.getZ()), 2));
	std::cout<< "Point A "<<std::endl;

	unsigned int longueurVerticale = sqrt(
			pow((tlCorner.getX() - blCorner.getX()), 2)
			+ pow((tlCorner.getY() - blCorner.getY()), 2)
			+ pow((tlCorner.getZ() - blCorner.getZ()),2));
	std::cout<< "Point B "<<std::endl;
	std::cout<< horRes <<std::endl;
	std::cout<< longueurHorizontale <<std::endl;
	std::cout<< "Point bis "<<std::endl;
	verRes = (horRes/longueurHorizontale)*longueurVerticale;
	std::cout<< "Point C "<<std::endl;
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
						tlCorner.getX() + ((double)j/verRes)*(trCorner.getX() - tlCorner.getX()) + ((double)k/horRes)* (blCorner.getX() - tlCorner.getX()),
						tlCorner.getY() + ((double)j/verRes)*(trCorner.getY() - tlCorner.getY()) + ((double)k/horRes)* (blCorner.getY() - tlCorner.getY()),
						tlCorner.getZ() + ((double)j/verRes)*(trCorner.getZ() - tlCorner.getZ()) + ((double)k/horRes)* (blCorner.getZ() - tlCorner.getZ())));
			tabPixels[j][k].setColor(this->color);
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

std::vector<std::vector<Pixel>> Screen::getTabPixels(){
	return tabPixels;
}

void Screen::setColor(RGB c){
	color = c;
}
void Screen::setTrCorner(const Coord3& c){
	trCorner = c;
}
void Screen::setBlCorner(const Coord3& c){
	blCorner = c;
}
void Screen::setTlCorner(const Coord3& c){
	tlCorner = c;
}
void Screen::setBrCorner(const Coord3& c){
	brCorner = c;
}
void Screen::setHorResolution(const float res){
	horRes = res;
}
void Screen::setVerResolution(const float res){
	verRes = res;
}
