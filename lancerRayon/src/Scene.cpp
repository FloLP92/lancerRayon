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
	    	dataRead++;
	    	//aP = atoi(a.c_str());
	    	aP = a;
	    	aP.erase (std::remove(aP.begin(), aP.end(),','), aP.end());
	    	switch(dataRead){
	    		case 1: //Camera position
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 2: //Top left corner
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 3: //Top right corner
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 4 : // Bottom left corner
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 5 : // screen horizontal resolution
	    			cout << aP << endl;
	    			break;
	    		case 6 : // background color
	    			iss >> bP >> cP;
	    			bP.erase (std::remove(bP.begin(), bP.end(),','), bP.end());// remove commas
	    			cP.erase (std::remove(cP.begin(), cP.end(),','), cP.end());
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 7 : // Light source position and color
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
	    		default : //Create Circles (just them for the moment)
	    			iss >> infos >> bP >> cP >> dP >> eP >> fP >> gP >> hP;
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

