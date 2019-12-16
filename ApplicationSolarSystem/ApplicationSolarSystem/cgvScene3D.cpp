#include <stdlib.h>
#include <stdio.h>

#include "cgvScene3D.h"
#include "cgvLight.h"
#include "cgvMaterial.h"
#include "cgvTexture.h"

// Constructor methods -----------------------------------




cgvScene3D::cgvScene3D () {
	axes = true;

	//Planet* p = new Mercury();
	
	GLubyte val_color[3] = { 1, 0, 0 };
	Mercury = new Planet(scaleSize(mercury_radius), "..\\..\\textures\\2k_mercury.bmp", scaleSize(mercury_orbit_radius), mercury_orbit_rotation, mercury_self_rotatin, val_color);
	Venus = new Planet(scaleSize(venus_radius), "..\\..\\textures\\2k_venus_surface.bmp", scaleSize(venus_orbit_radius), venus_orbit_rotation, venus_self_rotatin, val_color);
	Earth = new Planet(scaleSize(earth_radius),"..\\..\\textures\\2k_earth_daymap.bmp" /*image*/, scaleSize(earth_orbit_radius), earth_orbit_rotation, earth_self_rotatin, earth);
	Earth->addMoon(1000, 10000, 0.6);
	Mars = new Planet(scaleSize(mars_radius), "..\\..\\textures\\2k_mars.bmp", scaleSize(mars_orbit_radius), mars_orbit_rotation, mars_self_rotatin, val_color);
	Jupiter = new Planet(scaleSize(jupiter_radius), "..\\..\\textures\\2k_jupiter.bmp", scaleSize(jupiter_orbit_radius), jupiter_orbit_rotation, jupiter_self_rotatin, val_color);
	Jupiter->addMoon(1560, 67090, 4.3);
	Jupiter->addMoon(2634, 107000, 2);
	Jupiter->addMoon(1821, 42200, 8.6);
	Jupiter->addMoon(2410, 127000, 0.9);
	Saturn = new Planet(scaleSize(saturn_radius), "..\\..\\textures\\2k_saturn.bmp", scaleSize(saturn_orbit_radius), saturn_orbit_rotation, saturn_self_rotatin, val_color);
	Saturn->addRing(scaleSize(90000) / scaleRadius, scaleSize(117588) / scaleRadius);
	Uran = new Planet(scaleSize(uran_radius), "..\\..\\textures\\2k_uranus.bmp", scaleSize(uran_orbit_radius), uran_orbit_rotation, uran_self_rotatin, val_color);
	Neptun = new Planet(scaleSize(neptun_radius), "..\\..\\textures\\2k_neptune.bmp", scaleSize(neptun_orbit_radius), neptun_orbit_rotation, neptun_self_rotatin, val_color);
	
	instance_sun = new Sun(cgvColor(255.0, 128.0, 0.0));
}

cgvScene3D::~cgvScene3D() {

}


// Public methods ----------------------------------------

void
cgvScene3D::set(int scene) {
}


void cgvScene3D::draw_axes(void) {
  GLfloat red[]={1,0,0,1.0};
  GLfloat green[]={0,1,0,1.0};
  GLfloat blue[]={0,0,1,1.0};

	glBegin(GL_LINES);
    glMaterialfv(GL_FRONT,GL_EMISSION,red);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);

    glMaterialfv(GL_FRONT,GL_EMISSION,green);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);

    glMaterialfv(GL_FRONT,GL_EMISSION,blue);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();

	Earth->drawOrbit();
	Mercury->drawOrbit();
	Venus->drawOrbit();
	Mars->drawOrbit();
	Jupiter->drawOrbit();
	Saturn->drawOrbit();
	Uran->drawOrbit();
	Neptun->drawOrbit();

}


void cgvScene3D::render(renderMode mode) {
  
	marija();
}




void cgvScene3D::marija()
{
	glPushMatrix();

	int scena = 0;
	if (scena == 0)
	{
		cgvLight light(GL_LIGHT0, cgvPoint3D(0, 0, 0), cgvColor(0, 0, 0, 1), cgvColor(5, 5, 5, 1), cgvColor(6, 6, 6, 1), 1, 0, 0);
		light.switchOn();
		light.apply();


		if (axes) draw_axes();

		Mercury->draw();
		Venus->draw();
		Earth->draw();
		Mars->draw();
		Jupiter->draw();
		Saturn->draw();
		Uran->draw();
		Neptun->draw();

		instance_sun->draw_space();
		instance_sun->draw();



		cgvLight space_light(GL_LIGHT2, cgvPoint3D(0, 0, 0), cgvColor(100, 100, 100), cgvColor(100, 100, 100), cgvColor(100, 100, 100), 1, 0, 0);
		space_light.switchOn();
		space_light.apply();

		double border = scaleSize(4 * neptun_radius) / scaleRadius;// 4 neptun radius = 2 neptuns
		double shift = scaleSize(sun_radius) / scaleRadius - border;
		double width_image = border/*add to the left of the image*/
			+ 2 * scaleSize(neptun_radius) / scaleRadius/*do fit the last planet*/
			+ scaleSize(neptun_orbit_radius) / scaleRadius/*distance between npt and sun*/
			+ border/*right border where a part of the sun is visible*/;

		double furthest_point = width_image + shift;

		GLUquadric* sphere = gluNewQuadric();
		gluQuadricDrawStyle(sphere, GLU_FILL);

		cgvMaterial* material = new cgvMaterial(cgvColor(1, 1, 1),
			cgvColor(1, 1, 1),
			cgvColor(1, 1, 1), 50);
		material->apply();

		char image[] = "..\\..\\textures\\2k_stars.bmp";
		cgvTexture texture(instance_sun->get_space(), instance_sun->get_w(), instance_sun->get_h());
		texture.apply();

		gluQuadricTexture(sphere, TRUE);
		gluQuadricNormals(sphere, GLU_SMOOTH);
		gluSphere(sphere, sqrt(2)*furthest_point, 200, 200);


		space_light.switchOff();
		space_light.apply();

		light.switchOff();
		light.apply();
		gluDeleteQuadric(sphere);
	}
	else {
		if (axes) draw_axes();


		//int i;
		//int lineAmount = 100; //# of triangles used to draw circle

		////GLfloat radius = 0.8f; //radius
		//GLfloat twicePi = 2.0f * M_PI;
		//GLfloat color[] = { 0,1,0,1.0 };
		//glMaterialfv(GL_FRONT, GL_EMISSION, color);

		//glBegin(GL_LINE_LOOP);
		//for (i = 0; i <= lineAmount;i++) {
		//	glVertex3f(
		//		(2 * cos(i * twicePi / lineAmount)),
		//		(2 * sin(i * twicePi / lineAmount)),
		//		0
		//	);
		//}
		//glEnd();

		
	}
	glPopMatrix (); 
}
void cgvScene3D::natalija()
{
}


void cgvScene3D::rotateEarth()
{
	Mercury->move();
	Venus->move();
	Earth->move();
	Mars->move();
	Jupiter->move();
	Saturn->move();
	Uran->move();
	Neptun->move();
}

