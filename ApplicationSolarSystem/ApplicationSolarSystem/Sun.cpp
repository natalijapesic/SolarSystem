
#include "Sun.h"

Sun::Sun(cgvColor color)
{
	char image[]= "..\\..\\textures\\sun.bmp";
	strcpy(this->image_path, image);
	char image1[]= "..\\..\\textures\\space.bmp";
	strcpy(this->image_space, image1);
	this->angle = (360 / (30 * 24))*scaleHours;
	this->color = color;
	this->radius = scaleSize(sun_radius) / scaleRadius;

	this->array_image = loadBMPRaw(image, weight, height, true);
	this->array_space=loadBMPRaw(image1, s_weight, s_height, true);
}

void Sun::draw()
{
	glPushMatrix();

	GLUquadric* sphere;
	cgvLight light(GL_LIGHT0, cgvPoint3D(0, 0, 0), cgvColor(240, 240, 240, 1), cgvColor(0, 0, 0, 1), cgvColor(0, 0, 0, 1), 1, 0, 0);
	light.switchOn();
	light.apply();
	cgvTexture texture(this->array_image, this->weight, this->height);

	glRotated(angle, 0, 1, 0);
	sphere = gluNewQuadric();

	glColor3f(0, 1, 1);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	texture.apply();

	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);


	gluSphere(sphere, this->radius, 320, 160);

	light.switchOff();
	light.apply();
	glPopMatrix();

	gluDeleteQuadric(sphere);
}

void Sun::draw_space()
{
	glPushMatrix();

	glCullFace(GL_FRONT);
	GLUquadric* sphere;
	cgvLight light(GL_LIGHT0, cgvPoint3D(0, 0, 0), cgvColor(240, 240, 240, 1), cgvColor(0, 0, 0, 1), cgvColor(0, 0, 0, 1), 1, 0, 0);
	light.switchOn();
	light.apply();
	cgvTexture texture(this->array_space, this->s_weight, this->s_height);

	glRotated(angle, 0, 1, 0);
	sphere = gluNewQuadric();

	glColor3f(0, 1, 1);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	texture.apply();

	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);


	gluSphere(sphere, space_radius()-10000, 320, 160);

	glCullFace(GL_BACK);
	light.switchOff();
	light.apply();

	glPopMatrix();

	gluDeleteQuadric(sphere);
}
