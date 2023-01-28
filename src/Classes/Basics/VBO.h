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

	void SetVertices(const std::vector<float> &array);
	std::vector<float>& GetVertices() { return this->vertices; }

	void Bind();
	void SetData(GLenum usage);
	void UnBind();
};

