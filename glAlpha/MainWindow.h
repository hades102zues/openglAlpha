#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>




class MainWindow {


private:
	GLuint winHeight, winWidth;
	int buffHeight, buffWidth;
	GLFWwindow* mainwindow;
	const char* title;

	

public:

	bool keyPool[1024];

	GLfloat prevXPos, prevYPos;
	GLfloat xOffset, yOffset;
	bool mouseFirstClick;
	

	static void  keyinput_window_handler_cb(GLFWwindow* window, int key, int scancode, int  action, int mods);
	static void mouse_window_handler_cb(GLFWwindow* window, double xpos, double ypos);
	static void framebuffersize_cb(GLFWwindow* window, int width, int height);

	MainWindow();
	MainWindow(GLuint wWidth, GLuint wHeight, const char* title);
	~MainWindow();

	int spool();
	void end();
	int getBuffHeight();
	int getBuffWidth();
	bool shouldClose();
	GLfloat getXOffset();
	GLfloat getYOffset();
	bool* getKeyPool();

	GLFWwindow* getWindow();

	
};
