#pragma once
#include "Characters/Entity.h"
#include "Basics/Texture2D.h"
#include "Basics/Shaders.h"
#include "Basics/VBO.h"
#include "Basics/EBO.h"
#include "Basics/Sprite2D.h"

#include "Basics/Characteristics.h"

#include <vector>

class Hero : public Entity, Characteristics
{
private:
    Sprite2D sprite;
    VBO vbo_pos;
    EBO ebo;
    glm::vec2 target_point;

    void Move();
public:
    Hero();
    virtual void ProcessData() override;
    EBO& GetEBO() { return this->ebo; }
    Sprite2D& GetSprite() { return this->sprite; }

    void Animation();
    void MoveTo(const glm::vec2 &target);
};