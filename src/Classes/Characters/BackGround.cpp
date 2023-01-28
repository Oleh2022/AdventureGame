#include "BackGround.h"
#include <vector>

BackGround::BackGround()
{
    texture.Bind();
    texture.SetParameters();
    texture.LoadTexture("data/images/BackGroundAdventure.png", false);
    texture.UnBind();

    shaders.compile("data/shaders/BackGround.vs", "data/shaders/BackGround.fs");

    transform.SetSize(texture.GetSize());
    transform.SetPosition(glm::vec2(0.f, 0.f));

    std::vector<float> vert = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    vao.Bind();
    vbo.Bind();
    vbo.SetVertices(vert);
    vbo.SetData(GL_STATIC_DRAW);
    vao.SetAttrib(0, 4, 4 * sizeof(float), (void*)0);
    vao.UnBind();
    vbo.UnBind();
}

void BackGround::ProcessData()
{
    shaders.Bind();
    shaders.setMatrix("transform", transform.GetTransform());
}
