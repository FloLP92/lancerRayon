/*============================================================================
// Name        : Rayon.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Classe implémentant des methodes statiques de calcul utilises par les autres classes (header)
//============================================================================*/

#ifndef RAYON_H_
#define RAYON_H_
#include "Sphere.h"
#include <vector>
#include <valarray>
#include <iostream>
#include <boost/optional.hpp>
#include "Coord3.h"
#include "RGB.h"

class Rayon {
private:
public:
	Rayon();
	virtual ~Rayon();
	//Methodes de calcul
	static boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere,Coord3 origine);
	static int nbPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere,Coord3 origine);
	Coord3 calculRayonReflechi(Coord3 origine,Coord3 ptSurface,Coord3 centreSphere);
	std::valarray<float> calculVecteurUnitaire(std::valarray<float> vecteur);
	static float calculCos(Coord3 position, Coord3 surface,Coord3 sourceLumineuse);
	static RGB calculCouleur(float cos,RGB couleurInter,RGB couleurSource);
	static std::valarray<float> calculVecteur(const Coord3 c1, const Coord3 c2);
	static float calculDistance(Coord3 c1, Coord3 c2);
};

#endif /* RAYON_H_ */
