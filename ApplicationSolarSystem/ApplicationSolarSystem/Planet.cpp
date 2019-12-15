#include "Planet.h"



Planet::Planet(double _radius, const char image[200], double _orbit_radius, double _speed, double _rotational_speed, cgvColor _select)
{
	//set parameters
	this->radius = _radius;
	this->orbit_radius = _orbit_radius;
	this->orbital_speed = _speed;
	this->rotation_speed = _rotational_speed;
	this->select = _select;
	strcpy(this->image_path, image);
//	this->image_path = image;
	this->textureID = -1;
	//moons and rings later
	rotate_angle = 0;
	orbit_angle = 0;
	
}

void Planet::draw()
{
	//draw it in the center of the wcs
	glPushMatrix();

	//move the planet according to its orbit
	float x = orbit_radius * sin( M_PI* 2 * this->orbit_angle / 360) /scaleRadius;
	float y = orbit_radius * cos(M_PI * 2 * this->orbit_angle / 360) / scaleRadius;
	glTranslatef(x, 0, y);
	printf("%f, %f\n", x, y);

	glRotatef(90-23.5, 1, 0, 0);
	glRotatef(this->rotate_angle, 0, 0, 1);
	
	GLUquadric* sphere;

	cgvTexture texture(this->image_path);

	sphere = gluNewQuadric();

	glColor3f(0.0, 1.0, 0.0);
	gluQuadricDrawStyle(sphere, GLU_FILL);

	cgvMaterial* material = new cgvMaterial(cgvColor(1, 1, 1),
		cgvColor(1, 1, 1),
		cgvColor(1, 1, 1), 50);
	material->apply();

	texture.apply();
	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	gluSphere(sphere, radius/scaleRadius, 32, 16);
	printf("%f\n", radius / scaleRadius);
	glPopMatrix();

	gluDeleteQuadric(sphere);
}



void Planet::move()
{
	//make it dance
	//it moves in a period of time


	this->rotate_angle +=360 * (double)scaleHours/rotation_speed;//rs - hours for the 

	this->orbit_angle+=360 * (double)scaleHours /(orbital_speed*24);//
	
}
