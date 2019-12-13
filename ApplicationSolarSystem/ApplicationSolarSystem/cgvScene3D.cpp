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
	  char image[] = "D:/VII semestar Jaen/Computer Graphics and visualization/project/SolarSystem/textures/2k_earth_daymap.bmp";
	  Planet Earth(2, image, 4, 5, 23, cgvColor(1, 0, 0));
	  Earth.draw();
	  //GLuint tex;
	  //GLUquadric* sphere;

	  //unsigned char* image;
	  //unsigned int width, height;

	  //// load the BMP image in memory
	  //image = loadBMPRaw("D:/VII semestar Jaen/Computer Graphics and visualization/project/SolarSystem/textures/2k_earth_daymap.bmp", width, height, true);

	  //glGenTextures(1, &tex);
	  //glBindTexture(GL_TEXTURE_2D, tex);
	  ////glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid*)data);
	  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	  //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	  //sphere = gluNewQuadric();
	  //glEnable(GL_TEXTURE_2D);

	  //glColor3f(0.0, 1.0, 0.0);
	  //gluQuadricDrawStyle(sphere, GLU_FILL);
	  //glBindTexture(GL_TEXTURE_2D, tex);
	  //gluQuadricTexture(sphere, TRUE);
	  //gluQuadricNormals(sphere, GLU_SMOOTH);
	  //gluSphere(sphere, 1.0, 32, 16);

	glPopMatrix (); 
}

