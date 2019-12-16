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
	comets_rain[0] = new Comet(100.0, scaleSize(comet_orbit_radius + rand() % 100000), comet_orbit_rotation);
	comets_rain[1] = new Comet(100.0, scaleSize(comet_orbit_radius + rand() % 100000), comet_orbit_rotation);
	comets_rain[2] = new Comet(100.0, scaleSize(comet_orbit_radius + rand() % 100000), comet_orbit_rotation);
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
  
	glPushMatrix();


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

		instance_sun->draw();

		comets_rain[0]->draw(-scaleSize(comet_orbit_radius+1000));
		comets_rain[1]->draw(scaleSize(jupiter_orbit_radius));
		comets_rain[2]->draw(scaleSize(-mars_orbit_radius+45236));


		light.switchOff();
		light.apply();


	glPopMatrix();
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
	for (int i = 0; i < 3; i++)
		comets_rain[i]->move();
}

