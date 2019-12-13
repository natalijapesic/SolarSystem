#include "Planet.h"



Planet::Planet(float _radius, char* image, float _orbitA, float _orbitB, float _speed, cgvColor _select)
{
	//set parameters
	this->radius = _radius;
	this->orbitA = _orbitA;
	this->orbitB = _orbitB;
	this->speed = _speed;
	this->select = _select;
	this->image_path = image;
	this->textureID = -1;
	//moons and rings later
	

}

void Planet::draw()
{
	//draw it in the center of the wcs
	glPushMatrix();

	
	GLUquadric* sphere;

	unsigned char* image;
	unsigned int width, height;

	// load the BMP image in memory
	image = loadBMPRaw(this->image_path, width, height, true);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid*)data);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	sphere = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);

	glColor3f(0.0, 1.0, 0.0);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, textureID);
	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	gluSphere(sphere, 1.0, 32, 16);

	glPopMatrix();

	gluDeleteQuadric(sphere);
	//glutSolidSphere(1, 50, 50);
}

void Planet::orbith()
{
	//define the orbit
}

void Planet::move(bool direction)
{
	//make it dance
}
