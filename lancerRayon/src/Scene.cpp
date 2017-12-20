#include "Scene.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "Light.h"

using namespace std;

Scene::Scene() {
	// TODO Auto-generated constructor stub
}
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

void lecture(){
	std::ifstream infile("aParser.txt");

	std::string line;
	int dataRead = 0; // nombre de données lues
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);
	    string a,infos;
	    Light l();
	   	string aP,bP,cP,dP,eP,fP,gP,hP;
	   	float aF,bF,cF,dF,eF,fF,gF,hF;
	    if (!(iss >> a)) { break; } // error
	    else if(a.compare("#")!=0){ // on lit une donnée
	    	dataRead++; // On incremente le nombre de données utiles lues
	    	aP = a; // on place la donnee dans notre liste des donnees lues
	    	aP.erase (std::remove(aP.begin(), aP.end(),','), aP.end()); //on supprimes les , de la ligne
	    	switch(dataRead){
	    		case 1: //Camera position (on lit 2 autres données sur cette ligne)
	    			iss >> bP >> cP; // on place le reste de la lecture dans des variables
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());//on supprimes les , de la ligne
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());//on supprimes les , de la ligne
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 2: //Top left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 3: //Top right corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 4 : // Bottom left corner (on lit 2 autres donnees sur cette ligne)
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 5 : // screen horizontal resolution (on lit 1 autre donnee sur cette ligne)
	    			cout << aP << endl;
	    			break;
	    		case 6 : // background color (on lit 2 autres donnees sur cette ligne
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 7 : // Light source position and color on lit 5 autres donnees
	    			iss >> bP >> cP >> dP >> eP >> fP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			dP.erase (std::remove(dP.begin(), dP.end(),','), dP.end());
	    			eP.erase (std::remove(eP.begin(), eP.end(),','), eP.end());
	    			fP.erase (std::remove(fP.begin(), fP.end(),','), fP.end());
	    			aF = strtof(aP.c_str(),0);
	    			bF = strtof(bP.c_str(),0);
	    			cF = strtof(cP.c_str(),0);
	    			dF = strtof(dP.c_str(),0);
	    			eF = strtof(eP.c_str(),0);
	    			fF = strtof(fP.c_str(),0);
	    			cout << aP << " " << bP << " " << cP << " " << dP << " " << eP << " " << fP <<endl;
	    			break;
	    		default : //reste des infos utiles cad la liste des cercles en bas du fichier
	    			iss >> infos >> bP >> cP >> dP >> eP >> fP >> gP >> hP; //8 donnees utiles
	    			infos.erase (std::remove(infos.begin(), infos.end(),','), infos.end());
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			dP.erase (std::remove(dP.begin(), dP.end(),','), dP.end());
	    			eP.erase (std::remove(eP.begin(), eP.end(),','), eP.end());
	    			fP.erase (std::remove(fP.begin(), fP.end(),','), fP.end());
	    			gP.erase (std::remove(gP.begin(), gP.end(),','), gP.end());// remove commas
	    			hP.erase (std::remove(hP.begin(), hP.end(),','), hP.end());
	    			cout << infos << " " << bP << " " << cP << " " << dP << " " << eP << " " << fP << " " << gP << " " << hP <<endl;
	    			break;
	    	}//end switch
	    }// end if comment
	}// end while read

}

void write_image(){ //Creation du fichier ppm
	std::ofstream outfile;
	outfile.open("new.ppm");
	outfile<<"P6\n";
	outfile<<"4 4\n";
	outfile<<"15\n";
	outfile.close();
}

