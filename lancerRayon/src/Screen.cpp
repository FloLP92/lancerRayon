//============================================================================
// Name        : Screen.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Ecran de quatre bords avec un ensemble de pixels
//============================================================================
#include "Screen.h"
#include "Coord3.h"
#include <cmath>

Screen::~Screen() {}
//Calcul du 4eme bord de l'ecran selon les 3 autres bords
void Screen::calculBrCorner()
{
	Coord3 midPointTrBl,a;
	midPointTrBl = (trCorner + blCorner)/2; //milieu de l'autre diagonale
	brCorner = Coord3::paralleleCoord3(tlCorner,midPointTrBl);//On cherche le parallele au bord oppose selon le milieu calcule
}
//Calcul resolution verticale selon les bords et la resolution horizontale
void Screen::calculResVer() {
	unsigned int longueurHorizontale = (unsigned int)sqrt(
			pow((brCorner.getX() - blCorner.getX()), 2)
			+ pow((brCorner.getY() - blCorner.getY()), 2)
			+ pow((brCorner.getZ() - blCorner.getZ()), 2));
	unsigned int longueurVerticale = (unsigned int)sqrt(
			pow((tlCorner.getX() - blCorner.getX()), 2)
			+ pow((tlCorner.getY() - blCorner.getY()), 2)
			+ pow((tlCorner.getZ() - blCorner.getZ()),2));
	verRes = (horRes/longueurHorizontale)*longueurVerticale;
}
//Initialisation du tableau de pixels de notre ecran
void Screen::creationPixels(){
	tabPixels.resize(verRes); //On ajuste selon la resolution verticale
	for (unsigned int i(0); i < verRes; ++i)
		tabPixels[i].resize(horRes); //On ajuste selon la resolution horizontale
	for (unsigned int j(0); j < verRes; ++j) //On initialise couleur et position pour chaque pixel
	{
		for(unsigned int k(0); k < horRes; ++k)
		{
			tabPixels[j][k].setCoord3(Coord3(
				tlCorner.getX() + (j/(float)verRes)*(trCorner.getX() - tlCorner.getX()) + (k/(float)horRes)* (blCorner.getX() - tlCorner.getX()),
				tlCorner.getY() + (j/(float)verRes)*(trCorner.getY() - tlCorner.getY()) + (k/(float)horRes)* (blCorner.getY() - tlCorner.getY()),
				tlCorner.getZ() + (j/(float)verRes)*(trCorner.getZ() - tlCorner.getZ()) + (k/(float)horRes)* (blCorner.getZ() - tlCorner.getZ())));
			tabPixels[j][k].setColor(this->color);
		}
	}
}

//Getters and Setters
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
unsigned int Screen::getHorResolution(){
	return horRes;
}
unsigned int Screen::getVerResolution(){
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
void Screen::setHorResolution(const unsigned int& res){
	horRes = res;
}
void Screen::setVerResolution(const unsigned int res){
	verRes = res;
}
void Screen::setTabPixels(std::vector<std::vector<Pixel>> chTabPixels){
	tabPixels = chTabPixels;
}
