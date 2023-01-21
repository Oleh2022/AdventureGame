#pragma once 

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Basics/Texture2D.h"
#include "Basics/Shaders.h"
#include "Basics/VAO.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Entity
{
protected:
    Texture2D texture;
    Shaders shaders;
    VAO vao;

    glm::vec2 size = glm::vec2(0.f, 0.f);
    glm::vec2 position = glm::vec2(0.f, 0.f);
    glm::mat4 projection = glm::ortho(0.f, 1920.f, 1080.f, 0.f, -1.f, 1.f);
    glm::mat4 model = glm::mat4(1.f);
public: 
    virtual void SetPosition(const glm::vec2 &pos) { this->position = pos; }
    virtual void AddToPosition(const glm::vec2 &pos) { this->position += pos; }
    virtual void SetSize(const glm::vec2 &size_) { this->size = size_; }
    virtual void AddToSize(const glm::vec2 &size_) { this->size += size_; }

    virtual void SetMatrix() = 0;    
    virtual glm::vec2 GetPosition() { return this->position; }
    virtual void Draw() = 0;
    virtual ~Entity() = default;
};