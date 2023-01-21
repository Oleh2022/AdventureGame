#pragma once
#include <glad/glad.h>

class EBO
{
private:
	unsigned int ID;
public:
	EBO();
	~EBO();

	void Bind();
	void SetData(int size, unsigned int *data, GLenum usage);
	void UnBind();
};
