#pragma once
#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1

#include "cgvColor.h"

//cgvPoint3D(300,0,50),cgvPoint3D(0,0,50),cgvPoint3D(0,1.0,0),   MIDDLE
//- 1 * 50, 1 * 50, -1 * 25, 1 * 25, -1 * 0, 600)


	//it is assumed that the sun revolves around its axis in 30 days
	//the scaleHours is the variable which said how much time passed after one button click
	//variables
	//radius of sun is 695,500km...km == cm ==> valueHere=659,500/1000 

static const float scaleRadius = 10000.0f;
static const float scaleHours = 100;

#pragma region Sun
static const float sun_radius = 695500;
#pragma endregion

//Objects
#pragma region Mercury
static const double mercury_radius = 2439.7;//the size of the planet 
static const double mercury_orbit_radius = 58000000; //distance from the orbit
static const double mercury_self_rotatin = 1408;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double mercury_orbit_rotation = 87.97; //days to rotate around the orbit
//88*24 = hours to rotate around the orbit
//360 / (88*24) = degreese in 1hour
#pragma endregion

#pragma region Venus
static const double venus_radius = 6051.8;
static const double venus_orbit_radius = 108000000;
static const double venus_self_rotatin = 5832;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double venus_orbit_rotation = 224.7; //days to rotate around the orbit

#pragma endregion

#pragma region Earth
static const double earth_radius = 6378.1;//
static const double earth_orbit_radius = 150000000;
static const double earth_self_rotatin = 24;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double earth_orbit_rotation = 365.26; //days to rotate around the orbit

#pragma endregion

#pragma region Mars
static const double mars_radius = 3396.2;// 
static const double mars_orbit_radius = 228000000 ;
static const double mars_self_rotatin = 25;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double mars_orbit_rotation = 686.98; //days to rotate around the orbit

#pragma endregion

#pragma region Jupiter
static const double jupiter_radius = 71492;//
static const double jupiter_orbit_radius = 778000000;
static const double jupiter_self_rotatin = 10;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double jupiter_orbit_rotation = 4332.82; //days to rotate around the orbit

#pragma endregion

#pragma region Saturn
static const double saturn_radius = 60268;// 
static const double saturn_orbit_radius = 1427000000;
static const double saturn_self_rotatin = 11;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double saturn_orbit_rotation = 10755.7; //days to rotate around the orbit

#pragma endregion

#pragma region Uran
static const double uran_radius = 25559;// 
static const double uran_orbit_radius = 2871000000;
static const double uran_self_rotatin = 17;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double uran_orbit_rotation = 30687.15; //days to rotate around the orbit

#pragma endregion

#pragma region Neptun
static const double neptun_radius =24764 ;//
static const double neptun_orbit_radius = 4497000000;
static const double neptun_self_rotatin = 16;//hours to rotate 360 around itself, 360/self_rotatin is how many degrees it rotates around itself for 1h
static const double neptun_orbit_rotation = 60190.03; //days to rotate around the orbit

#pragma endregion

#pragma region Comet
static const double comet_radius = 10;
static const double comet_tail = 1000000;
static const double comet_speed = 100 * 3600 * scaleHours / scaleRadius; // km/s
static const double min_sun_distance = 5000000000;
static const double middle_distance = 228000000;
#pragma endregion



#endif

