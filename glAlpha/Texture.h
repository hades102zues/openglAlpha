#pragma once
#include <GL/glew.h>
#include <iostream>
#include "stb_image.h	"

class Texture
{
private:
	GLuint textureID;
	const char* path;

public:
	Texture();
	Texture(const char* textPath);

	void	 loadTexture();
	void bindTexture();
	void unbindTexture();

	~Texture();
};

