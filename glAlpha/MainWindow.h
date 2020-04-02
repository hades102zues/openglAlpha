#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class MainWindow {


private:
	GLint height, width;

public:
	
	MainWindow();
	void spool();
	~MainWindow();
};
