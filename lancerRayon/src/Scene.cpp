#include "Scene.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "Light.h"
#include "Rayon.h"

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
RGB Scene::getBackgroundColor(){
	return backgroundColor;
}
void Scene::setBackgroundColor(RGB c){
	backgroundColor = c;
}
vector<Sphere> Scene::getTabSphere(){
	return tabSphere;
}

//renvoit boolean indiquant si point eclaire par source lumineuse
bool Scene::eclaireParSource(Coord3 coordPoint)
{
	//On calcule le vecteur directeur
	valarray<float> vectDirecteur;
	vectDirecteur(coordPoint.x - light.getPosition().x);
	vectDirecteur(coordPoint.y - light.getPosition().y);
	vectDirecteur(coordPoint.z - light.getPosition().z);

	for(Sphere sphere : tabSphere) //On teste pour chaque objet s ils bloquent la lumiere
	{
		if(Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius()) != boost::none)
			return false;
	}
	return true;
}

//Calcul de l image sans reflexion
bool Scene::calculRayonSansRef(std::valarray<float> rayonIncident,Sphere s,Coord3 ptInter)
{

	boost::optional<Coord3*> intersections = new Coord3();
	for(unsigned int i(0); i < screen.getVerResolution(); i++)
	{
		for(unsigned int i(0); i < screen.getHorResolution(); i++)
		{
			for(Sphere sphere : tabSphere) //On teste pour chaque objet
			{
				//intersections = Rayon::calculPtIntersection(sphere.getCenter(), vectDirecteur, sphere.getRadius())
				if(sphere != boost::none)
				{

				}
			}
		}
	}
	return false;

}
void Scene::lecture(){
	std::ifstream infile("aParser.txt");

	std::string line;
	int dataRead = 0; // nombre de données lues
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);// tete de lecture
			Light l;
			this->setLight(l);
	   	string aP,bP,cP,dP,eP,fP,gP,hP,infos;
	   	float aF,bF,cF,dF,eF,fF,gF,hF;
			std::string::size_type sz; //Variable used to convert string into float (or int)
	   	//on commence par lire le premier mot : si il contient # au début c'est un comment donc on passe
	   	//sinon c'est une donnée utile : on sait quelle donnee utile c'est parce que on a un compteur qui permet
	   	// de savoir combien de donnees utiles on a lues. (donc ou on en est dans le fichier).
	   	// et on peut traiter en fonction de ce que c'est (utilisation switch).

			Screen s;
			this->setScreen(s);
			Coord3 tl;
			Coord3 tr;
			Coord3 bl;
			Coord3 br;

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
						this->camera.x = aF;
						this->camera.y = bF;
						this->camera.z = cF;

	    			break;
	    		case 2: //Top left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;

						aF = std::stoi(aP,&sz);
						bF = std::stoi(bP,&sz);
						cF = std::stoi(cP,&sz);
						tl.x = aF; tl.y = bF; tl.z = cF;
						this->getScreen().setTlCorner(tl);
	    			break;
	    		case 3: //Top right corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;

						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						tr.x = aF; tr.y = bF; tr.z = cF;
						this->getScreen().setTrCorner(tr);
	    			break;
	    		case 4 : // Bottom left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
						aF = std::stof(aP,&sz);
						bF = std::stof(bP,&sz);
						cF = std::stof(cP,&sz);
						bl.x = aF; bl.y = bF; bl.z = cF;
						this->getScreen().setBlCorner(bl);
	    			break;
	    		case 5 : // screen horizontal resolution (on lit 1 donnee sur cette ligne)
	    			cout << aP << endl;
						aF = std::stof(aP,&sz);
						this->getScreen().setHorResolution(aF);
	    			break;
	    		case 6 : // background color (on lit 2 autres donnees sur cette ligne
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
						aF = std::stoi(aP,&sz);
						bF = std::stoi(bP,&sz);
						cF = std::stoi(cP,&sz);
						RGB colorBG; colorBG.red = dF; colorBG.green = eF; colorBG.blue = fF;
						this->getScreen().setColor(colorBG);
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
						dF = std::stoi(dP,&sz);
						eF = std::stoi(eP,&sz);
						fF = std::stoi(fP,&sz);
						Coord3 coordLight; coordLight.x = aF; coordLight.y = bF; coordLight.z = cF;
						RGB colorLight; colorLight.red = dF; colorLight.green = eF; colorLight.blue = fF;
						l.setPosition(coordLight);
						l.setColor(colorLight);
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
						eF = std::stoi(eP,&sz);//red
						fF = std::stoi(fP,&sz);//green
						gF = std::stoi(eP,&sz);//blue
						hF = std::stof(fP,&sz);//reflex

						Coord3 coordSphere; coordSphere.x = aF; coordSphere.y = bF; coordSphere.z = cF;
						RGB colorSphere; colorSphere.red = eF; colorSphere.green = fF; colorSphere.blue = gF;
						Sphere sphere1 = Sphere(dF,coordSphere,hF,colorSphere);
						this->tabSphere.push_back(sphere1);
						std::cout<<this->getTabSphere().size()<<std::endl;
						break;
	    	}//end switch
	    }// end if comment
	}// end while read
	screen.calculBrCorner();
	screen.calculResVer();
	screen.creationPixels();

}

void Scene::write_image(){ //Creation du fichier ppm
	std::ofstream outfile;
	outfile.open("new.ppm");
	outfile<<"P6\n";
	outfile<<"4 4\n";
	outfile<<"15\n";
	outfile.close();
}
