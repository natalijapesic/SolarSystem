#include "cgvTexture.h"

// Constructor and destructor methods

cgvTexture::cgvTexture(char *file) {
	unsigned char *image; 
	unsigned int width, height;

	// load the BMP image in memory
	image = loadBMPRaw(file, width, height, true);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	glEnable(GL_TEXTURE_2D);
	//idTexture = 1;
	glGenTextures(1, &idTexture);
	glBindTexture(GL_TEXTURE_2D, idTexture);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	
	/*unsigned char* image = SOIL_load_image(filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(image);*/

	/*glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   
   glTexImage3D(GL_TEXTURE_3D,0,GL_INTENSITY,XDIM,YDIM,ZDIM,0,GL_LUMINANCE,GL_UNSIGNED_BYTE,pVolume);
   */

	delete[] image;
	
}

void cgvTexture::apply(void) {
  glBindTexture(GL_TEXTURE_2D, idTexture);
}

cgvTexture::~cgvTexture() {
  glDeleteTextures(1, &idTexture); 
}
