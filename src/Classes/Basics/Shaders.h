#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string.h>

class Shaders
{
private:
    unsigned int ID;
public:
    void compile(const char* VertexPath, const char* FragmentPath);
    void Bind() const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;
    void setMatrix(const char* name, glm::mat4 value) const;
};