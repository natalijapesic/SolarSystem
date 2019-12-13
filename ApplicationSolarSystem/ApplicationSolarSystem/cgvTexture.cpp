#include "cgvTexture.h"

// Constructor and destructor methods

cgvTexture::cgvTexture(char *file) {
	unsigned char *image; 
	unsigned int width, height;

	// load the BMP image in memory
	image = loadBMPRaw(file, width, height, true);

	/* TODO: Section H: Add here the code to load the BMP image as a texture */
	/*
	- Enable GL_TEXTURE_2D
	- Generate the identifier of the texture and assign it to the attribute idTexture
	- Application mode of the texture
	- Parameters of the texture: repeat and filters
	- Specify the texture assigning it the image array.
	*/



	delete[] image;
	
}

void cgvTexture::apply(void) {
  glBindTexture(GL_TEXTURE_2D, idTexture);
}

cgvTexture::~cgvTexture() {
  glDeleteTextures(1, &idTexture); 
}
