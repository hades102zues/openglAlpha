/*
	To-Do:
		.Register a viewport resize callback
		.Settup the window screen clearing
		.

*/


#include "MainWindow.h"


MainWindow::MainWindow() {
	this->winHeight = 800;
	this->winWidth = 600;
	this->mainwindow = nullptr;
	this->title = "default";
}

MainWindow::MainWindow(GLuint wHeight, GLuint wWidth, const char* title) {
	this->winHeight =wHeight;
	this->winWidth = wWidth;
	this->mainwindow = nullptr;
	this->title = title;
}


int MainWindow::spool() {

	if (!glfwInit()) {

		printf("glfw failed intialization");
		this->~MainWindow();
		return -1;
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	this->mainwindow = glfwCreateWindow(this->winWidth, this->winHeight, this->title, NULL, NULL);
	if (! this->mainwindow) {

		printf("glfw window failed creation");
		this->~MainWindow();
		return -1;

	}

	glfwGetFramebufferSize(this->mainwindow, &(this->buffWidth), &(this->buffHeight));
	glfwMakeContextCurrent(this->mainwindow);
	glViewport(0, 0, this->buffWidth, this->buffHeight);


	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("Glew failed initialization.");
		this->~MainWindow();
		return -1;
	}

	while (glfwWindowShouldClose(this->mainwindow)) {

		glfwPollEvents();


		//drawing operations



		//screenn clearing

		glfwSwapBuffers(this->mainwindow);


	}


}


int MainWindow::end() {

	glfwTerminate();
	if (!this->mainwindow) {
		glfwDestroyWindow(this->mainwindow);
	}

	
}

MainWindow::~MainWindow() {
	this->end();
}