#include <stdlib.h>

#include "cgvInterface.h"

// Global objects
// Object that contains the configuration and the interaction with the display window
cgvInterface interface;

int width = glutGet(GLUT_SCREEN_WIDTH);
int main (int argc, char** argv) {
	// initialize the display window
	interface.configure_environment(argc,argv,
	                           width,width/2, // window size
														 0,0, // window position
														 "Solar System" // title of the window
														 );

	// define the callbacks to manage the events. 
	interface.init_callbacks();

	// initialize the loop of the OpenGL visualization
	interface.init_rendering_loop();

	return(0);
}
