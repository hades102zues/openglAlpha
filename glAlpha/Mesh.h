#pragma once

#include <GL/glew.h>

class Mesh
{
private:
	GLuint vaoID, vboID, attribLocation;
	GLfloat* vertices;
	int span, size,stride;
	void* startingPostion;
	GLenum type;

public:
	Mesh();
	Mesh(GLfloat* vertices, int verticeSize
		      , GLuint location, int span, GLenum type, int stride, void* start);

	void createMesh();
	void bindVAO();
	void unbindVAO();
	void destroyMesh();

	GLuint getVaoID();

	~Mesh();
};

