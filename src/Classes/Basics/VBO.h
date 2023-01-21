#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <fstream>

class VBO
{
private:
	std::vector<float> vertices;
	unsigned int VertexBuffer;

public:
	VBO();
	~VBO();

	void SetVertices(const char* path);
	void SetVertices(float *array, int capacity);

	void Bind();
	void SetData(GLenum usage);
	void UnBind();
};

