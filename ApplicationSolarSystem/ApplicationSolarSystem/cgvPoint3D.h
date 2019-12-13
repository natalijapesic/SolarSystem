/************************************************************************************************/
/* The class cgvPoint3D implements the functionality of the objects Point and Vector in 3D */
/************************************************************************************************/

#ifndef __CGVPOINT3D
#define __CGVPOINT3D

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif

#define IGV_EPSILON 0.000001 // for comparisons with 0

#ifndef __ENUM_XYZ
#define __ENUM_XYZ

typedef enum {
	X,
	Y,
	Z
};
#endif

class cgvPoint3D {

	public:
		double c[3]; // components x, y, z of a point or vector

	public:
		// Constructors
		cgvPoint3D();
		cgvPoint3D( const double& x, const double& y, const double& z );
		
		// Copy Constructor 
		cgvPoint3D( const cgvPoint3D& p );

		// Assignment operator
		cgvPoint3D& operator = (const cgvPoint3D& p);

		// Destructor
		~cgvPoint3D();

		// Operators
		inline double& operator[] ( const unsigned char idx ) {return c[idx];};
		inline double operator[] (const unsigned char idx) const {return c[idx];};

		int operator == (const cgvPoint3D& p);
		int operator != (const cgvPoint3D& p);

		void set( const double& x, const double& y, const double& z);
};
#endif

