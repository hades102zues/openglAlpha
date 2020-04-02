/*
	To-Do:
		.Register a viewport resize callback
		.Setup a key handler callback

*/


#include "MainWindow.h"


MainWindow::MainWindow() {
	this->winHeight = 800;
	this->winWidth = 600;
	this->mainwindow = nullptr;
	this->title = "default";
}

MainWindow::MainWindow( GLuint wWidth, GLuint wHeight, const char* title) {
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
	


	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("Glew failed initialization.");
		this->~MainWindow();
		return -1;
	}

	glViewport(0, 0, this->buffWidth, this->buffHeight);
	glEnable(GL_DEPTH);

	glfwSetFramebufferSizeCallback(this->mainwindow, this->framebuffer_size_cb);



	return 1;
}


void MainWindow::end() {

	glfwTerminate();
	if (!this->mainwindow) {
		glfwDestroyWindow(this->mainwindow);
	}

}

bool MainWindow::shouldClose() {
	return glfwWindowShouldClose(this->mainwindow);
}

GLFWwindow* MainWindow::getWindow() {
	return this->mainwindow;
}

void framebuffer_size_cb(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

MainWindow::~MainWindow() {
	this->end();
}