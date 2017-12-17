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

void Test::test1()
{
	Coord3 sphere1 = Struct::createCoord3(4,0,0);
	std::vector<float> vectDirecteur;
	vectDirecteur.push_back(1);vectDirecteur.push_back(0);vectDirecteur.push_back(0);
	float rayonSphere = 3;
	boost::optional<Coord3*> test = new Coord3();
	test = Rayon::calculPtIntersection(sphere1, vectDirecteur,rayonSphere);
	if(test != boost::none)
		Coord3 a = test.get()[0];
	else
		std::cout << "a";
	//for(int i=0;i< sizeof(test)/sizeof(*test);i++)

		//Struct::coutCoord3(test.get()[0]);
	    //std::cout << Struct::coutCoord3(test.get()[i]) << ' ';
}

