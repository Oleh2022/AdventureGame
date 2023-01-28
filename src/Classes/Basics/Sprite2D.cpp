#include "Sprite2D.h"

Sprite2D::Sprite2D()
{
    vbo_texture_coords.SetVertices(std::vector<float>(8));
}

void Sprite2D::LoadSprite(const char* path, bool flip)
{
    texture.Bind();
    texture.SetParameters();
    texture.LoadTexture(path, flip);
    texture.UnBind();
    sprite_sheet = texture.GetSize();
}

void Sprite2D::SetTextureCoordinates()
{
    vbo_texture_coords.Bind();
    vbo_texture_coords.SetData(GL_DYNAMIC_DRAW);
    vbo_texture_coords.UnBind();
}

void Sprite2D::CalculateTextureCoordinates(const glm::vec2& index, const glm::vec2 &sprite)
{
    vbo_texture_coords.GetVertices()[0] = (index.x * sprite.x) / sprite_sheet.x;
    vbo_texture_coords.GetVertices()[1] = (index.y * sprite.y) / sprite_sheet.y;

    vbo_texture_coords.GetVertices()[2] = (index.x * sprite.x) / sprite_sheet.x;
    vbo_texture_coords.GetVertices()[3] = ((index.y + 1) * sprite.y) / sprite_sheet.y;

    vbo_texture_coords.GetVertices()[4] = ((index.x + 1)  * sprite.x) / sprite_sheet.x;
    vbo_texture_coords.GetVertices()[5] = ((index.y + 1)  * sprite.y) / sprite_sheet.y;

    vbo_texture_coords.GetVertices()[6] = ((index.x + 1) * sprite.x) / sprite_sheet.x;
    vbo_texture_coords.GetVertices()[7] = (index.y * sprite.y) / sprite_sheet.y;

    this->texture.SetSize(sprite);
}