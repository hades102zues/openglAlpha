#define STB_IMAGE_IMPLEMENTATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>



#include "MainWindow.h"
#include "SProgram.h"
#include "Mesh.h"
#include "Texture.h"



int main() {

	MainWindow* mainWindow = new MainWindow(800, 600, "jak");
	if (mainWindow->spool() != 1) {
		return -1;
	}

	GLfloat vertices[] = {
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

	//**GOTCHA**__remember to update the size, stride and starting position values as you change the arrays!!!
	Mesh* mesh = new Mesh(
		vertices, 20, 
		0, 3, GL_FLOAT, sizeof(vertices[0]) * 5, (void*)0, //vertex attribs
		indices, 6,
		2, 2, GL_FLOAT, sizeof(vertices[0]) * 5, (void*)(sizeof(vertices[0]) * 3) //text coord attribs
	);

	//texture here 
	Texture* container = new Texture("./container.jpg");

	const char* vPath = "./shaders/shader.vertex";
	const char* fPath = "./shaders/shader.fragment";

	SProgram* shaderProgram = new SProgram(vPath, fPath);


	while (!mainWindow->shouldClose()) {

		//screenn clearing
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//drawing operations
	    shaderProgram->bindProgram();
		container->bindTexture();
		mesh->bindVAO();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //provides info about the indices array

	  //shaderProgram->unbindProgram();

	  container->unbindTexture();
	  mesh->unbindVAO();


		glfwPollEvents();
		glfwSwapBuffers(mainWindow->getWindow());

	}

	mainWindow->~MainWindow();
	return 0;

}