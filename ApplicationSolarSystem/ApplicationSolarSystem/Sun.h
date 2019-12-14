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
class Sun
{
	float radius; //Radius: 695,500 km
	float rotation_speed;
	float rotate_angle;
};
