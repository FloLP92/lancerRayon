#ifndef SCENE_H_
#define SCENE_H_
#include <vector>
#include <iostream>
#include <boost/optional.hpp>
#include "Sphere.h"
#include "Light.h"
#include "Screen.h"

class Scene {
private:
	std::vector<Sphere> tabSphere; // tableau de spheres
	Light light;
	Coord3 camera;
	Screen screen;
	RGB backgroundColor;
public:
	Scene(){}
	virtual ~Scene();
	static void write_image();
	void lecture();

	/*getters & setters*/
	Screen getScreen();
	void setScreen(Screen s);
	Light getLight();
	void setLight(Light l);
	void setBackgroundColor(RGB c);
	RGB getBackgroundColor();
	std::vector<Sphere> getTabSphere();

};

#endif /* SCENE_H_ */
