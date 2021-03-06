/*============================================================================
// Name        : Rayon.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Classe impl�mentant des methodes statiques de calcul utilises par les autres classes
//============================================================================*/

#include "Rayon.h"
#include <math.h>
#include <iostream>
#include "Sphere.h"
#include <valarray>

Rayon::Rayon() {
}
Rayon::~Rayon() {
}

//Determine des possibles points d'intersections entre un point origineRayon et une sphere en suivant un vecteur directeur
//Si pas de points, renvoie boost::none
boost::optional<Coord3*> Rayon::calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere,Coord3 origineRayon){
	//but trouver les coef de lequation de degre 2

	float a = vectDirecteur[0]*vectDirecteur[0] + vectDirecteur[1]*vectDirecteur[1] + vectDirecteur[2]*vectDirecteur[2];
	float b = 2 * ( vectDirecteur[0]*(origineRayon.getX()-ptSphere.getX()) + vectDirecteur[1]*(origineRayon.getY()-ptSphere.getY()) + vectDirecteur[2]*(origineRayon.getZ()-ptSphere.getZ()) );
	float c = (origineRayon.getX()-ptSphere.getX())*(origineRayon.getX()-ptSphere.getX()) + (origineRayon.getY()-ptSphere.getY())*(origineRayon.getY()-ptSphere.getY()) + (origineRayon.getZ()-ptSphere.getZ())*(origineRayon.getZ()-ptSphere.getZ())-RayonSphere*RayonSphere;
	std::vector<float> solution; // On va stocker nos solutions reelles dedans
	float delta = b*b-4*a*c; //calcul du delta

	if(delta<0){
		return boost::none; // On ne peut pas avoir de solutions dans r
	}
	else
	{
		if(delta == 0){
			float s = -b/(2*a);
			if(s>0)
				solution.push_back(s);
			else{
				return boost::none;
			}
		}
		if(delta>0){
			float s1 = (-b-sqrt(delta))/(2*a);
			float s2 = (-b+sqrt(delta))/(2*a);
			if(s1>0){
				solution.push_back(s1);
				if(s2>0){
					solution.push_back(s2);
				}
			}
			else
			{
				if(s2>0){
					solution.push_back(s2);
				}
				else
					return boost::none;
			}
		}
		//coordonnees du (des) point(s) trouves
		boost::optional<Coord3*> coordonnees = new Coord3[solution.size()];

		for(unsigned int i(0);i<solution.size();i++){
			float x= vectDirecteur[0]*solution[i] + origineRayon.getX(); // (+ptorigine.x)
			float y= vectDirecteur[1]*solution[i] + origineRayon.getY(); // (+ptorigine.y)
			float z= vectDirecteur[2]*solution[i] + origineRayon.getZ(); // (+ptorigine.z)
			Coord3 c = Coord3(x, y, z);
			coordonnees.get()[i] = c;

		}
		return coordonnees;
	}
}
//Renvoie le nombre de points d'intersections entre un point origineRayon et une sphere en suivant un vecteur directeur
int Rayon::nbPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere,Coord3 origineRayon){ // On suppose que l'origine du rayon est le vecteur (0,0,0)
	//but trouver les coef de lequation de degre 2

	float a = vectDirecteur[0]*vectDirecteur[0] + vectDirecteur[1]*vectDirecteur[1] + vectDirecteur[2]*vectDirecteur[2];
	float b = 2 * ( vectDirecteur[0]*(origineRayon.getX()-ptSphere.getX()) + vectDirecteur[1]*(origineRayon.getY()-ptSphere.getY()) + vectDirecteur[2]*(origineRayon.getZ()-ptSphere.getZ()) );
	float c = (origineRayon.getX()-ptSphere.getX())*(origineRayon.getX()-ptSphere.getX()) + (origineRayon.getY()-ptSphere.getY())*(origineRayon.getY()-ptSphere.getY()) + (origineRayon.getZ()-ptSphere.getZ())*(origineRayon.getZ()-ptSphere.getZ())-RayonSphere*RayonSphere;
	int solution=0; // On va stocker nos solutions reelles dedans
	float delta = b*b-4*a*c; //calcul du delta

	if(delta<0){

	}
	else
	{
		if(delta == 0){
			float s = -b/(2*a);
			if(s>0)
				solution++;
		}
		if(delta>0){

			float s1 = (-b-sqrt(delta))/(2*a);
			float s2 = (-b+sqrt(delta))/(2*a);
			if(s1>0){
				solution = solution+1;
			}
			if(s2>0){
				solution = solution+1;
			}
		}
	}
	return solution;
}


// calcul le cosinus entre la normale d'une sphere et l'angle d'incidence
float Rayon::calculCos(Coord3 position, Coord3 surface,Coord3 sourceLumineuse){

	//Calcul du produit scalaire entre les deux vecteurs ( rayon incident et normale au point de reflexion)
	float scalaire = ((position.getX() - surface.getX()) * (sourceLumineuse.getX() - surface.getX())
		+ (position.getY() - surface.getY()) * (sourceLumineuse.getY() - surface.getY())
		+ (position.getZ() - surface.getZ()) * (sourceLumineuse.getZ() - surface.getZ()));

	//Norme de la normale ||(x,y,z)|| = x^2+y^2+z^2
	float normeN = sqrt(pow(position.getX() - surface.getX(), 2)
		+ pow(position.getY() - surface.getY(), 2)
		+ pow(position.getZ() - surface.getZ(), 2));

		//Norme du rayon incident ||(x,y,z)|| = x^2+y^2+z^2
	float normeR = sqrt(pow(sourceLumineuse.getX() - surface.getX(), 2)
		+ pow(sourceLumineuse.getY() - surface.getY(), 2)
		+ pow(sourceLumineuse.getZ() - surface.getZ(), 2));

	//On remet en positive si la valeur trouvée est négative
	float cosinus = 	scalaire/(normeN * normeR);
	cosinus = sqrt(cosinus*cosinus);
	return cosinus;
}

//Calcul de la couleur sans reflexion
RGB Rayon::calculCouleur(float cos,RGB couleurInter,RGB couleurSource){
	RGB couleurFinale;
	float red,green,blue;
	red = (couleurInter.getRed()*couleurSource.getRed())/255;
	green = (couleurInter.getGreen()*couleurSource.getGreen())/255;
	blue = (couleurInter.getBlue()*couleurSource.getBlue())/255;
	red *= cos;
	green *= cos;
	blue *= cos;

	couleurFinale.setRed((int) red);
	couleurFinale.setGreen((int) green);
	couleurFinale.setBlue((int) blue);


	return couleurFinale;
}

//Calcul de la couleur avec Reflexion
RGB Rayon::calculCouleur2(float cos,RGB couleurRayon,RGB couleurSource,RGB couleurInter,float coefReflexion){
	RGB couleurFinale;
	float red,green,blue;
	red = (couleurInter.getRed()*couleurSource.getRed())/255;
	green = (couleurInter.getGreen()*couleurSource.getGreen())/255;
	blue = (couleurInter.getBlue()*couleurSource.getBlue())/255;
	red *= cos;
	green *= cos;
	blue *= cos;
	red *= (1-coefReflexion);
	green *= (1-coefReflexion);
	blue *= (1-coefReflexion);
	float a = coefReflexion*couleurRayon.getRed();
	float b = coefReflexion*couleurRayon.getGreen();
	float c = coefReflexion*couleurRayon.getBlue();
	red += a;
	blue += b;
	green += c;
	couleurFinale.setRed((int) red);
	couleurFinale.setGreen((int) green);
	couleurFinale.setBlue((int) blue);


	return couleurFinale;
}
//Renvoie le vecteur directeur entre les point c1 et c2
std::valarray<float> Rayon::calculVecteur(const Coord3 c1, const Coord3 c2)
{
	std::valarray<float> vect(3);
	vect[0] = (c2.getX() - c1.getX());
	vect[1] = (c2.getY() - c1.getY());
	vect[2] = (c2.getZ() - c1.getZ());
	return vect;
}

//Calcul du rayon reflechi : on recupere un point sur le rayon qui est reflechi sur la sphere
Coord3 Rayon::calculRayonReflechi(Coord3 origine,Coord3 ptSurface,Coord3 centreSphere){
	std::valarray<float> vect = Rayon::calculVecteur(origine,ptSurface);
	vect = calculVecteurUnitaire(vect);

	//vecteur normale
	std::valarray<float> vect2 = Rayon::calculVecteur(centreSphere,ptSurface);
	vect2 = calculVecteurUnitaire(vect2);

	std::valarray<float> res = vect - vect2*( sqrt(vect[0]*vect[0]+vect[1]*vect[1]+vect[2]*vect[2]) * sqrt(vect2[0]*vect2[0]+vect2[1]*vect2[1]+vect2[2]*vect2[2]) * Rayon::calculCos(centreSphere,ptSurface,origine) )*2;

	ptSurface.setX(ptSurface.getX()+res[0]);
	ptSurface.setY(ptSurface.getY()+res[1]);
	ptSurface.setZ(ptSurface.getZ()+res[2]);
	return ptSurface;
}

//Calcul du vecteur unitaire
std::valarray<float> Rayon::calculVecteurUnitaire(std::valarray<float> vecteur){
	std::valarray<float> vectDirecteur = vecteur;
	float normeVecteurDirecteur = sqrt(vectDirecteur[0]*vectDirecteur[0]+vectDirecteur[1]*vectDirecteur[1]+vectDirecteur[2]*vectDirecteur[2]);
	vectDirecteur[0] = vectDirecteur[0]/normeVecteurDirecteur;
	vectDirecteur[1] = vectDirecteur[1]/normeVecteurDirecteur;
	vectDirecteur[2] = vectDirecteur[2]/normeVecteurDirecteur;
	return vectDirecteur;
}
//Renvoie la distance entre les points c1 et c2
float Rayon::calculDistance(Coord3 c1, Coord3 c2){
	float dist = sqrt(pow(c1.getX() - c2.getX(), 2)
			+ pow(c1.getY() - c2.getY(), 2)
			+ pow(c1.getZ() - c2.getZ(), 2));
	return dist;
}
