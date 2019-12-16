#ifndef __CGVSCENE3D
#define __CGVSCENE3D

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif

#include "cgvLight.h"
#include "Constants.h"
#include "Sun.h"
#include "Planet.h"
#include "Comet.h";

#define nbScenes 5

typedef enum {
	CGV_VISUALIZE,
	CGV_SELECT
} renderMode;

class cgvScene3D {
	public:/*
		int Scene[nbScenes];
		char *Scene_Name[nbScenes];*/

	protected:
		// Attributes

		bool axes;
		int selectedScene;
		Planet *Mercury, *Venus, *Earth, *Mars, *Jupiter, *Saturn, *Uran, *Neptun;
	public:
		Sun* instance_sun;
		Comet* comets_rain[3];
		// Default constructor and destructor
		cgvScene3D();
		~cgvScene3D();

		void set(int scene);

		// Static methods

		// Methods
		// method with the OpenGL calls to render the scene
		void render(renderMode mode);

		void natalija();
		void marija();
		bool get_axes() {return axes;};
		void set_axes(bool _axes){axes = _axes;};
		void draw_axes(void);

		void rotateEarth();
};

#endif
