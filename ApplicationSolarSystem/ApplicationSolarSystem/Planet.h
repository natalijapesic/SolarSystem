
#ifndef __PLANET
#define __PLANET

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif


#include "cgvLight.h"
#include "cgvTexture.h"
#include "cgvColor.h"

/*dimenzije, slicica, prstenje i meseci, boje za select, rotacija oko svoje ose
kretanje : putanja, brzina, udaljenost od sunca*/



class Planet {
private:
	float radius;
	unsigned int textureID;
	char* image_path;
	//rings data struct
	//moons data struct
		
	cgvColor select;
	float orbitA, orbitB;
	float speed;



public:
	Planet(float _radius, char* image, float _orbitA, float _orbitB, float _speed, cgvColor _select);
	void draw();
	void orbith();
	void move(bool direction);

};




#endif