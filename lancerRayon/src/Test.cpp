#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "Test.h"
#include "Rayon.h"
#include "Scene.h"
#include "Struct.h"
using namespace std;
Test::Test()
{

}

Test::~Test()
{

}

void Test::test1(){
	Coord3 sphere1(4,0,0);
	valarray<float> vect1;
	vect1[0] = 1;vect1[1] = 0; vect1[2] = 0;
	float rayonSphere = 3;
	boost::optional<Coord3*> test = new Coord3();
	test = Rayon::calculPtIntersection(sphere1, vect1,rayonSphere);
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
	test2 = Rayon::calculPtIntersection(sphere2, vect2,r2);
	assert(test != boost::none);
	cout << "2eme test" << endl;
	for(unsigned int i(0);i< sizeof(test2)/sizeof(*test2);i++){
		//cout << test2.get()[i] << endl;
	}

}

void Test::testParsing(){
	Scene scene;
	scene.lecture();
}
