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


}

void cgvMaterial::set(cgvColor _Ka, cgvColor _Kd, cgvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



