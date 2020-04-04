#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "MainWindow.h"
#include "SProgram.h"
#include "Mesh.h"



int main() {

	MainWindow* mainWindow = new MainWindow(800, 600, "jak");
	if (mainWindow->spool() != 1) {
		return -1;
	}

	GLfloat vertices[] = {
		-0.5f, -1.0f, 0.0f,
		0.5f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	Mesh* mesh = new Mesh(vertices, 9, 0, 3, GL_FLOAT, sizeof(vertices[0]) * 3, (void*) 0);

	const char* vPath = "./shaders/shader.vertex";
	const char* fPath = "./shaders/shader.fragment";

	SProgram* shaderProgram = new SProgram(vPath, fPath);


	while (!mainWindow->shouldClose()) {

		//screenn clearing
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//drawing operations
		//shaderProgram->bindProgram();
		//mesh->bindVAO();
		glUseProgram(shaderProgram->getProgramID());
		glBindVertexArray(mesh->getVaoID());
		glDrawArrays(GL_TRIANGLES, 0, 3);

	/*	shaderProgram->unbindProgram();
		mesh->unbindVAO();*/


		glfwPollEvents();
		glfwSwapBuffers(mainWindow->getWindow());

	}

	mainWindow->~MainWindow();
	return 0;

}