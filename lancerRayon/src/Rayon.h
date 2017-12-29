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
	static boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere,Coord3 origine);
	static float calculCos(Coord3 position, Coord3 surface,Coord3 sourceLumineuse);
	static RGB calculCouleur(float cos,RGB couleurInter,RGB couleurSource);
	static std::valarray<float> calculVecteur(const Coord3 c1, const Coord3 c2);
	static float calculDistance(Coord3 c1, Coord3 c2);

};

#endif /* RAYON_H_ */
