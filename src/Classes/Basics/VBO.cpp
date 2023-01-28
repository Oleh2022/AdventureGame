#include "VBO.h"

void VBO::SetVertices(const std::vector<float> &array)
{
	this->vertices = array;
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
}

void VBO::SetData(GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], usage);
}

void VBO::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::VBO()
{
	glGenBuffers(1, &VertexBuffer);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &VertexBuffer);
}