#include "Camera.h"


Camera::Camera() {

	this->front = glm::vec3(0.0f, 0.0f, -1.0f);
	this->position = glm::vec3(0.0f, 0.0f, 3.0f);
	this->movespeedMultiplier = 0.5f;
	this->sensitivity = 0.5;
	this->pitch = 20.0f ;
	this->yaw = 0.0f;

	this->updateCameraPlane();
}

void Camera::updateCameraPlane() {

	this->front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	this->front.y = sin(glm::radians(pitch));
	this->front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	this->front = glm::normalize(this->front);

	this->right = glm::normalize(glm::cross(this->front, glm::vec3(0.0f, 1.0f, 0.0f)));
	this->up = glm::normalize(glm::cross(this->right, this->front)); 

}

void Camera::updateOrientation(GLfloat mouseXOffset, GLfloat mouseYOffset	) {

	mouseXOffset *= this->sensitivity ;
	mouseYOffset *= this->sensitivity ;

	this->yaw += mouseXOffset;
	this->pitch += mouseYOffset;


	if (this->pitch > 89.0f)
		this->pitch = 89.0f;
	if (this->pitch < -89.0f)
		this->pitch = -89.0f;


	this->updateCameraPlane();

}


void Camera::updatePosition(bool* keyPool) {

	if (keyPool[GLFW_KEY_W]) {
		this->position +=  this->movespeedMultiplier * this->front;
	}

	if (keyPool[GLFW_KEY_S]) {
		this->position -= this->movespeedMultiplier *  this->front;
	}

	if (keyPool[GLFW_KEY_A]) {
		this->position -= this->movespeedMultiplier *  this->right ;
	}

	if (keyPool[GLFW_KEY_D]) {
		this->position += this->movespeedMultiplier *  this->right ;
	}

}

glm::mat4 Camera::getViewMatrix() {

	return glm::lookAt(this->position, this->front + this->position, this->up);

}


glm::vec3 Camera::getCameraWorldPostion() {
	
	return this->position;

}