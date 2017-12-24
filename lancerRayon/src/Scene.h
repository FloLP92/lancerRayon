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
public:
	Scene(){}
	virtual ~Scene();
	Screen getScreen();
	void setScreen(Screen s);
	Light getLight();
	void setLight(Light l);
	void lecture();
	static void write_image();
};

#endif /* SCENE_H_ */
