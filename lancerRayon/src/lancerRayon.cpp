//============================================================================
// Name        : lancerRayon.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "Test.h"
#include "Scene.h"
using namespace std;

int main() {
	Light light;
	Scene scene1;

	scene1.lecture();
	scene1.imageSansReflexion();
	scene1.write_image();
	//Test::testParsing();
	//Test::testCalculVecteur();
	cout << "taille tableau sphere " << scene1.getTabSphere().size()<< endl;
	std::vector<Coord3*> tabIntersection;
	boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere);
	return 0;
}

Coord3 equaRay(Coord3 chCamera, Coord3 chLight)
{
	Coord3 ray;
	return ray;
}
