
#ifndef __PLANET
#define __PLANET

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>
#include <string.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#endif


#include "cgvLight.h"
#include "cgvTexture.h"
#include "cgvColor.h"
#include "cgvMaterial.h"
#include "Constants.h"
/*dimenzije, slicica, prstenje i meseci, boje za select, rotacija oko svoje ose
kretanje : putanja, brzina, udaljenost od sunca*/

struct Moon {
	double radius;
	double distance;
	double speed;
	double current_angle;
};



class Planet {
protected:
	

	unsigned int textureID;
	char image_path[200];//NEPOTREBNO
	//rings data struct
	//moons data struct

	GLubyte select[3];

	double radius;//the radius of a planet
	double rotation_speed; //hours to rotate around itself
	double rotate_angle;//the current angle of rotation of the planet

	double orbit_radius;//distance of the sun
	double orbital_speed;//days to orbit around the Sun
	double orbit_angle;//the current position of the planet
	
	int moon_count;
	Moon moons[4];
	double ring_inner, ring_outer;

public:
	Planet(double _radius,const char image[200], double _orbit_radius, double _orbital_speed, double _rotational_speed, GLubyte _select[3]);
	void draw();
	void drawMoon(int count);
	void drawRing();
	void drawOrbit();
	//virtual void drawTexture() = 0;

	void move();
	void addMoon(double radius, double distance, double speed);
	void addRing(double inner_ring, double outer_ring);
	void set_color(GLubyte color[3]);

};

//
//class Mercury :Planet {
//public:
//	void drawTexture();
//};
//class Venus :Planet {
//public:
//	void drawTexture();
//};
//class Earth :Planet {
//public:
//	void drawTexture();
//};
//class Mars :Planet {
//public:
//	void drawTexture();
//};
//class Jupiter :Planet {
//public:
//	void drawTexture();
//};
//class Saturn :Planet {
//public:
//	void drawTexture();
//};
//class Uran :Planet {
//public:
//	void drawTexture();
//};
//class Neptun :Planet {
//public:
//	void drawTexture();
//};
#endif