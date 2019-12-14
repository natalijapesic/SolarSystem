#include "cgvMaterial.h"

// Constructor and destructor methods 

cgvMaterial::cgvMaterial () {
	
}

cgvMaterial::~cgvMaterial () {

}

cgvMaterial::cgvMaterial (const cgvMaterial& m) {	//copy constructor
	Ka = m.Ka;
	Kd = m.Kd;
	Ks = m.Ks;
	Ns = m.Ns;
}

cgvMaterial::cgvMaterial(cgvColor _Ka, cgvColor _Kd, cgvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Public methods 

void cgvMaterial::apply(void) {

// Section C
// Apply the attributes of the cgvMaterial object:
// - ambient coefficient 
// - diffuse coefficient
// - specular coefficient
// - Phong exponent

// set the color (0.0, 0.0, 0.0) as emission color (the object is not a light source )

	GLfloat ak[3] = { Ka[0], Ka[1], Ka[2] };
	GLfloat dk[3] = { Kd[0], Kd[1], Kd[2] };
	GLfloat sk[3] = { Ks[0], Ks[1], Ks[2] };

	glMaterialfv(GL_FRONT, GL_AMBIENT, ak);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dk);
	glMaterialfv(GL_FRONT, GL_SPECULAR, sk);

	glMaterialf(GL_FRONT, GL_SHININESS, Ns);

	float color[] = { 0.0,0.0,0.0 };
	glMaterialfv(GL_FRONT, GL_EMISSION, color);
}

void cgvMaterial::set(cgvColor _Ka, cgvColor _Kd, cgvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



