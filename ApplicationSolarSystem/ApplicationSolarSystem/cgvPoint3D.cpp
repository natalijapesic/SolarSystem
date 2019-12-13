#include <stdio.h>
#include <math.h>

#include "cgvPoint3D.h"

// Constructors
cgvPoint3D::cgvPoint3D() {
	c[X] = c[Y] = c[Z] = 0.0;
}

cgvPoint3D::cgvPoint3D (const double& x, const double& y, const double& z ) {
	c[X] = x;
	c[Y] = y;
	c[Z] = z;	
}

// Copy constructor 
cgvPoint3D::cgvPoint3D (const cgvPoint3D& p ) {
	c[X] = p.c[X];
	c[Y] = p.c[Y];
	c[Z] = p.c[Z];
}

// Assignment operator 
cgvPoint3D& cgvPoint3D::operator = (const cgvPoint3D& p) {
	c[X] = p.c[X];
	c[Y] = p.c[Y];
	c[Z] = p.c[Z];
	return(*this);
}

// Destructor
cgvPoint3D::~cgvPoint3D() {
}

// Operators
int cgvPoint3D::operator == (const cgvPoint3D& p) {
	return ((fabs(c[X]-p[X])<IGV_EPSILON) && (fabs(c[Y]-p[Y])<IGV_EPSILON) && (fabs(c[Z]-p[Z])<IGV_EPSILON));
}

int cgvPoint3D::operator != (const cgvPoint3D& p) {
	return ((fabs(c[X]-p[X])>=IGV_EPSILON) || (fabs(c[Y]-p[Y])>=IGV_EPSILON) || (fabs(c[Z]-p[Z])>=IGV_EPSILON));
}

void cgvPoint3D::set( const double& x, const double& y, const double& z) {
	c[X] = x;
	c[Y] = y;
	c[Z] = z;
}

