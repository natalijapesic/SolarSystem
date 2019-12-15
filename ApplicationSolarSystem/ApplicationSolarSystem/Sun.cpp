
#include "Sun.h"

Sun::Sun(cgvColor color)
{
	char image[]= "..\\..\\textures\\sun.bmp";
	strcpy(this->image_path, image);
	this->angle = (360 / (30 * 24))*scaleHours;
	this->color = color;
	this->radius = scaleSize(sun_radius) / scaleRadius;
}

void Sun::draw()
{
	glPushMatrix();

	GLUquadric* sphere;
	cgvLight light(GL_LIGHT0, cgvPoint3D(0, 0, 0), cgvColor(240, 240, 240, 1), cgvColor(0, 0, 0, 1), cgvColor(0, 0, 0, 1), 1, 0, 0);
	light.switchOn();
	light.apply();
	cgvTexture texture(this->image_path);
	
	sphere = gluNewQuadric();

	glColor3f(0, 1, 1);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	texture.apply();

	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	gluSphere(sphere, this->radius, 32, 16);
	glPopMatrix();

	gluDeleteQuadric(sphere);
}
