#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class MainWindow {


private:
	GLint winHeight, winWidth, buffHeight,buffWidth;
	GLFWwindow* mainwindow;

public:
	
	MainWindow();
	void spool();
	~MainWindow();
};
