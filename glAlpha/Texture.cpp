
#include "Texture.h"

Texture::Texture() {

	std::cout << "Incomplete texture created. Please use other overloaded constructor." << std::endl;
				
}


Texture::Texture(const char* t_Path) {

	glGenTextures(1, &this->textureID);
	this->path = t_Path;

	this->loadTexture();
}

void Texture::loadTexture() {

	int width, height, nrComponents;
	unsigned char* data = stbi_load(this->path, &width, &height, &nrComponents, 0);
	
	if (data) {

		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, this->textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << " Error loading texture image from path" << std::endl;
	}

	stbi_image_free(data);

}

void Texture::bindTexture() {
	
	glBindTexture(GL_TEXTURE_2D, this->textureID);

}


void Texture::unbindTexture() {

	glBindTexture(GL_TEXTURE_2D, 0);

}