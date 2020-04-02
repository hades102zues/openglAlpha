#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "MainWindow.h"

int main() {

	MainWindow* mainWindow = new MainWindow(800, 600, "jak");
	if (mainWindow->spool() != 1) {
		return -1;
	}


	while (!mainWindow->shouldClose()) {

		//screenn clearing
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//drawing operations





		glfwPollEvents();
		glfwSwapBuffers(mainWindow->getWindow());

	}

	mainWindow->~MainWindow();
	return 0;

}