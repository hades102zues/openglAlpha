#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <GL/glew.h>

class SProgram
{

private:			
	GLuint sprogram;
	const char* vStruct;
	const char* fStruct;

public:
	SProgram();
	SProgram(const char* vertexShaderPath, const char* fragmentShaderPath);

	void compileShader(const char* lines, GLenum type);
	void linkShaders();
	void bindProgram();
	void unbindProgram();

	GLuint getProgramID();
	std::string readFile(const char* path);


	~SProgram();


};

