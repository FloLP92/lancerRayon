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
#include "Parsing.h"
#include "Test.h"
#include "Scene.h"
using namespace std;

int main() {
	Light light;
	Scene scene1;

	scene1.lecture();

	Scene::write_image();
	//Test::testParsing();
	cout << "taille tableau sphere " << scene1.getTabSphere().size()<< endl;
	std::vector<Coord3*> tabIntersection;
	boost::optional<Coord3*> calculPtIntersection(Coord3 ptSphere,std::valarray<float> vectDirecteur,float RayonSphere);
	return 0;
}

Coord3 equaRay(Coord3 chCamera, Coord3 chLight)
{
	Coord3 ray;
	return ray;
}

//take an image_t and write it on a ppm file
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
	fprintf(pgmFile, "P3\n%d %d\n%d\n",(*img).width,(*img).height,(*img).vmax);
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
