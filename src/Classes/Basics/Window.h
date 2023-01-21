#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    int width, height;
    GLFWwindow* window;
public:
    Window(const int &Width, const int &Height, const char* Title);
    ~Window();

    inline GLFWwindow* get() { return this->window; }
};