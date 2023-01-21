#pragma once
#include "Entity.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Basics/Texture2D.h"
#include "Basics/Shaders.h"
#include "Basics/VAO.h"

class BackGround : public Entity
{
private:
    Shaders shaders;
    Texture2D texture;
    VAO vao;
public:
    BackGround();
    virtual void SetMatrix() override; 
    virtual void Draw() override;
    void SetProjection(const glm::mat4 &projec) { this->projection = projec; }
};