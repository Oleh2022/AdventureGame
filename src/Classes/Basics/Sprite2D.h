#pragma once

#include "Basics/Texture2D.h"
#include "Basics/VBO.h"

#include <glm/glm.hpp>

class Sprite2D
{
private:
    Texture2D texture;
    VBO vbo_texture_coords;
    glm::vec2 sprite_sheet;
public:
    Sprite2D();
    void LoadSprite(const char* path, bool flip = true);
    void SetTextureCoordinates();
    void CalculateTextureCoordinates(const glm::vec2 &index, const glm::vec2 &sprite);

    void BindTexture() const { this->texture.Bind(); }
    void UnBindTexture() const { this->texture.UnBind(); }

    VBO& GetVBO() { return vbo_texture_coords; }
    Texture2D& GetTexture() { return texture; }
};

