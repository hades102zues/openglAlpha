#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "glm/gtc/type_ptr.hpp"

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

	void setVec2(const char* attribName, glm::vec2 value);
	void setVec3(const char* attribName, glm::vec3 value);
	void setMat4(const char* attribName, glm::mat4 value);

	GLuint getProgramID();
	GLuint getUniformLocation(const GLchar* name);

	
	std::string readFile(const char* path);


	~SProgram();


};

