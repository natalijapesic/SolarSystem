#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif

#include <math.h>

#include "cgvCamera.h"

// Constructors

cgvCamera::cgvCamera () {}

cgvCamera::~cgvCamera () {}

cgvCamera::cgvCamera(cameraType _type, cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;

	type = _type;
}


// Public methods 
void cgvCamera::set(cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;
}
void cgvCamera::set(cameraType _type, cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V,
			                                double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar) {
	type = _type;

	P0 = _P0;
	r = _r;
	V = _V;

	xwmin = _xwmin;
	xwmax = _xwmax;
	ywmin = _ywmin;
	ywmax = _ywmax;
	znear = _znear;
	zfar = _zfar;
}

void cgvCamera::set(cameraType _type, cgvPoint3D _P0, cgvPoint3D _r, cgvPoint3D _V,
			                         double _angle, double _raspect, double _znear, double _zfar) {
	type = _type;

	P0 = _P0;
	r = _r;
	V = _V;

	angle = _angle;
	raspect = _raspect;
	znear = _znear;
	zfar = _zfar;
}

void cgvCamera::apply(void) {
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	if (type==CGV_PARALLEL) {
		glOrtho(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (type==CGV_FRUSTUM) {
		glFrustum(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (type==CGV_PERSPECTIVE) {
		gluPerspective(angle,raspect,znear,zfar);
	}
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(P0[X],P0[Y],P0[Z], r[X],r[Y],r[Z], V[X],V[Y],V[Z]);
}
