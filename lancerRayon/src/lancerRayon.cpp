//============================================================================
// Name        : lancerRayon.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Programme principale avec le main, active le lancer de rayons et lance les diff�rents tests
//============================================================================//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "RGB.h"
#include "Test.h"
#include "Scene.h"
using namespace std;

int main() {
	Scene scene1;
	scene1.lecture(); // Lecture et Parsage du fichier en elements contenus dans notre scene
	scene1.imageSansReflexion(); // Calcul de l'image sans reflexion
	scene1.write_image(); // Ecriture du fichier ppm contenant l'image precedente
	Test::testParsing();
	Test::testCalculVecteur();
	Test::testlectureEtInters();
	std::vector<Coord3*> tabIntersection;
	boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere);
	return 0;
}

Coord3 equaRay(Coord3 chCamera, Coord3 chLight)
{
	Coord3 ray;
	return ray;
}
