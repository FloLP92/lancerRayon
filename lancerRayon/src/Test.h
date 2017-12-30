//============================================================================
// Name        : Test.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Tests des differentes fonctions (header)
//============================================================================

#ifndef TEST_H_
#define TEST_H_
#include <iostream>

class Test {

private:

public:
	Test();
	virtual ~Test();
	static void testIntersection(); //Test Intersections previsibles
	static void testCalculVecteur(); //Test calcul de vecteur directeur entre 2 points
	static void testlectureEtInters(); //Test lecture, parsing et calcul de points d'intersections
	static void testParsing(); //Test lecture et parsing dans les differents objets de la scene
};



#endif /* TEST_H_ */
