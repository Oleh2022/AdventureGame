#pragma once
#include "Entity.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Basics/Texture2D.h"
#include "Basics/VBO.h"
#include "Basics/EBO.h"

class BackGround : public Entity
{
private:
    Texture2D texture;
    VBO vbo;
public:
    BackGround();
    virtual void ProcessData() override;
    Texture2D& GetTexture() { return this->texture; }
};