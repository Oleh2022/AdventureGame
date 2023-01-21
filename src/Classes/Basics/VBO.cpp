#include "VBO.h"

void VBO::SetVertices(const char* path)
{
	std::ifstream file(path);
	float number{};

	while (file >> number)
	{
		vertices.push_back(number);
	}
}

void VBO::SetVertices(float *array, int capacity)
{
	for(int i = 0; i < capacity; i++)
	{
		vertices.push_back(array[i]);
	}
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