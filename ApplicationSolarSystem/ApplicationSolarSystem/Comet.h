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

class Comet
{
private:
	double radius;
	double tail;
	double tail_angle;
	double sun_distance;

public:
	Comet();

	void draw();
	void move_comet();
	void start_rotation();
};

