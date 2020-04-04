#include "Mesh.h"


Mesh::Mesh() {
	std::cout << "Incomplete Mesh created" << std::endl;
}

Mesh::Mesh( GLfloat* vertices, int verticeSize,
					GLuint location, int span, GLenum type, int stride, void* start, 
					GLuint* indices, int iSize
) {

	this->vertices = vertices; 
	this->size = verticeSize;
	this->attribLocation = location;
	this->span = span;
	this->type = type;
	this->stride = stride;
	this->startingPostion = start;

	this->indices = indices;
	this->indicesSize = iSize;

	this->createMesh();

}

void Mesh::createMesh() {

	glGenVertexArrays(1, &this->vaoID);
	glBindVertexArray(this->vaoID);

	glGenBuffers(1, &this->vboID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices[0]) * this->size, this->vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &this->eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices[0]) * this->indicesSize, this->indices, GL_STATIC_DRAW);

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


