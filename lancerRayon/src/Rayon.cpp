/*
 * Rayon.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#include "Rayon.h"
#include <math.h>

Rayon::Rayon() {
	// TODO Auto-generated constructor stub

}

Rayon::~Rayon() {
	// TODO Auto-generated destructor stub
}

bool Rayon::calculPtIntersection(Coord3 ptOrigine,std::vector<float> vectDirecteur,float RayonSphere){
	//but trouver les coef de lequation de degre 2
	float a = vectDirecteur[0]*vectDirecteur[0] + vectDirecteur[1]*vectDirecteur[1] + vectDirecteur[2]*vectDirecteur[2];
	float b = 2*vectDirecteur[0]*ptOrigine.x+ 2*vectDirecteur[1]*ptOrigine.y + 2*vectDirecteur[1]*ptOrigine.z;
	float c = ptOrigine.x*ptOrigine.x+ptOrigine.y*ptOrigine.y+ptOrigine.z*ptOrigine.z-RayonSphere*RayonSphere;
	float solution=0;
	float delta = b*b-4*a*c; //calcul du delta
	if(b<0){
		return false; // On ne peut pas avoir de solutions dans r
	}
	else if(b == 0){
		solution = -b/(2*a);
	}
	else{
		solution = -b-sqrt(delta)/2*a;
		//solution = -b+sqrt(delta)/2*a;
	}
	//coordonnees du point
	float x= vectDirecteur[0]*solution+ptOrigine.x;
	float y= vectDirecteur[1]*solution+ptOrigine.y;
	float z= vectDirecteur[2]*solution+ptOrigine.z;

	return false;
}

