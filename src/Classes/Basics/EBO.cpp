#include "EBO.h"

EBO::EBO()
{
    glGenBuffers(1, &ID);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &ID);
}

void EBO::Bind() const 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void EBO::SetData(int size, unsigned int *data, GLenum usage)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
}

void EBO::UnBind() const 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}