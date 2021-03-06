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

	MainWindow* mainWindow = new MainWindow(1280, 800, "jak");
	if (mainWindow->spool() != 1) {
		return -1;
	}

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
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};


	GLfloat vertices[] = {
		// positions          // normals           // texture coords
		   -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
			0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
			0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
			0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		   -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		   -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		   -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
			0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
			0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
			0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		   -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		   -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		   -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		   -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		   -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		   -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		   -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		   -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

			0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
			0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
			0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
			0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
			0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
			0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		   -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
			0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
			0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		   -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		   -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		   -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
			0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
			0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
			0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		   -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		   -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};



	//**GOTCHA**__remember to update the size, stride and starting position values as you change the arrays!!!
	Mesh* bigSquare = new Mesh(
		vertices, 288, 
		0, 3, GL_FLOAT, sizeof(vertices[0]) * 8, (void*)0, //vertex attribs
		nullptr, 0,
		2, 2, GL_FLOAT, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 6), //tex coord attribs 
		1, 3, GL_FLOAT, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3) //norm attribs

	);
	Mesh* lightSource = new Mesh(
		vertices, 288,
		0, 3, GL_FLOAT, sizeof(vertices[0]) * 8, (void*)0, //vertex attribs
		nullptr, 0,
		2, 2, GL_FLOAT, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 6), //tex coord attribs 
		1, 3, GL_FLOAT, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3) //norm attribs
	);

	//texture here 
	Texture* container = new Texture("./container.jpg");
	Texture* crate = new Texture("./textures/container2.png");
	Texture* crate_spec = new Texture("./textures/container2_specular.png");

	//shaders Structs
	//------------------------------------------------------------
	const char* vPath = "./shaders/shader.vertex";
	const char* lsFPath = "./shaders/shaderLS.fragment";
	const char* objFPath = "./shaders/shaderObj.fragment"; 


	//shader Programs
	//------------------------------------------------------------
	SProgram* ls_shaderProgram = new SProgram(vPath, lsFPath);
	SProgram* obj_shaderProgram = new SProgram(vPath, objFPath);


	//Projection
	//-------------------------------------------------
	glm::mat4 projection(1.0f);
	projection = glm::perspective(
		glm::radians(45.0f),
		(float)(mainWindow->getBuffWidth()) / (float)(mainWindow->getBuffHeight()),
		0.1f,
		100.0f
	);


	//Camera
	//----------------------------------
	Camera* camera = new Camera(glm::vec3(-12.2f, -1.0f, -4.0f));
	float deltaTime = 0.0f;
	float lastTime = 0.0f;
	float currentTime;

	//Models
	//------------------------
	glm::vec3 lightPos(7.0f, 4.2f, 2.0f);
	glm::mat4 ls_model= glm::mat4(1.0);
	ls_model = glm::translate(ls_model, lightPos);
	ls_model = glm::scale(ls_model, glm::vec3(0.2f));

	glm::mat4 obj_model = glm::mat4(1.0);
	obj_model = glm::translate(obj_model, glm::vec3(1.0f, -0.0f, -3.0f) );
	obj_model = glm::scale(obj_model, glm::vec3(4.0));



	while (!mainWindow->shouldClose()) {
		glfwPollEvents();

		//screenn clearing
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//pre-empt
		//---------------------------------------
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		camera->updateOrientation(mainWindow->getXOffset(), mainWindow->getYOffset());
		camera->updatePosition(mainWindow->getKeyPool(), deltaTime);


		//drawing operations
		//---------------------------------------
	    ls_shaderProgram->bindProgram();

			ls_shaderProgram->setMat4("model", ls_model);
			ls_shaderProgram->setMat4("view", camera->getViewMatrix());
			ls_shaderProgram->setMat4("projection", projection);

			lightSource->bindVAO();
				glDrawArrays(GL_TRIANGLES, 0, 36);
			lightSource->unbindVAO();

		ls_shaderProgram->unbindProgram();


		obj_shaderProgram->bindProgram();

			obj_shaderProgram->setMat4("model", obj_model);
			obj_shaderProgram->setMat4("view", camera->getViewMatrix());
			obj_shaderProgram->setMat4("projection", projection);

			obj_shaderProgram->setVec3("cameraPos", camera->getCameraWorldPostion());

		
			glActiveTexture(GL_TEXTURE0);
				crate->bindTexture();
				obj_shaderProgram->setInt("material.diffuse", (GLuint)0);

			glActiveTexture(GL_TEXTURE1);
				crate_spec->bindTexture();
				obj_shaderProgram->setInt("material.specular", (GLuint)1);

			obj_shaderProgram->setFloat("material.shinniness", (GLfloat) 32.0f);

			obj_shaderProgram->setVec3("light.position", lightPos);
			obj_shaderProgram->setVec3("light.ambientLightColor",glm::vec3(0.2f, 0.2f, 0.2f));
			obj_shaderProgram->setVec3("light.diffuseLightColor", glm::vec3(0.7f, 0.7f, 0.7f));
			obj_shaderProgram->setVec3("light.specularLightColor", glm::vec3(1.0f, 1.0f, 1.0f));

			bigSquare->bindVAO();
				glDrawArrays(GL_TRIANGLES, 0, 36);
			bigSquare->unbindVAO();

		obj_shaderProgram->unbindProgram();

		
		glfwSwapBuffers(mainWindow->getWindow());

	}

	mainWindow->~MainWindow();
	return 0;

}