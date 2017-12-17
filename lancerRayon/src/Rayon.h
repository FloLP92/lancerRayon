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
#include <iostream>
#include <boost/optional.hpp>

class Rayon {

private:


public:
	Rayon();
	virtual ~Rayon();
	static boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::vector<float> vectDirecteur,float RayonSphere);
	bool calculRayonReflechi(std::vector<float> rayonIncident,Sphere s,Coord3 ptInter);
};

#endif /* RAYON_H_ */
