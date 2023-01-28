#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Basics/EBO.h"
#include "Basics/VAO.h"
#include "Basics/Shaders.h"
#include "Basics/Texture2D.h"
#include "Basics/Sprite2D.h"

class Renderer
{
private:

public:
    void StartRendering();
    void EndRendering(GLFWwindow* window);
    void Draw(const VAO &vao, const Shaders &shaders, const unsigned int &count) const;
    void Draw(const VAO &vao, const Shaders &shaders, const EBO &ebo, const unsigned int &count) const;
    void Draw(const VAO &vao, const Shaders &shaders, const Texture2D &texture, const unsigned int &count) const;
    void Draw(const VAO &vao, const Shaders &shaders, const Texture2D &texture, const EBO &ebo, const unsigned int &count) const;

    void Draw(const VAO &vao, const Shaders &shaders, const Sprite2D &sprite, const unsigned int &count) const;
    void Draw(const VAO &vao, const Shaders &shaders, const Sprite2D &sprite, const EBO &ebo, const unsigned int &count) const;

};