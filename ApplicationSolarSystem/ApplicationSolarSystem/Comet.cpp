#include "Comet.h"

Comet::Comet()
{
	this->radius = comet_radius*100/ scaleRadius;

	comet_angle *= -1;
	this->tail_angle = comet_angle*45.0f;

	this->sun_distance = (middle_distance+ rand()%1000)/scaleRadius;

	this->sun_rotation = (360 / (30 * 24))*scaleHours;
}

void Comet::draw(float x, float y, float z)
{
	glPushMatrix();

	cgvLight light(GL_LIGHT1, cgvPoint3D(0, 0, 0), cgvColor(100, 100, 0), cgvColor(0, 0, 0), cgvColor(0, 0, 0), 1, 0, 0);
	light.switchOn();
	light.apply();

	cgvMaterial material(cgvColor(0, 0, 0), cgvColor(0, 0, 0), cgvColor(0, 0, 0), 1);
	material.apply();

	glRotated(sun_rotation, 0, 1, 0);
	glTranslatef(this->sun_distance + x, y, z);

	GLUquadric* sphere = gluNewQuadric();

	gluSphere(sphere, this->radius, 10, 10);

	glPopMatrix();

	gluDeleteQuadric(sphere);
}

void Comet::move_comet()
{
	if ((sun_distance > scaleSize(sun_radius+4000) / scaleRadius) && rotate_comet)
	{
		sun_distance -= comet_speed;
		sun_rotation += (360 / (30 * 24)) * scaleHours;
	}
	else {
		rotate_comet = false;
		sun_distance += comet_speed;
	}
	
}

