#ifndef __CGVMATERIAL
#define __CGVMATERIAL

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif

#include "cgvColor.h"

class cgvMaterial {

	protected:
		// attributes
		cgvColor Ka; // ambient coefficient 
		cgvColor Kd; // diffuse coefficient
		cgvColor Ks; // specular coefficient
		double   Ns; // Phong exponent
		
		// Methods

	public:
		// Default constructor and destructor
		cgvMaterial();
		~cgvMaterial();

		// Other constructors
		cgvMaterial(const cgvMaterial& m);	//copy constructor
		cgvMaterial(cgvColor _Ka, cgvColor _Kd, cgvColor _Ks, double _Ns);

		// Methods 
		void apply(void);

		void set(cgvColor _Ka, cgvColor _Kd, cgvColor _Ks, double _Ns);
};

#endif

