/*============================================================================
// Name        : Scene.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Implemente la scene avec tous les elements a l interieur (header)
//============================================================================*/
#ifndef SCENE_H_
#define SCENE_H_
#include <vector>
#include <iostream>
#include <valarray>
#include <boost/optional.hpp>
#include "Sphere.h"
#include "Light.h"
#include "Screen.h"

class Scene {
private:
	std::vector<Sphere> tabSphere; // tableau de spheres
	Light light;
	Coord3 camera;
	Screen screen;
public:
	Scene(){}
	virtual ~Scene();
	void write_image(); //exporte les pixels et le reste des informations dans un fichier ppm
	void lecture(); //lit et parse un fichier texte
	bool eclaireParSource(Coord3 coordPoint); //renvoie bool selon si coordPoint eclaire par la source (methode 1)
	bool eclaireParSource2(Coord3 coordPoint); //verifie si coordPoint eclaire par la source (methode 2)
	bool calculRayonSansRef(std::valarray<float> rayonIncident,Sphere s,Coord3 ptInter);
	void imageSansReflexion(); //calcul d'une image apres lancer de rayons sans reflexion
	//Getters and Setters
	Screen getScreen();
	void setScreen(Screen s);
	Light getLight();
	void setLight(Light l);
	Coord3 getCamera();
	void setCamera(Coord3 c);
	std::vector<Sphere> getTabSphere();
};

#endif /* SCENE_H_ */
