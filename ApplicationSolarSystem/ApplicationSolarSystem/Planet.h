
#ifndef __PLANET
#define __PLANET

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#endif


#include "cgvLight.h"
#include "cgvTexture.h"
#include "cgvColor.h"

/*dimenzije, slicica, prstenje i meseci, boje za select, rotacija oko svoje ose
kretanje : putanja, brzina, udaljenost od sunca*/



class Planet {
private:
	float radius;//the radios of a planet

	unsigned int textureID;
	char image_path[200];//NEPOTREBNO
	//rings data struct
	//moons data struct
		
	cgvColor select;
	float orbit_radius;

	float orbital_speed;
	float orbit_angle;

	float rotation_speed;
	float rotate_angle;



public:
	Planet(float _radius,const char image[200], float _orbit_radius, float _orbital_speed, float _rotational_speed, cgvColor _select);
	void draw();
	void orbith();
	void move(bool direction);

};




#endif