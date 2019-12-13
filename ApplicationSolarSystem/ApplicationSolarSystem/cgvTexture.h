#ifndef __CGVTEXTURE
#define __CGVTEXTURE

#if defined(__APPLE__) && defined(__MACH__)

#include <GLUT/glut.h>

#include <OpenGL/gl.h>

#include <OpenGL/glu.h>

#else

#include <GL/glut.h>

#endif
#include <stdio.h>

#include "bmp.h"

class cgvTexture {

	protected:
		// Attributes
		unsigned int idTexture; // texture identifier
		unsigned int height,      // height of the texture
			          width;     // weight of the texture

		
	public:
		// Default Constructors and destructor
		cgvTexture(char *file); // Texture from a BMP file
		~cgvTexture();

		// Methods
		void apply(void); // bind the texture as the active texture
};

#endif

