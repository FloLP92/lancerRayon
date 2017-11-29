/*
 * Parsing.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: Vincent DOISNEAU
 */

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>

using namespace std;

void lecture(){
	std::ifstream infile("aParser.txt");

	std::string line;
	int dataRead = 0; // nombre de données lues
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);
	    string a,infos;
	   	string aP,bP,cP,dP,eP,fP,gP,hP;
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
	    	}
	    }
	}
}


void write_image(){

}

