#include "Mesh.h"


Mesh::Mesh() {
	std::cout << "Incomplete Mesh created. Please use other overloaded constructor." << std::endl;
}

Mesh::Mesh(
						GLfloat* vertices, int verticeSize
						, GLuint location, int span, GLenum type, int stride, void* start
						, GLuint* indices, int iSize
						, GLuint tex_location, int tex_span, GLenum tex_type, int tex_stride, void* tex_start
						, GLuint norm_location, int norm_span, GLenum norm_type, int norm_stride, void* norm_start
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

	this->norm_location = norm_location;
	this->norm_span = norm_span;
	this->norm_type = norm_type;
	this->norm_stride = norm_stride;
	this->norm_start = norm_start;

	this->createMesh();

}

void Mesh::createMesh() {

	glGenVertexArrays(1, &this->vaoID);
	glBindVertexArray(this->vaoID);

	glGenBuffers(1, &this->vboID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices[0]) * this->size, this->vertices, GL_STATIC_DRAW);

	if (this->indices != nullptr) {

		glGenBuffers(1, &this->eboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices[0]) * this->indicesSize, this->indices, GL_STATIC_DRAW);

	}
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

	//normals
	glVertexAttribPointer(
		this->norm_location,
		this->norm_span,
		this->norm_type,
		GL_FALSE,
		this->norm_stride,
		this->norm_start
	);
	glEnableVertexAttribArray(this->norm_location);

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


