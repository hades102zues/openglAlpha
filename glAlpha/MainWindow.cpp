/*
	To-Do:
		.Setup a key handler callback

*/


#include "MainWindow.h"


  void MainWindow:: keyinput_window_handler_cb(GLFWwindow* window, int key, int scancode, int  action, int mods) {

	MainWindow* localWind = static_cast<MainWindow*> (glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE and action == GLFW_PRESS) {
		glfwSetWindowShouldClose(localWind->getWindow(), true);
	}
}

void MainWindow::framebuffersize_cb(GLFWwindow* window, int width, int height) {
	  glViewport(0, 0, width, height);
 }


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

	glfwSetWindowUserPointer(this->mainwindow, this);

	glViewport(0, 0, this->buffWidth, this->buffHeight);
	glEnable(GL_DEPTH);

	glfwSetKeyCallback(this->mainwindow, this->keyinput_window_handler_cb);
    glfwSetFramebufferSizeCallback(this->mainwindow, this->framebuffersize_cb);



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



MainWindow::~MainWindow() {
	this->end();
}