#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Renderer
{
private:

public:
    void Clear();
    void Draw(const glm::vec2 &pos, const glm::vec2 &size);
};