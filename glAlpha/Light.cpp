#include "Light.h"


Light::Light() {

	this->position = glm::vec3(0.0f, 0.0f, 5.0f);
	this->color = glm::vec3(1.0f, 1.0f, 1.0f);

}


Light::Light(glm::vec3 pos, glm::vec3 color) {

	this->position = pos;
	this->color = color;

}

glm::vec3 Light::getPosition() {
	return this->position;
}
glm::vec3 Light::getColor() {
	return this->color;
}
GLfloat Light::getAmbIntensity() {
	return this->ambientIntensity;
}
GLfloat Light::getDiffIntensity() {
	return this->diffusionIntensity;
}
GLfloat Light::getSpecIntensity() {
	return this->specularIntensity;
}





Light::~Light() {

}