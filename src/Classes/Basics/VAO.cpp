#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::Bind() const 
{
	glBindVertexArray(ID);
}

void VAO::SetAttrib(unsigned int index, int size, int stride, const void* pointer)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
}

void VAO::UnBind() const
{
	glBindVertexArray(0);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &ID);
}