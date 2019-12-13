#include "cgvColor.h"

// Constructors

cgvColor::cgvColor () {
}

cgvColor::~cgvColor () {
}

cgvColor::cgvColor (const double r, const double g, const double b) {
	color[R] = r;
	color[G] = g;
	color[B] = b;
}

cgvColor::cgvColor (const double r, const double g, const double b, const double a) {
	color[R] = r;
	color[G] = g;
	color[B] = b;
	color[A] = a;
}

cgvColor::cgvColor (const cgvColor& p) {	//copy constructor
	color[R] = p.color[R];
	color[G] = p.color[G];
	color[B] = p.color[B];
	color[A] = p.color[A];
}

// Public methods 

// Access operators
double& cgvColor::operator[] ( const unsigned char idx ) {
	return color[idx];
}

double cgvColor::operator[] (const unsigned char idx) const {
	return color[idx];
}

void cgvColor::apply (void) {
	glColor4dv(color);
}
