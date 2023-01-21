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

    int get_width() { return width; }
    int get_height() { return height; }
    inline GLFWwindow* get() { return this->window; }
};