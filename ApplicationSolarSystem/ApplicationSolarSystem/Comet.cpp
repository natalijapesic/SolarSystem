#include "Comet.h"

Comet::Comet(double _radius, double _orbit_radius, double _speed)
{
	this->radius = _radius;
	this->orbit_radius = _orbit_radius + scaleSize(sun_radius); //distance from the sun + sun radius = distance from the center of the sun
	this->orbital_speed = _speed;

	rotate_angle = 0;
	orbit_angle = 0;
}

void Comet::draw(double distance)
{
	GLUquadric* sphere;

	glTranslatef(0, 0, distance);
	double xx = orbit_radius * sin(M_PI * 2 * this->orbit_angle / 360) / scaleRadius;
	double yy = orbit_radius * cos(M_PI * 2 * this->orbit_angle / 360) / scaleRadius;
	glTranslatef(xx, 0, yy);

	glRotatef(this->rotate_angle, 0, 0, 1);
	sphere = gluNewQuadric();

	glColor3f(0.0, 1.0, 0.0);
	gluQuadricDrawStyle(sphere, GLU_FILL);

	cgvMaterial* material = new cgvMaterial(cgvColor(1, 1, 1), cgvColor(1, 1, 1), cgvColor(1, 1, 1), 50);
	material->apply();

	gluSphere(sphere, radius / scaleRadius, 32, 16);

	glPopMatrix();

	gluDeleteQuadric(sphere);
}

void Comet::move()
{
	this->orbit_angle += 360 * (double)scaleHours / (orbital_speed * 24);//
}

