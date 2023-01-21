#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Basics/Texture2D.h"

class Icon
{
private:
    Texture2D icon;
    GLFWimage images[1];
public:
    Icon();
    GLFWimage* GetImages() { return this->images; } 
};