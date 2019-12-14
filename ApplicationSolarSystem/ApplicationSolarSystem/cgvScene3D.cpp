#include <stdlib.h>
#include <stdio.h>

#include "cgvScene3D.h"
#include "cgvLight.h"
#include "cgvMaterial.h"
#include "cgvTexture.h"

// Constructor methods -----------------------------------

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

	Mercury = new Planet(0.3, "..\\..\\textures\\2k_mercury.bmp", 1, 14, 3, cgvColor(1, 0, 0));
	Earth = new Planet(0.6,"..\\..\\textures\\2k_earth_daymap.bmp" /*image*/, 4, 23, 15, cgvColor(1, 0, 0));

	instace_sun = new Sun(cgvColor(255.0, 128.0, 0.0));

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

void draw_quad() {

	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 5.0);
		glVertex3f(5.0, 0.0, 5.0);
		glVertex3f(5.0, 0.0, 0.0);
	glEnd();


}


void cgvScene3D::render(void) {
  
	glPushMatrix(); 

	  if (axes) draw_axes();

	  Earth->draw();
	  Mercury->draw();


	  glPushMatrix();
	 
	  glRotated(instace_sun->get_angle(), 0, 1, 0);
	  instace_sun->draw();
	  
	  glPopMatrix();


	  


	glPopMatrix (); 
}

void cgvScene3D::rotateEarth()
{
	Earth->move(true);
	Mercury->move(true);
}

