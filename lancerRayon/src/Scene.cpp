/*============================================================================
// Name        : Scene.cpp
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Implemente la scene avec tous les elements a l interieur
//============================================================================*/
#include "Scene.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "Light.h"
#include "Rayon.h"
#include <cmath>
using namespace std;

Scene::~Scene() {}
//renvoie bool selon si coordPoint eclaire par la source (methode 1)
bool Scene::eclaireParSource(Coord3 coordPoint)
{
	//On calcule le vecteur directeur

	valarray<float> vectDirecteur = Rayon::calculVecteur(light.getPosition(),coordPoint);
	bool b = true;
	float normeVecteurDirecteur = sqrt(vectDirecteur[0]*vectDirecteur[0]+vectDirecteur[1]*vectDirecteur[1]+vectDirecteur[2]*vectDirecteur[2]);
	vectDirecteur[0] = vectDirecteur[0]/normeVecteurDirecteur;
	vectDirecteur[1] = vectDirecteur[1]/normeVecteurDirecteur;
	vectDirecteur[2] = vectDirecteur[2]/normeVecteurDirecteur;
	boost::optional<Coord3*> inters = new Coord3();
	double epsilon = 0.05;

	for(Sphere sphere : tabSphere) //On teste pour chaque objet s ils bloquent la lumiere
	{
		inters = Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),light.getPosition());
		int nbInters = Rayon::nbPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),light.getPosition());

		if(nbInters==1){
			Coord3 point1 =  inters.get()[0];
			if( Rayon::calculDistance(coordPoint,light.getPosition()) <=  Rayon::calculDistance(point1,light.getPosition())+epsilon){

			}
			else{
				return false;
				break;
			}
		}
		else if(nbInters==2)
		{
			Coord3 point1 =  inters.get()[0];
			Coord3 point2 =  inters.get()[1];
			if( Rayon::calculDistance(coordPoint,light.getPosition()) <=  Rayon::calculDistance(point1,light.getPosition())+epsilon && Rayon::calculDistance(coordPoint,light.getPosition()) <=  Rayon::calculDistance(point2,light.getPosition())+epsilon){

			}
			else{
				return false;
				break;
			}
		}
		else if(nbInters>2){
			return false;
		}
	}
	return b;
}
//renvoie bool selon si coordPoint eclaire par la source (methode 2)
bool Scene::eclaireParSource2(Coord3 coordPoint)
{
	valarray<float> vectDirecteur = Rayon::calculVecteur(coordPoint,light.getPosition());
	float normeVecteurDirecteur = sqrt(vectDirecteur[0]*vectDirecteur[0]+vectDirecteur[1]*vectDirecteur[1]+vectDirecteur[2]*vectDirecteur[2]);
	vectDirecteur[0] = vectDirecteur[0]/normeVecteurDirecteur;
	vectDirecteur[1] = vectDirecteur[1]/normeVecteurDirecteur;
	vectDirecteur[2] = vectDirecteur[2]/normeVecteurDirecteur;
	Coord3 coordEnCours = coordPoint;
	float distance;
	//on va remonter du point jusqua la source
	do{
		for(Sphere sphere : tabSphere) //On teste pour chaque objet s ils bloquent la lumiere
		{
			//Si on est dans le champ dune sphere
			float d = Rayon::calculDistance(sphere.getCenter(),coordEnCours);
			if(d<sphere.getRadius())
				return false;
		}
		distance = Rayon::calculDistance(coordEnCours,light.getPosition());
		coordEnCours.setX(coordEnCours.getX()-vectDirecteur[0]);
		coordEnCours.setY(coordEnCours.getY()-vectDirecteur[1]);
		coordEnCours.setZ(coordEnCours.getZ()-vectDirecteur[2]);
	}while(distance>Rayon::calculDistance(coordEnCours,light.getPosition()));
	return true;
}
//lit et parse un fichier texte
void Scene::lecture(){
	std::ifstream infile("aParser.txt");

	std::string line;
	int dataRead = 0; // nombre de données lues

	//Variables tampons qui seront utilisees pour stocker les donnees lues
	string aP,bP,cP,dP,eP,fP,gP,hP,infos;
	float aF,bF,cF,dF,hF;

	std::string::size_type sz; //Variable used to convert string into float (or int)
	Light l;
	this->setLight(l);
	Screen s;
	this->setScreen(s);
	Coord3 tl;
	Coord3 tr;
	Coord3 bl;
	Coord3 br;
	unsigned int horres = 0;
	unsigned int verres = 0;
	RGB colorBG;
	Coord3 coordLight;
	RGB colorLight;
	l.setPosition(coordLight);
	l.setColor(colorLight);
	s.setColor(colorBG);
	this->screen.setHorResolution(horres);
	this->screen.setVerResolution(verres);

	Coord3 coordSphere;
	RGB colorSphere;
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);// tete de lecture

	   	//on commence par lire le premier mot : si il contient # au début c'est un comment donc on passe
	   	//sinon c'est une donnée utile : on sait quelle donnee utile c'est parce que on a un compteur qui permet
	   	// de savoir combien de donnees utiles on a lues. (donc ou on en est dans le fichier).
	   	// et on peut traiter en fonction de ce que c'est (utilisation switch).


	    if (!(iss >> aP)) { break; } // On lit le premier mot de la ligne
	    else if(aP.compare("#")!=0){ // on ne tombe par sur un commentaire : c'est une donnee utile
	    	dataRead++; // On incremente le nombre de données utiles lues
	    	aP.erase (std::remove(aP.begin(), aP.end(),','), aP.end()); //on supprimes les , de la ligne
	    	switch(dataRead){ // savoir quel type de donnee on va lire (ou on en est dans la lecture du fichier)
	    		case 1: //Camera position (on lit 2 autres données sur cette ligne)
	    			iss >> bP >> cP; // on place le reste des mots de la ligne dans les autres variables
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());//on supprime les ',' du mot (on ne veut retenir que les nombre,
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());// pas les virgules avec, utile quand on va passer de str a float)

						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						this->camera.setX(aF);
						this->camera.setY(bF);
						this->camera.setZ(cF);

	    			break;
	    		case 2: //Top left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());

						aF = (float)std::stoi(aP,&sz);
						bF = (float)std::stoi(bP,&sz);
						cF = (float)std::stoi(cP,&sz);
						tl.setX(aF); tl.setY(bF); tl.setZ(cF);

	    			break;
	    		case 3: //Top right corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());

						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						tr.setX(aF); tr.setY(bF); tr.setZ(cF);
	    			break;
	    		case 4 : // Bottom left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						bl.setX(aF); bl.setY(bF); bl.setZ(cF);
	    			break;
	    		case 5 : // screen horizontal resolution (on lit 1 donnee sur cette ligne)
						horres = std::stoi(aP,&sz);
						this->screen.setHorResolution(horres);
	    			break;
	    		case 6 : // background color (on lit 2 autres donnees sur cette ligne
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    				colorBG.setRed(std::stoi(aP,&sz));
	    				colorBG.setGreen(std::stoi(bP,&sz));
	    				colorBG.setBlue(std::stoi(cP,&sz));
						this->screen.setColor(colorBG);
	    			break;
	    		case 7 : // Light source position (x,y,z) and color(rgb): on lit 5 autres donnees
	    			iss >> bP >> cP >> dP >> eP >> fP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			dP.erase (std::remove(dP.begin(), dP.end(),','), dP.end());
	    			eP.erase (std::remove(eP.begin(), eP.end(),','), eP.end());
	    			fP.erase (std::remove(fP.begin(), fP.end(),','), fP.end());

						/*partie cast(string to float, puis float to int pour le RGB) */

						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						colorLight.setRed(std::stoi(dP,&sz));
						colorLight.setGreen(std::stoi(eP,&sz));
						colorLight.setBlue(std::stoi(fP,&sz));
						coordLight.setX(aF); coordLight.setY(bF); coordLight.setZ(cF);
						this->light.setPosition(coordLight);
						this->light.setColor(colorLight);
	    			break;

	    		default : //reste des infos utiles cad la liste des cercles en bas du fichier
	    			iss >> infos >> bP >> cP >> dP >> eP >> fP >> gP >> hP; //8 donnees utiles : (3coord + 1radius + 3colors + 1reflexion)
	    			infos.erase (std::remove(infos.begin(), infos.end(),','), infos.end());
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			dP.erase (std::remove(dP.begin(), dP.end(),','), dP.end());
	    			eP.erase (std::remove(eP.begin(), eP.end(),','), eP.end());
	    			fP.erase (std::remove(fP.begin(), fP.end(),','), fP.end());
	    			gP.erase (std::remove(gP.begin(), gP.end(),','), gP.end());// remove commas
	    			hP.erase (std::remove(hP.begin(), hP.end(),','), hP.end());

						aF = std::stof(infos,&sz);//coordx
						bF = std::stof(bP,&sz);//coordy
						cF = std::stof(cP,&sz);//coordz
						dF = std::stof(dP,&sz);//radius
						colorSphere.setRed(std::stoi(eP,&sz));//red
						colorSphere.setGreen(std::stoi(fP,&sz));//green
						colorSphere.setBlue(std::stoi(gP,&sz));//blue
						hF = std::stof(hP,&sz);//reflex

						coordSphere.setX(aF); coordSphere.setY(bF); coordSphere.setZ(cF);
						Sphere sphere1 = Sphere(dF,coordSphere,hF,colorSphere);
						this->tabSphere.push_back(sphere1);
						break;
	    	}//end switch
	    }// end if comment
	}// end while read

	this->screen.setTrCorner(tr);
	this->screen.setTlCorner(tl);
	this->screen.setBlCorner(bl);
	this->screen.setBrCorner(br);
	screen.calculBrCorner();
	screen.calculResVer();
	screen.creationPixels();
}
//calcul d'une image apres lancer de rayons sans reflexion
void Scene::imageSansReflexion()//Calcul de l image sans reflexion
{
	vector<vector<Pixel>> tabPixels = screen.getTabPixels();
	boost::optional<Coord3*> inters = new Coord3(); //Tous nos points intersections
	std::valarray<float> vectDirecteur;
	Sphere objet;
	Coord3 pointInters; //Point le plus proche
	Coord3 point1, point2;
	float distInters = 0; //distance du point le plus proche
	float distance1,distance2;

	//partie 2 :
	vector<Coord3> pointsSource;// points a partir desquels partent la reflexion
	vector<Coord3> pointsRayon; // point sur le trajet de la reflexion
	vector<RGB> couleurs;// couleur de la source du rayon (premier rebond rayon)

	for (unsigned int i(0); i < screen.getVerResolution(); ++i)
		{
			for(unsigned int j(0); j < screen.getHorResolution(); ++j)
			{
				for(Sphere sphere : tabSphere)//On va chercher intersection la plus proche
				{
					vectDirecteur = Rayon::calculVecteur(camera,tabPixels[i][j].getCoord3());
					inters = Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),camera);
					int nbInters = Rayon::nbPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),camera);

					if(nbInters>0)//On a au moins un point d intersections
					{
						if(nbInters==2) //On doit prendre le plus proche
						{

							point1 = inters.get()[0];
							point2 = inters.get()[1];
							distance1 = Rayon::calculDistance(camera,point1);
							distance2 = Rayon::calculDistance(camera,point2);
							if(distance1 < distance2)
							{
								distInters = distance1;
								pointInters = point1;
								objet = sphere;
							}
							else
							{
								distInters = distance2;
								pointInters = point2;
								objet = sphere;
							}

						}
						else // 1 seul point, pas de choix possible
						{
							point1 = inters.get()[0];
							distance1 = Rayon::calculDistance(camera,point1);
							distInters = distance1;
							pointInters = point1;
							objet = sphere;
						}
					}
				} //End for sphere
				if(distInters != 0)//On a eu au moins une intersection
				{

					if(Scene::eclaireParSource(pointInters))
					{
						float cos = Rayon::calculCos(objet.getCenter(),pointInters,light.getPosition());
						tabPixels[i][j].setColor(Rayon::calculCouleur(cos,objet.getColor(),light.getColor()));

						//On garde des elements pour ensuite calculer plus tard la deuxieme reflexion
						pointsSource.push_back(pointInters);
						Coord3 ptRayon = Rayon::calculRayonReflechi(light.getPosition(),pointInters,objet.getCenter());
						pointsRayon.push_back(ptRayon);
						couleurs.push_back(objet.getColor());

					}
					else{ //Pas dans la lumiere :  on met la couleur noire a la place
						RGB coloration;
						coloration.setRed(0);coloration.setGreen(0);coloration.setBlue(0);
						tabPixels[i][j].setColor(coloration);
					}
				}
				distInters = 0;
			}
		}

		///PARTIE2 : reflexion
		/*for(unsigned int i(0); i < pointsSource.size(); ++i){
			std::valarray<float> vectDirecteur = Rayon::calculVecteur(pointsSource[i],pointsRayon[i]);
			for(Sphere sphere : tabSphere)//On va chercher intersection la plus proche
			{
					inters = Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),pointsSource[i]);
					int nbInters = Rayon::nbPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),pointsSource[i]);
					if(nbInters>0)//On a au moins un point d intersections
					{
						if(nbInters==2) //On doit prendre le plus proche
						{

							point1 = inters.get()[0];
							point2 = inters.get()[1];
							distance1 = Rayon::calculDistance(pointsSource[i],point1);
							distance2 = Rayon::calculDistance(pointsSource[i],point2);
							if(distance1 < distance2)
							{
								distInters = distance1;
								pointInters = point1;
								objet = sphere;
							}
							else
							{
								distInters = distance2;
								pointInters = point2;
								objet = sphere;
							}

						}
						else // 1 seul point, pas de choix possible
						{
							point1 = inters.get()[0];
							distance1 = Rayon::calculDistance(pointsSource[i],point1);
							distInters = distance1;
							pointInters = point1;
							objet = sphere;
						}
					}
				}// End for sphere
				if(distInters != 0)//On a eu au moins une intersection
				{
					std::valarray<float> vectCameraEcran; //vecteur entre camera et ecran
					std::valarray<float> vectCameraPoint = Rayon::calculVecteur(camera,pointInters);//vecteur entre camera et point d'intersection
					//On cherche quel point de l'ecran il faut changer : on va regarder pour chaque point de lecran si on trouve un vecteur collineaire a celui du vecteur camera->pointintersection
					for (unsigned int j(0); j < screen.getVerResolution(); ++j)
					{
						for(unsigned int k(0); k < screen.getHorResolution(); ++k)
						{
							vectCameraEcran = Rayon::calculVecteur(camera,tabPixels[j][k].getCoord3());
							//On trouve le point sur l'ecran qui sera affecte en verifiant si les vecteurs sont collineaires
							if(vectCameraPoint[0]/vectCameraEcran[0] == vectCameraPoint[1]/vectCameraEcran[1] && vectCameraPoint[1]/vectCameraEcran[1] == vectCameraPoint[2]/vectCameraEcran[2]){
								float cos = Rayon::calculCos(objet.getCenter(),pointInters,pointsSource[i]);
								tabPixels[j][k].setColor(Rayon::calculCouleur2(cos,couleurs[i],light.getColor(),objet.getColor(),objet.getReflexion()));
							}
						}
					}
				}
			}//end for*/


	screen.setTabPixels(tabPixels);
}
//exporte les pixels et le reste des informations dans un fichier ppm
void Scene::write_image(){ //Creation du fichier ppm
	std::ofstream outfile;
	outfile.open("new.ppm");
	outfile<<"P3\n";
	outfile<<this->screen.getHorResolution()<<" "<<this->screen.getVerResolution()<<"\n";
	outfile<<"255\n";


	std::vector<std::vector<Pixel>> tabPixels = this->screen.getTabPixels();
	for (unsigned int j(0); j < this->screen.getVerResolution(); ++j)
	{
		for(unsigned int k(0); k < this->screen.getHorResolution(); ++k)
		{
			outfile<<tabPixels[j][k].getColor().getRed()<<" "<< tabPixels[j][k].getColor().getGreen()<<" "<<tabPixels[j][k].getColor().getBlue()<<"\t";
		}
		outfile<<"\n";
	}
	outfile.close();
}

//Getters and Setters
Screen Scene::getScreen(){
	return screen;
}
void Scene::setScreen(Screen chScreen){
	screen = chScreen;
}
Light Scene::getLight(){
	return light;
}
void Scene::setLight(Light chLight){
	light = chLight;
}
vector<Sphere> Scene::getTabSphere(){
	return tabSphere;
}
Coord3 Scene::getCamera(){
	return camera;
}
void Scene::setCamera(Coord3 c){
	camera = c;
}
