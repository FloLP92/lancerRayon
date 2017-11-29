//============================================================================
// Name        : lancerRayon.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

//take an image_t and write it on a pgm file
void write_image(image_t* img,char* nameFile)
{
	FILE* pgmFile = NULL;
	pgmFile = fopen(nameFile,"w");
	int i,j;
	if (pgmFile == NULL)
	{
        perror("Error, cannot open file to write");
        exit(EXIT_FAILURE);
    }
	//
	fprintf(pgmFile, "P2\n%d %d\n%d\n",(*img).width,(*img).height,(*img).vmax);
	for (i=0; i<(*img).height; ++i)
	{
		for (j=0;j<(*img).width; ++j)
		{
			fprintf(pgmFile,"%d ",(*img).dataPixel[i*((*img).width)+j]);
		}
		fseek(pgmFile,-1,SEEK_CUR);
		fprintf(pgmFile,"\n");
	}

	fclose(pgmFile);
	printf("Image has been written in %s\n",nameFile);
}


