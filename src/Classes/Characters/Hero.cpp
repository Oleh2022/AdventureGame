#include "Hero.h"
#include "Basics/EBO.h"

Hero::Hero()
{
    sprite.LoadSprite("data/Hero/AxemanLime.png", false);

    shaders.compile("data/shaders/Hero.vs", "data/shaders/Hero.fs");

    transform.SetSize(sprite.GetTexture().GetSize());
    transform.SetPosition(glm::vec2(0.f, 0.f));

    speed = 5.f;

    std::vector<float> positions = { 
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0
    };

    vao.Bind();
 
    ebo.Bind();
    ebo.SetData(indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    vbo_pos.Bind();
    vbo_pos.SetVertices(positions); 
    vbo_pos.SetData(GL_STATIC_DRAW);
    vao.SetAttrib(0, 2, 2 * sizeof(float), (void*)0);
    
    sprite.GetVBO().Bind();
    sprite.GetVBO().SetData(GL_DYNAMIC_DRAW);
    vao.SetAttrib(1, 2, 2 * sizeof(float), (void*)0);

    vao.UnBind();
    ebo.UnBind();
    vbo_pos.UnBind();
    sprite.GetVBO().UnBind();
}

void Hero::ProcessData()
{
    shaders.Bind();
    shaders.setMatrix("transform", transform.GetTransform());

    sprite.CalculateTextureCoordinates(glm::vec2(0.f, 0.f), glm::vec2(16.f, 16.f));
    sprite.SetTextureCoordinates();

    Move();

    transform.SetSize(sprite.GetTexture().GetSize());
}

void Hero::Animation()
{

}

void Hero::MoveTo(const glm::vec2 &target)
{
    target_point = target;
}

void Hero::Move()
{
    if (target_point.x <= transform.GetPosition().x + 2 && target_point.x >= transform.GetPosition().x - 2 && target_point.y <= transform.GetPosition().y + 2 && target_point.y >= transform.GetPosition().y - 2)
    {
        target_point = transform.GetPosition();
    }
    else  
    {
        float deltaX = target_point.x - transform.GetPosition().x;
        float deltaY = target_point.y - transform.GetPosition().y;
        float angle = glm::atan(deltaY, deltaX);
        transform.AddToPosition(glm::vec2(speed * glm::cos(angle), speed * glm::sin(angle)));
    }  
}