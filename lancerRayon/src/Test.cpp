//============================================================================
// Name        : Test.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Tests des differentes fonctions
//============================================================================
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "Test.h"
#include "Rayon.h"
#include "RGB.h"
#include "Scene.h"
using namespace std;

Test::Test()
{}
Test::~Test()
{}
//Tests d'intersections previsibles dont l'on peut s'assurer du resultat
void Test::testIntersection(){
	Coord3 sphere1(4,0,0);
	valarray<float> vect1;
	vect1[0] = 1;vect1[1] = 0; vect1[2] = 0;
	float rayonSphere = 3;
	boost::optional<Coord3*> test = new Coord3();
	Coord3 origine = Coord3(0,0,0);
	test = Rayon::calculPtIntersection(sphere1, vect1,rayonSphere,origine);
	assert(test != boost::none);
	cout << "1er test" << endl;
	for(unsigned int i(0);i< sizeof(test)/sizeof(*test);i++){
		//cout << test.get()[i] << endl;
	}
	Coord3 sphere2(0,4,0);
	valarray<float> vect2;
	vect2[0] = 0;vect2[1] = 1;vect2[2] = 0;
	float r2 = 3;
	boost::optional<Coord3*> test2 = new Coord3();
	test2 = Rayon::calculPtIntersection(sphere2, vect2,r2,origine);
	assert(test != boost::none);
	cout << "2eme test" << endl;
	for(unsigned int i(0);i< sizeof(test2)/sizeof(*test2);i++){
		//cout << test2.get()[i] << endl;
	}
}
//Tests du calcul de vecteur directeur entre 2 points
void Test::testCalculVecteur(){
	Coord3 a(2,5,1);
	Coord3 b(9,2,10);
	valarray<float> vect = Rayon::calculVecteur(a,b);
	assert(vect[0] == 7);
	assert(vect[1] == -3);
	assert(vect[2] == 9);
}
//Test de la lecture du fichier, son parsage et une intersection prise au hasard
void Test::testlectureEtInters()
{
	Scene scene;
	scene.lecture();
	Coord3 origine = Coord3(0,0,0);
	Screen screen = scene.getScreen();
	valarray<float> vectDirecteur = Rayon::calculVecteur(scene.getCamera(),screen.getTabPixels()[1][3].getCoord3());
	cout << "coord pixel " << screen.getTabPixels()[1][3] << endl;
	Sphere sphere = scene.getTabSphere()[0];
	cout << "sphere " << sphere << endl;
}
//Test de la lecture du fichier, son parsage et verification de ce que l'on a parser
void Test::testParsing(){
	Scene scene;
	scene.lecture();
	Screen screen = scene.getScreen();
	cout << "TlCorner " << screen.getTlCorner();
	cout << "TrCorner " << screen.getTrCorner();
	cout << "BlCorner " << screen.getBlCorner();
	cout << "BrCorner " << screen.getBrCorner();
	cout << "Hor Res " << screen.getHorResolution() << endl;
	cout << "Ver Res " << screen.getVerResolution() << endl;
	cout << "taille tableau sphere " << scene.getTabSphere().size()<< endl;
}
