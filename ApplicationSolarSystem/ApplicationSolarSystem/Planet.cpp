#include "Planet.h"



Planet::Planet(double _radius, const char image[200], double _orbit_radius, double _speed, double _rotational_speed, GLubyte _select[3])
{
	//set parameters
	this->radius = _radius;
	this->orbit_radius = _orbit_radius + scaleSize(sun_radius); //distance from the sun + sun radius = distance from the center of the sun
	this->orbital_speed = _speed;
	this->rotation_speed = _rotational_speed;
	for (int i = 0; i < 3; i++)
		this->select[i] = _select[i];
	strcpy(this->image_path, image);
//	this->image_path = image;
	this->textureID = -1;
	//moons and rings later
	rotate_angle = 0;
	orbit_angle = 0;
	moon_count = 0;

	ring_inner = -1;
	ring_outer = -1;

	this->array_image = loadBMPRaw(this->image_path, this->weight, this->height, true);

}

void Planet::draw()
{
	
	//draw it in the center of the wcs
	glPushMatrix();

	GLUquadric* sphere;
	//move the planet according to its orbit
	float x = orbit_radius * sin( M_PI* 2 * this->orbit_angle / 360) /scaleRadius;
	float y = orbit_radius * cos(M_PI * 2 * this->orbit_angle / 360) / scaleRadius;


	glTranslatef(x, 0, y);

	glRotatef(90-23.5, 1, 0, 0);

	glPushMatrix();
	glRotatef(this->rotate_angle, 0, 0, 1);

	cgvTexture texture(this->array_image, this->weight, this->height);
	texture.apply();

	sphere = gluNewQuadric();

	if (glIsEnabled(GL_LIGHTING) && glIsEnabled(GL_TEXTURE_2D))
	{
		glColor3f(0.0, 1.0, 0.0);
		gluQuadricDrawStyle(sphere, GLU_FILL);

		cgvMaterial* material = new cgvMaterial(cgvColor(1, 1, 1),
			cgvColor(1, 1, 1),
			cgvColor(1, 1, 1), 50);
		material->apply();
		int j = 0;
		
		gluQuadricTexture(sphere, TRUE);
	}
	else {
		glColor3ub(select[0], select[1], select[2]);
		gluQuadricDrawStyle(sphere, GLU_FILL);
	}

	gluSphere(sphere, radius / scaleRadius, 32, 16);
	
	glPopMatrix();

	for (int i = 0;i < moon_count;i++)
	{
		drawMoon(i);
	}
	drawRing();

	glPopMatrix();
	gluDeleteQuadric(sphere);
}

void Planet::drawMoon(int count)
{
	//crtaj mesec
	glPushMatrix();

	glRotated(moons[count].current_angle/* - this->rotate_angle*/, 0, 0, 1);
	glTranslated(0, moons[count].distance + scaleSize(radius) / scaleRadius, 0);

	cgvMaterial* material = new cgvMaterial(cgvColor(50, 50, 50),
		cgvColor(10, 10, 10),
		cgvColor(20, 20, 20), 50);
	material->apply();

	glutSolidSphere(moons[count].radius, 50, 50);
	glPopMatrix();
}

void Planet::drawRing()
{
	if (this->ring_inner <= 0) return;



	glPushMatrix();

	glRotatef(10, 0, 1, 0);

	GLUquadric* ring = gluNewQuadric();

	cgvLight light(GL_LIGHT3, cgvPoint3D(0, 0, 0), cgvColor(1, 1, 1, 0.5), cgvColor(1, 1, 1, 0.5), cgvColor(1, 1, 1, 0.5), 1, 0, 0);
	light.switchOn();
	light.apply();

	glColor3f(0.0, 1.0, 0.0);
	//cgvColor(100, 100, 100, 1).apply();

	gluQuadricDrawStyle(ring, GLU_FILL);
	//light
	

	cgvMaterial* material = new cgvMaterial(cgvColor(1, 1, 1, 0.5),
		cgvColor(1, 1, 1, 0.5),
		cgvColor(1, 1, 1, 0.5), 5);
	material->apply();

	char image[] = "..\\..\\textures\\saturnmap.bmp";
	//cgvTexture texture(image);
	//texture.apply();

	gluQuadricTexture(ring, TRUE);
	gluQuadricNormals(ring, GLU_SMOOTH);
	gluDisk(ring, this->ring_inner, this->ring_outer, 100, 100);

	light.switchOff();
	light.apply();
	glPopMatrix();
}

void Planet::drawOrbit()
{
	//glPushMatrix();
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	GLfloat color[] = { 1,0,0,1.0 };
	//glMaterialfv(GL_FRONT, GL_EMISSION, color);

	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount;i++) {
		glVertex3f(
			(orbit_radius / scaleRadius * cos(i * twicePi / lineAmount)),
			0,
			(orbit_radius / scaleRadius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
}



void Planet::move()
{
	this->rotate_angle +=360 * (double)scaleHours/rotation_speed;//rs - hours for the 

	this->orbit_angle+=360 * (double)scaleHours /(orbital_speed*24);//
	
	for (int i = 0;i < moon_count;i++)
		moons[i].current_angle += moons[i].speed * scaleHours;
}

void Planet::addMoon(double radius, double distance, double speed)
{
	if (moon_count > 3) return;
	moons[moon_count].radius = scaleSize(radius)/scaleRadius;
	moons[moon_count].distance = scaleSize(distance) / scaleRadius;
	moons[moon_count].speed = speed;
	moons[moon_count].current_angle = rand() % 360;
	moon_count++;
}

void Planet::addRing(double inner_ring, double outer_ring)
{
	this->ring_inner = inner_ring;
	this->ring_outer = outer_ring;
}

void Planet::set_color(GLubyte _color[3])
{
	this->select[0] = _color[0];
	this->select[1] = _color[1];
	this->select[2] = _color[2];
}

