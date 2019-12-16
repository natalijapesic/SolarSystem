#include "cgvTexture.h"

// Constructor and destructor methods

cgvTexture::cgvTexture(char *file) {
	unsigned char *image; 

	// load the BMP image in memory
	image = loadBMPRaw(file, width, height, true);

	glGenTextures(1, &idTexture);
	glBindTexture(GL_TEXTURE_2D, idTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/*GL_REPLACE*/);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	//glEnable(GL_TEXTURE_2D);
	////idTexture = 1;
	//glGenTextures(1, &idTexture);
	//glBindTexture(GL_TEXTURE_2D, idTexture);

	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);




	delete[] image;
	
}

void cgvTexture::apply(void) {
  glBindTexture(GL_TEXTURE_2D, idTexture);
  
}

cgvTexture::~cgvTexture() {
  glDeleteTextures(1, &idTexture); 
}
