#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


class MainWindow {


private:
	GLuint winHeight, winWidth;
	int buffHeight, buffWidth;
	const char* title;
	GLFWwindow* mainwindow;

public:
	
	MainWindow();
	MainWindow(GLuint wHeight, GLuint wWidth, const char* title);
	int spool();
	int end();
	~MainWindow();
};
