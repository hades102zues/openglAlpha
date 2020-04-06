#include "Mesh.h"


Mesh::Mesh() {
	std::cout << "Incomplete Mesh created. Please use other overloaded constructor." << std::endl;
}

Mesh::Mesh(
						GLfloat* vertices, int verticeSize
						, GLuint location, int span, GLenum type, int stride, void* start
						, GLuint* indices, int iSize
						, GLuint tex_location, int tex_span, GLenum tex_type, int tex_stride, void* tex_start
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

	this->tex_attribLocation = tex_location;
	this->tex_span = tex_span;
	this->tex_type = tex_type;
	this->tex_stride = tex_stride;
	this->tex_startingPosition = tex_start;

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

	//vertex data
	glVertexAttribPointer(
		this->attribLocation,
		this->span,
		this->type,
		GL_FALSE,
		this->stride,
		this->startingPostion
	);
	glEnableVertexAttribArray(this->attribLocation);

	//texture coords
	glVertexAttribPointer(
		this->tex_attribLocation,
		this->tex_span,
		this->tex_type,
		GL_FALSE,
		this->tex_stride,
		this->tex_startingPosition
	);
	glEnableVertexAttribArray(this->tex_attribLocation);

	
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
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


