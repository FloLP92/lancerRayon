/*
 * Struct.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: vdoisne
 */


#include <iostream>
#include "Struct.h"

std::ostream& operator<<(std::ostream &out, const RGB &a) {//Affichage Coord3
	return out << "Red : " << a.red << " Blue : " << a.blue << " Green " << a.green << std::endl;
}


