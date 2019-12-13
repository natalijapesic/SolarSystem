#include "cgvLight.h"

// Constructor methods 

cgvLight::cgvLight() {
}

cgvLight::cgvLight(const unsigned int _idLight,
  				   const cgvPoint3D  & _position,
				   const cgvColor & cAmb, const cgvColor & cDif, const cgvColor & cEsp,
				   const double a0, const double a1, const double a2) {

  idLight = _idLight;
														 
	position = _position;
														 
	ambientColor = cAmb;
	diffuseColor = cDif;
	specularColor = cEsp;

	atten_a0 = a0;
	atten_a1 = a1;
	atten_a2 = a2;

	// Default values for point lights 
	spotlight_direction = cgvPoint3D(0,0,0);
	spotlight_angle = 180; // with this angle the spotlight becomes a point light source	
	spotlight_exponent = 0;

	on = true;
}

cgvLight::cgvLight(const unsigned int _idLight,
                   const cgvPoint3D & _position, 
                   const cgvColor& cAmb, const cgvColor& cDif, const cgvColor& cEsp,
		           const double a0, const double a1, const double a2,
				   const cgvPoint3D& spotlight_dir, const double spotlight_ang, const double spotlight_exp) {

  idLight = _idLight;
														 
	position = _position;
														 
	ambientColor = cAmb;
	diffuseColor = cDif;
	specularColor = cEsp;

	atten_a0 = a0;
	atten_a1 = a1;
	atten_a2 = a2;

	spotlight_direction = spotlight_dir;
	spotlight_angle = spotlight_ang;
	spotlight_exponent = spotlight_exp;

	on = true;
}

// Public methods ----------------------------------------

cgvPoint3D& cgvLight::getPosition(void) {
	return position;
}

void cgvLight::setPosition(cgvPoint3D pos) {
	position = pos;
}


void cgvLight::set(const cgvColor & cAmb, const cgvColor & cDif, const cgvColor & cEsp) {
	ambientColor = cAmb;
	diffuseColor = cDif;
	specularColor = cEsp;
}

void cgvLight::setAmbient(const cgvColor & cAmb) {
	ambientColor = cAmb;
}

void cgvLight::setDiffuse(const cgvColor & cDif) {
	diffuseColor = cDif;
}

void cgvLight::setSpecular(const cgvColor & cEsp) {
	specularColor = cEsp;
}

cgvColor & cgvLight::getAmbient(void) {
	return ambientColor;
}

cgvColor & cgvLight::getDiffuse(void) {
	return diffuseColor;
}

cgvColor & cgvLight::getSpecular(void) {
	return specularColor;
}

void cgvLight::setAttenuation(double a0, double a1, double a2) {
	atten_a0 = a0;
	atten_a1 = a1;
	atten_a2 = a2;
}

void cgvLight::getAttenuation(double & a0, double & a1, double & a2) {
	a0 = atten_a0;
	a1 = atten_a1;
	a2 = atten_a2;
}

void cgvLight::switchOn(void) {
  on = true;
}

void cgvLight::switchOff(void) {
  on = false;
}

unsigned int cgvLight::is_On(void) {
  return on;
}

void cgvLight::apply(void) {

// Section A
// if the light is on
//	enable the light
//	set the position of the light
//	set ambient, diffuse and specular colors
//	set radial attenuation
//	set the spotlight parameters: direction, cutoff, exponent. 

// If the light is off
//	disable the light 

}

