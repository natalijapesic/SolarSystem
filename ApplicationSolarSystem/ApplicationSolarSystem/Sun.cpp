
#include "Sun.h"

Sun::Sun(cgvColor color)
{
	char image[]= "..\\..\\textures\\sun.bmp";
	strcpy(this->image_path, image);
	this->angle = (360 / (30 * 24))*scaleHours;
	this->color = color;
	this->radius = initialRadius / scaleRadius;
}

void Sun::draw()
{
	glPushMatrix();

	GLUquadric* sphere;
	cgvLight light(GL_LIGHT0, cgvPoint3D(0, 0, 0), cgvColor(240, 240, 240, 1), cgvColor(0, 0, 0, 1), cgvColor(0, 0, 0, 1), 1, 0, 0);
	light.switchOn();
	light.apply();
	//unsigned char* image;
	//unsigned int width, height;
	//// load the BMP image in memory
	//image = loadBMPRaw(this->image_path, width, height, true);

	//glGenTextures(1, &textureID);
	//glBindTexture(GL_TEXTURE_2D, textureID);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	cgvTexture texture(this->image_path);
	
	sphere = gluNewQuadric();
	//glEnable(GL_TEXTURE_2D);

	glColor3f(0, 1, 1);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	texture.apply();
	//glBindTexture(GL_TEXTURE_2D, textureID);
	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	gluSphere(sphere, this->radius/10, 32, 16);

	glPopMatrix();

	gluDeleteQuadric(sphere);
}
