#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera
{
private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	GLfloat pitch;
	GLfloat yaw;
	GLfloat movespeedMultiplier;
	GLfloat sensitivity;

public:
	Camera();
	void updateCameraPlane();
	void updateOrientation(GLfloat mouseXOffset, GLfloat mouseYOffset);
	void updatePosition(bool* keyPool, float deltaTime);
	glm::mat4 getViewMatrix();
	glm::vec3 getCameraWorldPostion();
	~Camera();
};

