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

	//texture specifics
	GLuint tex_attribLocation;
	int tex_span;
	GLenum tex_type;
	int tex_stride;
	void* tex_startingPosition;

	
public:
	Mesh();
	
	Mesh(GLfloat* vertices, int verticeSize
		      , GLuint location, int span, GLenum type, int stride, void* start
			  , GLuint * indices, int iSize
			  ,GLuint tex_location, int tex_span, GLenum tex_type, int tex_stride, void* tex_start
	);

	void createMesh();
	void bindVAO();
	void unbindVAO();
	void destroyMesh();

	GLuint getVaoID();

	~Mesh();
};

