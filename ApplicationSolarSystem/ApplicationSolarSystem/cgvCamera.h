#ifndef __CGVCAMERA
#define __CGVCAMERA

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif

#include "cgvPoint3D.h"

typedef enum {
	CGV_PARALLEL,
	CGV_FRUSTUM,
	CGV_PERSPECTIVE
} cameraType;

class cgvCamera {

	public:
		// attributes
		
		cameraType type;	// parallel or perspective

		// view plane: parameters parallel projection and frustum
		GLdouble xwmin, xwmax, ywmin, ywmax;

		// view plane: parameters perspective projection
		GLdouble angle, raspect;

		// distances of near and far planes
		GLdouble znear, zfar;

		// point of view
		cgvPoint3D P0;

		// view reference point	
		cgvPoint3D r;

		// up vector 
		cgvPoint3D V;

		// Methods

	public:
		// Default Constructors and destructor
		cgvCamera();
		~cgvCamera();

		// other Constructors
		cgvCamera(cameraType _type, cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V);

		// Methods
		// define the camera position
		void set(cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V);

		// define a parallel or a frustum camera
		void set(cameraType _type, cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V,
			                         double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar);

		// define a perspective camera
		void set(cameraType _type, cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V,
			                         double _angle, double _raspect, double _znear, double _zfar);

		void apply(void); // apply the view and projection transformations to the object of the scene. 
		                    
};

#endif

