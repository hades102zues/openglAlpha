#define STB_IMAGE_IMPLEMENTATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "MainWindow.h"
#include "SProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"



int main() {

	MainWindow* mainWindow = new MainWindow(800, 600, "jak");
	if (mainWindow->spool() != 1) {
		return -1;
	}

	GLfloat vertices1[] = {
		// positions          // texture coords
	   0.5f,  0.5f, 0.0f,     1.0f, 1.0f,					// top right
	   0.5f, -0.5f, 0.0f,      1.0f, 0.0f,					// bottom right
	  -0.5f, -0.5f, 0.0f,      0.0f, 0.0f,					// bottom left
	  -0.5f,  0.5f, 0.0f,      0.0f, 1.0f					// top left 
	};

	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};


	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	//**GOTCHA**__remember to update the size, stride and starting position values as you change the arrays!!!
	Mesh* mesh = new Mesh(
		vertices, 180, 
		0, 3, GL_FLOAT, sizeof(vertices[0]) * 5, (void*)0, //vertex attribs
		indices, 6,
		2, 2, GL_FLOAT, sizeof(vertices[0]) * 5, (void*)(sizeof(vertices[0]) * 3) //tex coord attribs
	);

	//texture here 
	Texture* container = new Texture("./container.jpg");


	//shaders
	//------------------------------------------------------------
	const char* vPath = "./shaders/shader.vertex";
	const char* fPath = "./shaders/shader.fragment";
	SProgram* shaderProgram = new SProgram(vPath, fPath);

	GLuint modelLoc = shaderProgram->getUniformLocation("model");
	GLuint projectionLoc = shaderProgram->getUniformLocation("projection");
	GLuint viewLoc = shaderProgram->getUniformLocation("view");




	glm::mat4 projection(1.0f);
	int winWidth = mainWindow->getBuffWidth();
	int winHeight = mainWindow->getBuffHeight();
	projection = glm::perspective(
		glm::radians(45.0f),
		(float)winWidth / (float)winHeight,
		0.1f,
		100.0f
	);


	//Camera
	//----------------------------------
	Camera* camera = new Camera();
	float deltaTime = 0.0f;
	float lastTime = 0.0f;
	float currentTime;
	glm::mat4 view = camera->getViewMatrix();


	while (!mainWindow->shouldClose()) {
		glfwPollEvents();

		//screenn clearing
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//pre-empt
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		camera->updateOrientation(mainWindow->getXOffset(), mainWindow->getYOffset());
		camera->updatePosition(mainWindow->getKeyPool(), deltaTime);


		//drawing operations
	    shaderProgram->bindProgram();
			// setting comes AFTER you have bound
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
		container->bindTexture();
		mesh->bindVAO();

		for (unsigned int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			glDrawArrays(GL_TRIANGLES, 0, 36);
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //provides info about the indices array
		}
	  //shaderProgram->unbindProgram();

	  container->unbindTexture();
	  mesh->unbindVAO();


		
		glfwSwapBuffers(mainWindow->getWindow());

	}

	mainWindow->~MainWindow();
	return 0;

}