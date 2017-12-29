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

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}

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

//renvoit boolean indiquant si point eclaire par source lumineuse
bool Scene::eclaireParSource(Coord3 coordPoint)
{
	//On calcule le vecteur directeur
	valarray<float> vectDirecteur = Rayon::calculVecteur(coordPoint,light.getPosition());
	boost::optional<Coord3*> inters = new Coord3();
	double epsilon = 0.05;

	for(Sphere sphere : tabSphere) //On teste pour chaque objet s ils bloquent la lumiere
	{
		inters = Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),light.getPosition());
		if(inters != boost::none)
		{
			double distance1 = sqrt(pow(inters.get()[0].getX() - coordPoint.getX(), 2)
					+ pow(inters.get()[0].getY() - coordPoint.getY(), 2)
					+ pow(inters.get()[0].getZ() - coordPoint.getZ(), 2));
			if(distance1 > epsilon)
			{
				return false;
			}
			if(sizeof(inters.get()) / sizeof(Coord3*) > 1) //On doit prendre le plus proche
			{
				double distance2 = sqrt(pow(inters.get()[1].getX() - coordPoint.getX(), 2)
								+ pow(inters.get()[1].getY() - coordPoint.getY(), 2)
								+ pow(inters.get()[1].getZ() - coordPoint.getZ(), 2));
				if(distance2 > epsilon)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Scene::lecture(){
	std::ifstream infile("aParser.txt");

	std::string line;
	int dataRead = 0; // nombre de données lues
	string aP,bP,cP,dP,eP,fP,gP,hP,infos;
	float aF,bF,cF,dF,eF,fF,gF,hF;
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
	    			cout << aP << " " << bP << " " << cP << endl; // on affiche ce qu'on obtient (pour la phase de test)

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
	    			cout << aP << " " << bP << " " << cP << endl;

						aF = (float)std::stoi(aP,&sz);
						bF = (float)std::stoi(bP,&sz);
						cF = (float)std::stoi(cP,&sz);
						tl.setX(aF); tl.setY(bF); tl.setZ(cF);

	    			break;
	    		case 3: //Top right corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;

						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						tr.setX(aF); tr.setY(bF); tr.setZ(cF);
	    			break;
	    		case 4 : // Bottom left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						bl.setX(aF); bl.setY(bF); bl.setZ(cF);
	    			break;
	    		case 5 : // screen horizontal resolution (on lit 1 donnee sur cette ligne)
	    			cout << aP << endl;
						horres = std::stoi(aP,&sz);
						this->screen.setHorResolution(horres);
	    			break;
	    		case 6 : // background color (on lit 2 autres donnees sur cette ligne
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    				colorBG.red = std::stoi(aP,&sz);
	    				colorBG.green = std::stoi(bP,&sz);
	    				colorBG.blue = std::stoi(cP,&sz);
						this->screen.setColor(colorBG);
	    			break;
	    		case 7 : // Light source position (x,y,z) and color(rgb): on lit 5 autres donnees
	    			iss >> bP >> cP >> dP >> eP >> fP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			dP.erase (std::remove(dP.begin(), dP.end(),','), dP.end());
	    			eP.erase (std::remove(eP.begin(), eP.end(),','), eP.end());
	    			fP.erase (std::remove(fP.begin(), fP.end(),','), fP.end());
	    			cout << aP << " " << bP << " " << cP << " " << dP << " " << eP << " " << fP <<endl;

						/*partie cast(string to float, puis float to int pour le RGB) */

						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						colorLight.red = std::stoi(dP,&sz);
						colorLight.green = std::stoi(eP,&sz);
						colorLight.blue = std::stoi(fP,&sz);
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
	    			cout << infos << " " << bP << " " << cP << " " << dP << " " << eP << " " << fP << " " << gP << " " << hP <<endl;

						aF = std::stof(infos,&sz);//coordx
						bF = std::stof(bP,&sz);//coordy
						cF = std::stof(cP,&sz);//coordz
						dF = std::stof(dP,&sz);//radius
						colorSphere.red = std::stoi(eP,&sz);//red
						colorSphere.green = std::stoi(fP,&sz);//green
						colorSphere.blue = std::stoi(eP,&sz);//blue
						hF = std::stof(fP,&sz);//reflex

						coordSphere.setX(aF); coordSphere.setY(bF); coordSphere.setZ(cF);
						Sphere sphere1 = Sphere(dF,coordSphere,hF,colorSphere);
						this->tabSphere.push_back(sphere1);
						std::cout<<this->getTabSphere().size()<<std::endl;
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
void Scene::imageSansReflexion()//Calcul de l image sans reflexion
{
	vector<vector<Pixel>> tabPixels = screen.getTabPixels();
	boost::optional<Coord3*> inters = new Coord3(); //Tous nos points intersections
	valarray<float> vectDirecteur;
	Sphere objet;
	Coord3 pointInters; //Point le plus proche
	Coord3 point1, point2;
	float distInters = 0; //distance du point le plus proche
	float distance1,distance2;
	cout << "Point A" << endl;
	for (unsigned int i(0); i < screen.getVerResolution(); ++i)
		{
			for(unsigned int j(0); j < screen.getHorResolution(); ++j)
			{
				for(Sphere sphere : tabSphere)//On va chercher intersection la plus proche
				{
					vectDirecteur = Rayon::calculVecteur(camera,tabPixels[i][j].getCoord3());
					inters = Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius(),camera);
					if(inters != boost::none)//On a au moins un point d intersections
					{
						if(distInters == 0)//Pas d intersection, on le met direct
						{
							point1 = inters.get()[0];
							distance1 = Rayon::calculDistance(camera,point1);
							distInters = distance1;
							pointInters = point1;
							//objet = sphere;
						}
						if(sizeof(inters.get()) / sizeof(Coord3*) > 1) //On doit prendre le plus proche
						{
							point1 = inters.get()[0];
							point2 = inters.get()[2];
							distance1 = Rayon::calculDistance(camera,point1);
							distance2 = Rayon::calculDistance(camera,point2);
							if(distance1 < distInters)
							{
								distInters = distance1;
								pointInters = point1;
								//objet = sphere;
							}
							if(distance2 < distInters)
							{
								distInters = distance2;
								pointInters = point2;
								//objet = sphere;
							}
						}
						else // 1 seul point, pas de choix possible
						{
							point1 = inters.get()[0];
							distance1 = Rayon::calculDistance(camera,point1);
							if(distance1 < distInters)
							{
								distInters = distance1;
								pointInters = point1;
								//objet = sphere;
							}
						}
					}
				}
				if(distInters != 0)//On a eu au moins une intersection
				{
					if(Scene::eclaireParSource(pointInters))
					{
						vectDirecteur = Rayon::calculVecteur(camera,pointInters);
						float cos = Rayon::calculCos(vectDirecteur,objet,pointInters);
						tabPixels[i][j].setColor(Rayon::calculCouleur(cos,objet.getColor(),light.getColor()));
					}
					else //Pas dans la lumiere, on laisse couleur du fond
						tabPixels[i][j].setColor(screen.getColor());
				}
				distInters = 0;
			}
		}
	screen.setTabPixels(tabPixels);
}
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
			outfile<<tabPixels[j][k].getColor().red<<" "<< tabPixels[j][k].getColor().green<<" "<<tabPixels[j][k].getColor().blue<<"\t";
		}
		outfile<<"\n";
	}
	outfile.close();
}
