/*
 * Rayon.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#include "Rayon.h"
#include <math.h>
#include <iostream>
Rayon::Rayon() {
	// TODO Auto-generated constructor stub

}

Rayon::~Rayon() {
	// TODO Auto-generated destructor stub
}

bool Rayon::calculPtIntersection(Coord3 ptSphere,std::vector<float> vectDirecteur,float RayonSphere){ // On suppose que l'origine du rayon est le vecteur (0,0,0)
	//but trouver les coef de lequation de degre 2
	float a = vectDirecteur[0]*vectDirecteur[0] + vectDirecteur[1]*vectDirecteur[1] + vectDirecteur[2]*vectDirecteur[2];
	float b = 2*vectDirecteur[0]*ptSphere.x*(-1)+ 2*vectDirecteur[1]*ptSphere.y*(-1) + 2*vectDirecteur[1]*ptSphere.z*(-1);
	float c = ptSphere.x*ptSphere.x+ptSphere.y*ptSphere.y+ptSphere.z*ptSphere.z-RayonSphere*RayonSphere;
	std::vector <float> solution; // On va stocker nos solutions dedans
	float delta = b*b-4*a*c; //calcul du delta
	if(b<0){
		return false; // On ne peut pas avoir de solutions dans r
	}
	else if(b == 0){
		float s = -b/(2*a);
		if(s>0)
			solution.push_back(s);
	}
	else{
		float s1 = -b-sqrt(delta)/2*a;
		float s2 = -b+sqrt(delta)/2*a;
		if(s1>0)
			solution.push_back(s1);
		if(s2>0)
			solution.push_back(s2);
	}
	//coordonnees du (des) point(s) trouves
	std::vector <Coord3> coordonnees;
	for(int i=0;i<solution.size();i++){
		float x= vectDirecteur[0]*solution[i]; // (+ptorigine.x)
		float y= vectDirecteur[1]*solution[i]; // (+ptorigine.y)
		float z= vectDirecteur[2]*solution[i]; // (+ptorigine.z)
		Coord3 c = createCoord3(x, y, z);
		coordonnees.push_back(c);
	}


	return false;
}

