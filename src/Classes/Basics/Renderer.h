#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
private:

public:
    void Clear();
    void Display(GLFWwindow* window);
};