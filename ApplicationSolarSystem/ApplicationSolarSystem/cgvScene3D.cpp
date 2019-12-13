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
  
	// create the model
	glPushMatrix(); // store the model matrices

	  // draw the axes
	  if (axes) draw_axes();
		// the lights are placed before the transformations, this way they remain static during interaction

	  // TODO: Section B: Define and apply the point light specified in the practice 

	  if (selectedScene == 1) { // blue quad

		//  draw_quad();  

	  }
	  else if (selectedScene == 2) { // red quad
		  /* TODO: Section D: define and apply the material properties as specified in the practice */

	  }
	  else if (selectedScene == 3) { // mesh of quads
	  /* TODO: Section E and F: */

	  }
	  else if (selectedScene == 4) {// Spotlight
		  // TODO: Section G: Define and apply a spotlight as specified in the practice instructions

		  // TODO: Switch off the new spotlight
	  }
	  else if (selectedScene == 5) { // world map
		  /* TODO: Section H: World map. Add the required code to cgvScene3D::render() to:
				o	Create and bind a texture from the file map.BMP.
				o	Render the triangle mesh of the scene. 
			*/

	  }


	  // Assign the OpenGL default material. 
	  cgvMaterial defaultMat(cgvColor(0.2, 0.2, 0.2, 1), cgvColor(0.8, 0.8, 0.8, 1), cgvColor(0.0, 0, 0, 1), 0);
	  defaultMat.apply();

	glPopMatrix (); // restore the modelview matrix 
  
}

