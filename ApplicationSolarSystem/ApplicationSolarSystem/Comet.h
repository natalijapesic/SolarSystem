#pragma once
#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif
#include <random>
#include <iostream>
#include "Constants.h"
#include "cgvLight.h"
#include "cgvMaterial.h"

#define _USE_MATH_DEFINES
#include <math.h>
class Comet
{
private:
	double radius;
	double orbit_radius;
	double orbital_speed;
	double rotation_speed;
	double rotate_angle;
	double orbit_angle;

public:
	Comet(double _radius, double _orbit_radius, double _speed);

	void draw(double distance);

	void move();
};

