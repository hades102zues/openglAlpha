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
	MainWindow(GLuint wWidth, GLuint wHeight, const char* title);
	int spool();
	void end();
	bool shouldClose();
	GLFWwindow* getWindow();
	~MainWindow();
};
