


#include "MainWindow.h"


  void MainWindow:: keyinput_window_handler_cb(GLFWwindow* window, int key, int scancode, int  action, int mods) {

	MainWindow* localWind = static_cast<MainWindow*> (glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE and action == GLFW_PRESS) {
		glfwSetWindowShouldClose(localWind->getWindow(), true);
		return;
	}

	if (key >= 0 && key < 1024) {

		if (action == GLFW_PRESS) {
			localWind->keyPool[key] = true;
		}
		else if (action == GLFW_RELEASE) {
			localWind->keyPool[key] = false;
		}

	}

}

  void MainWindow::mouse_window_handler_cb(GLFWwindow* window, double xpos, double ypos) {

	  MainWindow* localWind = static_cast<MainWindow*> (glfwGetWindowUserPointer(window));

	  if (localWind->mouseFirstClick) {

		  localWind->prevXPos = xpos;
		  localWind->prevYPos = ypos;
		  localWind->mouseFirstClick = false;

	  }


	  localWind->xOffset = xpos - localWind->prevXPos;
	  localWind->yOffset = localWind->prevYPos - ypos ;

	  localWind->prevXPos = xpos;
	  localWind->prevYPos = ypos;


}

void MainWindow::framebuffersize_cb(GLFWwindow* window, int width, int height) {
	 
	MainWindow* localWind = static_cast<MainWindow*> (glfwGetWindowUserPointer(window));

	//we need to reset these in order to keep our projection perspective calculation inline with the new window dimensions
	localWind->buffHeight = height;
	localWind->buffWidth = width;

	 glViewport(0, 0, width, height);
 }


MainWindow::MainWindow() {

	this->winHeight = 800;
	this->winWidth = 600;
	this->mainwindow = nullptr;
	this->title = "default";

	for (int i = 0; i < 1024; i++) {
		this->keyPool[i] = false;
	}

	/*this->prevXPos = 300;
	this->prevYPos = 400;*/
	this->mouseFirstClick = true;

}

MainWindow::MainWindow( GLuint wWidth, GLuint wHeight, const char* title) {

	this->winHeight =wHeight;
	this->winWidth = wWidth;
	this->mainwindow = nullptr;
	this->title = title;

	for (int i = 0; i < 1024; i++) {
		this->keyPool[i] = false;
	}

	/*this->prevXPos = wWidth/2;
	this->prevYPos = wHeight/2;*/
	this->mouseFirstClick = true;
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
	glEnable(GL_DEPTH_TEST);

	glfwSetInputMode(this->mainwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetKeyCallback(this->mainwindow, this->keyinput_window_handler_cb);
	glfwSetCursorPosCallback(this->mainwindow, this->mouse_window_handler_cb);
    glfwSetFramebufferSizeCallback(this->mainwindow, this->framebuffersize_cb);


	return 1;
}


void MainWindow::end() {

	glfwTerminate();
	if (!this->mainwindow) {
		glfwDestroyWindow(this->mainwindow);
	}

}

int MainWindow::getBuffHeight() {

	return this->buffHeight;

}
int MainWindow::getBuffWidth() {

	return this->buffWidth;

}

bool MainWindow::shouldClose() {
	return glfwWindowShouldClose(this->mainwindow);
}

GLFWwindow* MainWindow::getWindow() {
	return this->mainwindow;
}


GLfloat MainWindow::getXOffset() {
	//***GOTCHA*** If we do not reset the values after sending them to the camera then we will get unwanted camera floating!!
	float outX = this->xOffset;
	this->xOffset = 0;
	return  outX;
}

GLfloat MainWindow::getYOffset() {
	//***GOTCHA*** If we do not reset the values after sending them to the camera then we will get unwanted camera floating!!
	float outY = this->yOffset;
	this->yOffset = 0;
	return outY;
}

bool* MainWindow::getKeyPool() {
	return this->keyPool;
}

MainWindow::~MainWindow() {
	this->end();
}