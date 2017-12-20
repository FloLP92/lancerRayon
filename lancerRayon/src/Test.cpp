#include <iostream>
#include <vector>
#include <math.h>
#include "Test.h"
#include "Rayon.h"
#include "Struct.h"
Test::Test()
{

}

Test::~Test()
{

}

void Test::test1(){
	Coord3 sphere1 = Struct::createCoord3(4,0,0);
	std::vector<float> vect1;
	vect1.push_back(1);vect1.push_back(0);vect1.push_back(0);
	float rayonSphere = 3;
	boost::optional<Coord3*> test = new Coord3();
	test = Rayon::calculPtIntersection(sphere1, vect1,rayonSphere);
	if(test == boost::none)
		std::cout << "Il n'y a pas de points d'interections";
	else{
		std::cout << "a";
		for(unsigned int i(0);i< sizeof(test)/sizeof(*test);i++){
			Struct::coutCoord3(test.get()[i]);
		}
	}

	Coord3 sphere2 = Struct::createCoord3(0,4,0);
	std::vector<float> vect2;
	vect2.push_back(0);vect2.push_back(1);vect2.push_back(0);
	float r2 = 3;
	boost::optional<Coord3*> test2 = new Coord3();
	test2 = Rayon::calculPtIntersection(sphere2, vect2,r2);
	if(test2 == boost::none)
		std::cout << "Il n'y a pas de points d'interections";
	else{
		for(unsigned int i(0);i< sizeof(test2)/sizeof(*test2);i++){
			Struct::coutCoord3(test2.get()[i]);
		}
	}

}

