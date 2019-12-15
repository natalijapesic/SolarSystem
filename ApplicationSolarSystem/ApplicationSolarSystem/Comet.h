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
	void print(){
		printf("sun d %f", sun_distance);
		printf("angle %d", comet_angle);
		printf(" speed %f", comet_speed);
	}
};

