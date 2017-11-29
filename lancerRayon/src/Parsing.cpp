/*
 * Parsing.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: vdoisne
 */

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void lecture(string nameFile){
	std::ifstream infile("aParser.txt");

	std::string line;
	int dataRead = 0; // nombre de données lues
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);
	    string a;
	    int aP,bP,cP,dP,eP,fP,gP,hP;
	    if (!(iss >> a)) { break; } // error
	    else if(a.compare("#")!=0){ // on lit une donnée
	    	dataRead++;
	    	aP = atoi(a.c_str());
	    	switch(dataRead){
	    		case 1: //Camera position
	    			iss >> bP >> cP;
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 2: //Top left corner
	    			iss >> bP >> cP;
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 3: //Top right corner
	    			iss >> bP >> cP;
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 4 : // Bottom left corner
	    			iss >> bP >> cP;
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 5 : // screen horizontal resolution
	    			cout << aP << endl;
	    			break;
	    		case 6 : // background color
	    			iss >> bP >> cP;
	    			cout << aP << " " << bP << " " << cP << endl;
	    			break;
	    		case 7 : // Light source position and color
	    			iss >> bP >> cP >> dP >> eP >> fP;
	    			cout << aP << " " << bP << " " << cP << " " << dP << " " << eP << " " << fP <<endl;
	    			break;
	    		default : //Create Circles (just them for the moment)
	    			iss >> bP >> cP >> dP >> eP >> fP >> gP >> hP;
	    			cout << aP << " " << bP << " " << cP << " " << dP << " " << eP << " " << fP << " " << gP << " " << hP <<endl;
	    			break;
	    	}
	    }
	}
}


