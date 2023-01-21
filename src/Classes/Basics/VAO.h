#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO
{
private:
	unsigned int ID;

public:
	VAO();
	~VAO();

	void Bind();
	void SetAttrib(unsigned int index, int size, int stride, const void* pointer);
	void UnBind();
};
