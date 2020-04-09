#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Light
{
private:
	glm::vec3 position;
	glm::vec3 color;
	GLfloat ambientIntensity;
	GLfloat diffusionIntensity;
	GLfloat specularIntensity;

public:

	Light();
	Light(glm::vec3 pos, glm::vec3 color);

	glm::vec3 getPosition();
	glm::vec3 getColor();
	GLfloat getAmbIntensity();
	GLfloat getDiffIntensity();
	GLfloat getSpecIntensity();


	~Light();

};

