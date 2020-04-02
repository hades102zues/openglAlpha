#include "Mesh.h"


Mesh::Mesh() {
}

Mesh::Mesh( GLfloat* vertices, int verticeSize, GLuint location, int span, GLenum type, int stride, void* start ) {

	this->vertices = vertices; 
	this->size = verticeSize;
	this->attribLocation = location;
	this->span = span;
	this->type = type;
	this->stride = stride;
	this->startingPostion = start;

	this->createMesh();

}

void Mesh::createMesh() {

	glGenVertexArrays(1, &this->vaoID);
	glBindVertexArray(this->vaoID);
	glGenBuffers(1, &this->vboID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);

	glVertexAttribPointer(
		this->attribLocation,
		this->span,
		this->type,
		GL_FALSE,
		this->stride,
		this->startingPostion
	);
	glEnableVertexAttribArray(this->attribLocation);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Mesh::bindVAO() {
	glBindVertexArray(this->vaoID);
}
void Mesh::unbindVAO() {
	glBindVertexArray(0);
}

void Mesh::destroyMesh() {

}
GLuint Mesh::getVaoID() {
	return this->vaoID;
}

Mesh::~Mesh() {

	this->destroyMesh();

}


