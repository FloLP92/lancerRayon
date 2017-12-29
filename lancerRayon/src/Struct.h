/*
 * Struct.h
 *
 *  Created on: Nov 29, 2017
 *      Author: florian.le-pallec
 */

#ifndef STRUCT_H_
#define STRUCT_H_
#include <iostream>

struct image_t{
		int width,height,vmax;
		unsigned int* dataPixel;
};
struct RGB {
   int red;
   int green;
   int blue;
   friend std::ostream& operator<<(std::ostream &out, const RGB &a);
 };

class Struct {
public :

};


std::ostream& operator<<(std::ostream &out, const RGB &a);
#endif /* STRUCT_H_ */
