/*
 * Rayon.h
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#ifndef RAYON_H_
#define RAYON_H_
#include "Sphere.h"
#include "Struct.h"
#include <vector>
#include <valarray>
#include <iostream>
#include <boost/optional.hpp>
#include "Coord3.h"

class Rayon {

private:


public:
	Rayon();
	virtual ~Rayon();
	static boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere);
	bool calculRayonReflechi(std::valarray<float> rayonIncident,Sphere s,Coord3 ptInter);
	RGB calculCouleur(float cos,RGB couleurInter,RGB couleurSource);
};

#endif /* RAYON_H_ */
