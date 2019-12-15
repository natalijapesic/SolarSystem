#include <stdlib.h>
#include <stdio.h>

#include "cgvScene3D.h"
#include "cgvLight.h"
#include "cgvMaterial.h"
#include "cgvTexture.h"

// Constructor methods -----------------------------------


//Comet* c = new Comet();
//c->draw();
//
///* for (int i = 0; i < 10; i++)
//	 comets_rain[i]->draw();*/
//	 //

cgvScene3D::cgvScene3D () {
	axes = true;

	Scene[0] = 1;
	Scene[1] = 2;
	Scene[2] = 3;
	Scene[3] = 4;
	Scene[4] = 5;

	Scene_Name[0] = (char*)"blue quad";
	Scene_Name[1] = (char*)"red quad";
	Scene_Name[2] = (char*)"mesh of quads";
	Scene_Name[3] = (char*)"spotlight";
	Scene_Name[4] = (char*)"texture";


	selectedScene = 1;

	char image[] = "..\\..\\textures\\2k_earth_daymap.bmp";

	Mercury = new Planet(1*mercury_radius, "..\\..\\textures\\2k_mercury.bmp", mercury_orbit_radius/10, mercury_orbit_rotation, mercury_self_rotatin, cgvColor(1, 0, 0));
	Earth = new Planet(1*earth_radius,"..\\..\\textures\\2k_earth_daymap.bmp" /*image*/, earth_orbit_radius/10, earth_orbit_rotation, earth_self_rotatin, cgvColor(1, 0, 0));

	instance_sun = new Sun(cgvColor(255.0, 128.0, 0.0));
	for (int i = 0; i < 10; i++)
		comets_rain[i] = new Comet();
}

cgvScene3D::~cgvScene3D() {

}


// Public methods ----------------------------------------

void
cgvScene3D::set(int scene) {
	selectedScene = scene;
}


void draw_axes(void) {
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
}


void cgvScene3D::render(void) {
  
	glPushMatrix(); 

	int scena = 0;

	cgvLight light(GL_LIGHT0, cgvPoint3D(0, 0, 0), cgvColor(0.5, 0.5, 0.5, 1), cgvColor(5, 5, 5, 1), cgvColor(6, 6, 6, 1), 1, 0, 0);
	light.switchOn();
	light.apply();


	  if (axes) draw_axes();


	  Mercury->draw();
	  Earth->draw();


	  glPushMatrix();
	 
	  glRotated(instance_sun->get_angle(), 0, 1, 0);
	  instance_sun->draw();
	  
	  glPopMatrix();


	  //
	//delete material;

	glPopMatrix (); 
}

void cgvScene3D::natalija()
{
}

void cgvScene3D::marija()
{
}

void cgvScene3D::rotateEarth()
{
	Earth->move();
	Mercury->move();
}

