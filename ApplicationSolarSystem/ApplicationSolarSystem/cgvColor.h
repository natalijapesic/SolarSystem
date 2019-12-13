#ifndef __CGVCOLOR
#define __CGVCOLOR

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif


typedef enum {
	R,
	G,
	B,
	A
};

class cgvColor {

	protected:
		// attributes

		double color[4]; // components R, G, B, A of the color
		
		// Methods

	public:
		// Default constructor and destructor
		cgvColor();
		~cgvColor();

		// Other constructors
		cgvColor(const double r, const double g, const double b);
		cgvColor(const double r, const double g, const double b, const double a);
		cgvColor(const cgvColor& p);	//copy constructor

		// Methods
		double& operator[] ( const unsigned char idx );
		double operator[] (const unsigned char idx) const;

		void apply(void);

};

#endif

