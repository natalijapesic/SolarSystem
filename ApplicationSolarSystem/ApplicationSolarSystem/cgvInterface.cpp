#include <stdio.h>
#include <stdlib.h>

#include "cgvInterface.h"

extern cgvInterface interface; // the callbacks must be static and this object is required to access to the variables of the class                   // ellos a las variables de la clase

// Constructor and destructor methods -----------------------------------

cgvInterface::cgvInterface () {}

cgvInterface::~cgvInterface () {}

static int x = 0;

// Public methods ----------------------------------------
void cgvInterface::create_world(void) {
	// create the camera

	mode = CGV_VISUALIZE;
	pressed_button = false;

	interface.current_cam = 2;

	// create the camera
	double size_of_the_visible_part;// from camera:
	size_of_the_visible_part = scaleSize(sun_radius) / 2 / scaleRadius;//distance from the coordinate beggining to the furthest planet - center to center
	double znear = scaleSize(neptun_orbit_radius + sun_radius + neptun_radius) * 1.01 / 2 / scaleRadius;
	double shift = scaleSize(sun_radius) * 0.8 / scaleRadius;//
	//double parameter = size_of_the_visible_part / 2/* + shift*/;

	interface.camera[2].set(CGV_PARALLEL, cgvPoint3D(znear, 0, size_of_the_visible_part + shift), cgvPoint3D(0, 0, size_of_the_visible_part + shift), cgvPoint3D(0, 1.0, 0),
		-1 * size_of_the_visible_part, 1 * size_of_the_visible_part, -1 * size_of_the_visible_part / 2, 1 * size_of_the_visible_part / 2, -1 * 0, znear * 2);

	interface.camera[0].set(CGV_PARALLEL, cgvPoint3D(30,0,-50),cgvPoint3D(0,0,0),cgvPoint3D(0,1, 0),
		                                -1*100, 1*100, -1*50, 1*50, -1*0, 600);
	interface.camera[1].set(CGV_PARALLEL, cgvPoint3D(50000, 0, 0), cgvPoint3D(0, 0, 250), cgvPoint3D(0, 1.0, 0),
		-1 * 2500, 1 * 2500, -1 * 1250, 1 * 1250, -1 * 0, 5000000 * 2);


	// create the camera
	double size_of_the_visible_part;// from camera:
	size_of_the_visible_part = scaleSize(sun_radius) / 2 / scaleRadius;//distance from the coordinate beggining to the furthest planet - center to center
	double znear = scaleSize(neptun_orbit_radius + sun_radius + neptun_radius) *1.01 / 2 / scaleRadius;
	double shift = scaleSize(sun_radius)*0.8 / scaleRadius;//
	//double parameter = size_of_the_visible_part / 2/* + shift*/;

	interface.camera[2].set(CGV_PARALLEL, cgvPoint3D(znear, 0, size_of_the_visible_part + shift), cgvPoint3D(0, 0, size_of_the_visible_part + shift), cgvPoint3D(0, 1.0, 0),
		-1 * size_of_the_visible_part, 1 * size_of_the_visible_part, -1 * size_of_the_visible_part / 2, 1 * size_of_the_visible_part / 2, -1 * 0, znear * 2);

	double border = scaleSize(4 * neptun_radius)/scaleRadius;// 4 neptun radius = 2 neptuns
	shift = scaleSize(sun_radius)/scaleRadius - border;

	double width_image = border/*add to the left of the image*/
		+ 2 * scaleSize(neptun_radius)/scaleRadius/*do fit the last planet*/
		+ scaleSize(neptun_orbit_radius) / scaleRadius/*distance between npt and sun*/
		+ border/*right border where a part of the sun is visible*/;

	double furthest_point = width_image + shift;
	printf("%f\n", width_image);
	
	interface.camera[1].set(CGV_PARALLEL, cgvPoint3D(furthest_point, 0, width_image/2 + shift), cgvPoint3D(0, 0, width_image / 2 + shift), cgvPoint3D(0, 1.0, 0),
		-1 * width_image/2, 1 * width_image / 2, -1 * width_image / 4, 1 * width_image / 4, -1 * 0, furthest_point * 2 /*to see the whole system*/);


	interface.camera[0].set(CGV_PARALLEL, cgvPoint3D(300,0,50),cgvPoint3D(0,0,50),cgvPoint3D(0,1.0,0),
		                                -1*70, 1*70, -1*35, 1*35, -1*0, 600);
	
	
	interface.camera[3].set(CGV_PARALLEL, cgvPoint3D(50000, 0, 225), cgvPoint3D(0, 0, 225), cgvPoint3D(0, 1.0, 0),
		-1 * 225, 1 * 225, -1 * 112.5, 1 * 112.5, -1 * 0, 50000 * 2);
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

	//create_menu();

	glEnable(GL_DEPTH_TEST); // enable the removal of hidden surfaces by using the z-buffer
  glClearColor(1.0,1.0,1.0,0.0); // define the background color of the window

	glEnable(GL_LIGHTING); // enable the lighting of the scene
  glEnable(GL_NORMALIZE); // normalize the normal vectors required by the lighting computation. 
	glEnable(GL_TEXTURE_2D); // enable the use of 2D textures


  create_world(); // create the world (scene) to be rendered in the window
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
		 interface.scene.instance_sun->inc_angle();
		 break;
	 case 'S': // Section F: decrease by 0.1 the R component of the specular coefficient of the material. 
		 scaleHours -= 10;
		 printf("%f\n", scaleHours);
		 break;
	 case 'F':
		 scaleHours += 10;
		 printf("%f\n", scaleHours);
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
		 if(rotate_comet)
		 for (int i = 0; i < 500; i++)
			interface.scene.comets_rain[i]->move_comet();
		 interface.scene.instance_sun->inc_angle();
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
  interface.camera[interface.current_cam].apply();

}

void cgvInterface::set_glutDisplayFunc() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window and the z-buffer

	// set up the viewport
	glViewport(0, 0, interface.get_width_window(), interface.get_height_window());
	// Apply the camera and projection parameters

	if (interface.mode == CGV_SELECT) {
		// Section D: if it is in the OpenGL selection mode disable the lighting to use the color buffer technique
		interface.init_selection();
	}
	interface.camera[interface.current_cam].apply();

	// Render the scene
	interface.scene.render(interface.mode);

	if (interface.mode == CGV_SELECT) {
		// Section D: exit the selection mode and process the information in the color buffer
		interface.mode = CGV_VISUALIZE;
		interface.finish_selection();
		glutPostRedisplay();
	}
	else {
		// refresh the window
		glutSwapBuffers(); // it is used instead of glFlush(), to avoid flickering
	}
}

void cgvInterface::menuHandle(int value)
{
	interface.scene.set(value);
	glutPostRedisplay(); // renew the content of the window
}

void cgvInterface::set_glutMouseFunc(GLint button, GLint state, GLint x, GLint y)
{
	if (button == GLUT_LEFT_BUTTON) {
		// Section D: Store the button that has been pressed or released. If it has been clicked, then change to selection mode (CGV_SELECT)
		if (interface.pressed_button == false && state == GLUT_DOWN) {
			interface.pressed_button = true;
			interface.mode = CGV_SELECT;
		}
		else if (interface.pressed_button == true && state == GLUT_UP) {
			interface.pressed_button = false;
			interface.mode = CGV_VISUALIZE;
		}

		// Section D: Save the position of the pixel when the mouse was clicked

		interface.cursorX = x;
		interface.cursorY = y;

		// Section D: Redraw the content of the display window 
		glutPostRedisplay();

	}
}

void cgvInterface::set_glutMotionFunc(GLint x, GLint y)
{
	if (!interface.pressed_button)
		return;

	// Section F: Save the new position of the mouse
	interface.cursorX = x;
	interface.cursorY = y;
	// Section F: Redraw the content of the display window 
	glutPostRedisplay();
}

void cgvInterface::init_selection()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void cgvInterface::finish_selection()
{
	glReadBuffer(GL_BACK);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);

	GLubyte pixels[3] = { 0, 0, 0 };

	// TODO: Section D: Use the function glReadPixels to get the color at a given position of the window. 
	glReadPixels(cursorX, height_window - cursorY - 1, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	// Section D: Call the assignSelection method of the scene class to compute the selected part of the model, if any. 
	assignSelection(pixels);

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

void cgvInterface::init_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);

	glutMouseFunc(set_glutMouseFunc);
	glutMotionFunc(set_glutMotionFunc);
}

void cgvInterface::assignSelection(GLubyte color[3])
{
	if (interface.current_cam == 2 && color[0] == earth[0] && color[1] == earth[1] && color[2] == earth[2])
	{
		interface.current_cam = 0; //4
	}
	else {
		interface.current_cam = 2;
	}
}
