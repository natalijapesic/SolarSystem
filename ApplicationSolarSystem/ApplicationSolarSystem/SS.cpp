#include <stdlib.h>

#include "cgvInterface.h"

// Global objects
// Object that contains the configuration and the interaction with the display window
cgvInterface interface;

int main (int argc, char** argv) {
	// initialize the display window
	interface.configure_environment(argc,argv,
	                           1200,600, // window size
														 100,100, // window position
														 "Computer Graphics and Visualization. Practice 4." // title of the window
														 );

	// define the callbacks to manage the events. 
	interface.init_callbacks();

	// initialize the loop of the OpenGL visualization
	interface.init_rendering_loop();

	return(0);
}
