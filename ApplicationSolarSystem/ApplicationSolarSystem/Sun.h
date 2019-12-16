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

	unsigned char* array_image;
	unsigned char* array_space;
	unsigned int height, weight, s_height, s_weight;;
public:

	Sun(cgvColor color);

	void draw();

	void draw_space();

	float get_angle() { return angle; }
	void inc_angle() { angle += (360 / (30 * 24)) * scaleHours; }

	unsigned char* get_space() { return array_space; }
	unsigned int get_h() { return this->s_height; }
	unsigned int get_w() { return this->s_weight; }

};
