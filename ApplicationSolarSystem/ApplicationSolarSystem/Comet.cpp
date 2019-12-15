#include "Comet.h"

Comet::Comet()
{
	this->radius = comet_radius / scaleRadius;
	this->tail = comet_tail / scaleRadius;
	this->tail_angle = 0;
	this->sun_distance = (min_sun_distance + rand()%1000)/scaleRadius;
}

void Comet::draw()
{
	glPushMatrix();

	glTranslatef(this->radius, 0, 0);
	glRotatef(-45, 1, 0, 0);
	glRotatef(-this->tail_angle, 0, 1, 0);
	//glTranslatef(this->sun_distance, this->sun_distance, 0);

	GLUquadric* cylinder;
	cylinder = gluNewQuadric();

	glColor3f(0, 0, 0);
	gluQuadricDrawStyle(cylinder, GLU_FILL);

	gluCylinder(cylinder, this->radius, this->radius, this->tail, 100, 100);

	glPopMatrix();

	gluDeleteQuadric(cylinder);
}

void Comet::move_comet()
{
	sun_distance -= comet_speed;
}

void Comet::start_rotation()
{
	if (sun_distance < middle_distance)
	{
		tail_angle -= scaleRadius;
	}
}
