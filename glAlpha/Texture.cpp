#include "Texture.h"

Texture::Texture() {

	std::cout << "Incomplete texture created." << std::endl;
				
}


Texture::Texture(const char* t_Path) {

	glGenTextures(1, &this->textureID);
	this->path = t_Path;

	this->loadTexture();
}

void Texture::loadTexture() {

	glBindTexture(GL_TEXTURE_2D, this->textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(this->path, &width, &height, &nrChannels, 0);
	
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << " Error loading texture image from path" << std::endl;
	}

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);


}

void Texture::bindTexture() {
	
	glBindTexture(GL_TEXTURE_2D, this->textureID);

}


void Texture::unbindTexture() {

	glBindTexture(GL_TEXTURE_2D, 0);

}