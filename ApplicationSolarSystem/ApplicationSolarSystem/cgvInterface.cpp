#include <stdio.h>
#include <stdlib.h>

#include "cgvInterface.h"

extern cgvInterface interface; // the callbacks must be static and this object is required to access to the variables of the class                   // ellos a las variables de la clase

// Constructor and destructor methods -----------------------------------

cgvInterface::cgvInterface () {}

cgvInterface::~cgvInterface () {}


// Public methods ----------------------------------------
void cgvInterface::create_world(void) {
	// create the camera
	interface.camera.set(CGV_PARALLEL, cgvPoint3D(300,0,50),cgvPoint3D(0,0,50),cgvPoint3D(0,1.0,0),
		                                -1*50, 1*50, -1*25, 1*25, -1*0, 600);
}

void cgvInterface::configure_environment(int argc, char** argv, 
			                       int _width_window, int _height_window, 
			                       int _pos_X, int _pos_Y, 
													 string _title)
													 {
	// initialization of the interface variables																	
	width_window = _width_window;
	height_window = _height_window;

	// initialization of the display window
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_width_window,_height_window);
  glutInitWindowPosition(_pos_X,_pos_Y);
	glutCreateWindow(_title.c_str());

	create_menu();

	glEnable(GL_DEPTH_TEST); // enable the removal of hidden surfaces by using the z-buffer
  glClearColor(1.0,1.0,1.0,0.0); // define the background color of the window

	glEnable(GL_LIGHTING); // enable the lighting of the scene
  glEnable(GL_NORMALIZE); // normalize the normal vectors required by the lighting computation. 
	glEnable(GL_TEXTURE_2D); // enable the use of 2D textures


  create_world(); // create the world (scene) to be rendered in the window
}

void cgvInterface::create_menu() {
	int menu_id = glutCreateMenu(menuHandle);
	for (int i = 0; i<nbScenes; ++i) {
		glutAddMenuEntry(interface.scene.Scene_Name[i], interface.scene.Scene[i]);
	}

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void cgvInterface::init_rendering_loop() {
	glutMainLoop(); // initialize the visualization loop of OpenGL
}

void cgvInterface::set_glutKeyboardFunc(unsigned char key, int x, int y) {
 switch (key) {
	 case 'd': // Section F: increase by 0.1 the R component of the diffuse coefficient of the material. 
		 break;
	 case 'D': // Section F: decrease by 0.1 the R component of the diffuse coefficient of the material. 
		 break;
	 case 's': // Section F: increase by 0.1 the R component of the specular coefficient of the material. 
		 interface.scene.instace_sun->inc_angle();
		 break;
	 case 'S': // Section F: decrease by 0.1 the R component of the specular coefficient of the material. 
		 break;
	 case 'p': // Section F: increase by 10 the phong exponent of the material. 
		 break;
	 case 'P': // Section F: decrease by 10 the phong exponent of the material. 
		 break;

	 case 'x': // Section G: increase by 0.2 the spotlight in the X axis
		 break;
	 case 'X': // Section G: decrease by 0.2 the spotlight in the X axis
		 break;
	 case 'y': // Section G: increase by 0.2 the spotlight in the Y axis
		 break;
	 case 'Y': // Section G: decrease by 0.2 the spotlight in the Y axis
		 break;
	 case 'r':
		 interface.scene.rotateEarth();
		 break;

    case 'a': // enable/disable the visualization of the axes
			interface.scene.set_axes(interface.scene.get_axes()?false:true);

	  break;
    case 27: // Escape key to exit
      exit(1);
    break;
  }
	glutPostRedisplay(); // renew the content of the window
}

void cgvInterface::set_glutReshapeFunc(int w, int h) {
  // dimension of the viewport with a new width and a new height of the display window 


  // store the new values of the viewport and the display window. 
  interface.set_width_window(w);
  interface.set_height_window(h);

  // Set up the kind of projection to be used
  interface.camera.apply();

}

void cgvInterface::set_glutDisplayFunc() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window and the z-buffer

	// set up the viewport
	glViewport(0, 0, interface.get_width_window(), interface.get_height_window());
	// Apply the camera and projection parameters
	interface.camera.apply();

	// Render the scene
	interface.scene.render();

	// refresh the window
	glutSwapBuffers(); // it is used instead of glFlush(), to avoid flickering
	
}

void cgvInterface::menuHandle(int value)
{
	interface.scene.set(value);
	glutPostRedisplay(); // renew the content of the window
}

void cgvInterface::init_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
}
