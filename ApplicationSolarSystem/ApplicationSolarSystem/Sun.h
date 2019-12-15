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

#include "Constants.h"
class Sun
{
private:

	float angle;
	cgvColor color;
	float radius;

	unsigned int textureID;
	char image_path[200];
	char image_space[200];


public:		
	
	Sun(cgvColor color);

	void draw();

	void draw_space();

	float get_angle() { return angle; }
	void inc_angle() { angle += (360 / (30 * 24)) * scaleHours; }

};
