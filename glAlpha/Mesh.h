#pragma once

#include <GL/glew.h>
#include <iostream>

class Mesh
{
private:
	GLuint vaoID;
	GLuint vboID;
	GLuint eboID;

	//Vertex Specific
	GLfloat* vertices;
	GLuint	 attribLocation;
	int span, size, stride;
	void* startingPostion;
	GLenum type;

	//indices specific
	GLuint* indices;
	int indicesSize;

public:
	Mesh();
	Mesh(GLfloat* vertices, int verticeSize
		      , GLuint location, int span, GLenum type, int stride, void* start
			  , GLuint * indices, int iSize
	);

	void createMesh();
	void bindVAO();
	void unbindVAO();
	void destroyMesh();

	GLuint getVaoID();

	~Mesh();
};

