#pragma once 

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Basics/Texture2D.h"
#include "Basics/Shaders.h"
#include "Basics/VAO.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Basics/Transform.h"

class Entity
{
protected:
    Transform transform;
    Shaders shaders;
    VAO vao;
public: 
    virtual void ProcessData() = 0;
    
    virtual Transform& GetTransform() { return this->transform; }
    virtual Shaders& GetShaders() { return this->shaders; }
    virtual VAO& GetVAO() { return this->vao; }

    virtual ~Entity() = default;    
};