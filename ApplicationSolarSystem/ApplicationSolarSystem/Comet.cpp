#include "Comet.h"

Comet::Comet()
{
	this->radius = comet_radius / scaleRadius;
	this->tail = comet_tail / scaleRadius;

	comet_angle *= -1;
	this->tail_angle = comet_angle * rand() % 180;

	this->sun_distance = (min_sun_distance + rand()%1000)/scaleRadius;
}

void Comet::draw()
{
	glPushMatrix();

	GLUquadric* sphere = gluNewQuadric();


	cgvLight light(GL_LIGHT1, cgvPoint3D(0, 0, 0), cgvColor(100, 100, 0), cgvColor(0, 0, 0), cgvColor(0, 0, 0), 1, 0, 0);
	light.switchOn();
	light.apply();

	cgvMaterial material(cgvColor(0, 0, 0), cgvColor(0, 0, 0), cgvColor(0, 0, 0), 1);
	material.apply();

	glRotatef(this->tail_angle, 0, 0, 1);
	//glTranslatef(this->sun_distance, 0, 0);
	glScalef(this->tail, 1, 1);

	gluSphere(sphere, this->radius, 10, 10);

	glPopMatrix();

	gluDeleteQuadric(sphere);
}

void Comet::move_comet()
{
	sun_distance -= comet_speed;
}

void Comet::start_rotation()
{
	if (sun_distance < middle_distance/scaleRadius)
	{
		tail_angle--;
	}
}
