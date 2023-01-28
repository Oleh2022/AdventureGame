#include "Window.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(const int &Width, const int &Height, const char* Title)
{
    window = glfwCreateWindow(Width, Height, Title, glfwGetPrimaryMonitor(), NULL);
    if(window == nullptr)
    {
        std::cerr << "Failed to create window!" << std::endl;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    this->width = Width;
    this->height = Height;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}
