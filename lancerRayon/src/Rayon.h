/*
 * Rayon.h
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#ifndef RAYON_H_
#define RAYON_H_

class Rayon {

private:


public:
	Rayon();
	virtual ~Rayon();
	bool calculPtIntersection(Coord3 ptOrigine,std::vector<float> vectDirecteur,float RayonSphere);
};

#endif /* RAYON_H_ */
