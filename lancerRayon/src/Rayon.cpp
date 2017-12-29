/*
 * Rayon.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: vincent.doisneau
 */

#include "Rayon.h"
#include <math.h>
#include <iostream>
#include "Sphere.h"
#include <valarray>


Rayon::Rayon() {
	// TODO Auto-generated constructor stub

}

Rayon::~Rayon() {
	// TODO Auto-generated destructor stub
}

boost::optional<Coord3*> Rayon::calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere,Coord3 origineRayon){ // On suppose que l'origine du rayon est le vecteur (0,0,0)
	//but trouver les coef de lequation de degre 2
	float a = vectDirecteur[0]*vectDirecteur[0] + vectDirecteur[1]*vectDirecteur[1] + vectDirecteur[2]*vectDirecteur[2];
	float b = 2*vectDirecteur[0]*(origineRayon.getX()-ptSphere.getX())*(-1) + 2*vectDirecteur[1]*(origineRayon.getY()-ptSphere.getY())*(-1) + 2*vectDirecteur[2]*(origineRayon.getZ()-ptSphere.getZ())*(-1);
	float c = (origineRayon.getX()-ptSphere.getX())*(origineRayon.getX()-ptSphere.getX()) + (origineRayon.getY()-ptSphere.getY())*(origineRayon.getY()-ptSphere.getY()) + (origineRayon.getZ()-ptSphere.getZ())*(origineRayon.getZ()-ptSphere.getZ())-RayonSphere*RayonSphere;
	std::vector<float> solution; // On va stocker nos solutions reelles dedans
	//std::cout<<" a : "<<a<<" b : "<<b<<" c: "<<c<<std::endl;
	float delta = b*b-4*a*c; //calcul du delta
	if(delta<0){
		return boost::none; // On ne peut pas avoir de solutions dans r
	}
	else
	{
		if(b == 0){
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
		boost::optional<Coord3*> coordonnees = new Coord3[solution.size()];
		for(unsigned int i(0);i<solution.size();i++){
			float x= vectDirecteur[0]*solution[i]; // (+ptorigine.x)
			float y= vectDirecteur[1]*solution[i]; // (+ptorigine.y)
			float z= vectDirecteur[2]*solution[i]; // (+ptorigine.z)
			Coord3 c = Coord3(x, y, z);
			coordonnees.get()[i] = c;
		}
		return coordonnees;
	}
}

bool Rayon::calculRayonReflechi(std::valarray<float> rayonIncident,Sphere s,Coord3 ptInter){

	//First Step : get normal vector

	//First Step. Point 1 : get vector origin sphere and intersection
	std::valarray<float> rayon(3);
	rayon[0] = ptInter.getX()-s.getCenter().getX();
	rayon[1] = ptInter.getY()-s.getCenter().getY();
	rayon[2] = ptInter.getZ()-s.getCenter().getZ();

	//First Step. Point 2 : norme
	float n = sqrt(rayon[0]*rayon[0] + rayon[1]*rayon[1] + rayon[2]*rayon[2]);

	//First Step. Point 3 : normale
	std::valarray<float> normale (3);
	normale[0] = rayon[0]/n;
	normale[1] = rayon[1]/n;
	normale[2] = rayon[2]/n;

	//Second step : get cos

	float cos = rayonIncident[0]*normale[0] + rayonIncident[1]*normale[1] + rayonIncident[2]*normale[2];
	float no = sqrt(normale[0]*normale[0] + normale[1]*normale[1] + normale[2]*normale[2])*sqrt(rayonIncident[0]*rayonIncident[0] + rayonIncident[1]*rayonIncident[1] + rayonIncident[2]*rayonIncident[2]);
	cos = cos/no;

	return false;

}
float Rayon::calculCos(std::valarray<float> rayonIncident,Sphere s,Coord3 ptInter){
	//First Step : get normal vector

		//First Step. Point 1 : get vector origin sphere and intersection
		std::valarray<float> rayon(3);
		rayon[0] = ptInter.getX()-s.getCenter().getX();
		rayon[1] = ptInter.getY()-s.getCenter().getY();
		rayon[2] = ptInter.getZ()-s.getCenter().getZ();

		//First Step. Point 2 : norme
		float n = sqrt(rayon[0]*rayon[0] + rayon[1]*rayon[1] + rayon[2]*rayon[2]);

		//First Step. Point 3 : normale
		std::valarray<float> normale (3);
		normale[0] = rayon[0]/n;
		normale[1] = rayon[1]/n;
		normale[2] = rayon[2]/n;

		//Second step : get cos

		float cos = rayonIncident[0]*normale[0] + rayonIncident[1]*normale[1] + rayonIncident[2]*normale[2];
		float no = sqrt(normale[0]*normale[0] + normale[1]*normale[1] + normale[2]*normale[2])*sqrt(rayonIncident[0]*rayonIncident[0] + rayonIncident[1]*rayonIncident[1] + rayonIncident[2]*rayonIncident[2]);
		cos = cos/no;

		return cos;
}
RGB Rayon::calculCouleur(float cos,RGB couleurInter,RGB couleurSource){
	RGB couleurFinale;
	float red,green,blue;
	red = couleurInter.red*couleurSource.red;
	green = couleurInter.green*couleurSource.green;
	blue = couleurInter.blue*couleurSource.blue;
	red *= cos;
	green *= cos;
	blue *= cos;

	couleurFinale.red = (int) red;
	couleurFinale.green = (int) green;
	couleurFinale.blue = (int) blue;

	//retravailler float en int
	return couleurFinale;
}
std::valarray<float> Rayon::calculVecteur(const Coord3 c1, const Coord3 c2)
{
	std::valarray<float> vect(3);
	vect[0] = (c2.getX() - c1.getX());
	vect[1] = (c2.getY() - c1.getY());
	vect[2] = (c2.getZ() - c1.getZ());
	return vect;
}
float Rayon::calculDistance(Coord3 c1, Coord3 c2){
	float dist = sqrt(pow(c1.getX() - c2.getX(), 2)
			+ pow(c1.getY() - c2.getY(), 2)
			+ pow(c1.getZ() - c2.getZ(), 2));
	return dist;
}
