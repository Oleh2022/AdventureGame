#include "BackGround.h"
#include "Basics/VBO.h"
#include "Basics/EBO.h"

BackGround::BackGround()
{
    texture.Bind();
    texture.SetParameters();
    texture.LoadTexture("data/images/BackGround.png", false);
    texture.UnBind();

    size.x = texture.GetWidth();
    size.y = texture.GetHeight();

    shaders.compile("data/shaders/BackGround.vs", "data/shaders/BackGround.fs");
    //shaders.use();
    //shaders.setMatrix("projection", projection);

    float vertices[] = { 
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    VBO vbo;
    vao.Bind();
    vbo.Bind();
    vbo.SetVertices(vertices, 24); // redo P.S. why do l need every fuking time to change this capacity number??? Because the developer is a fool:)
    vbo.SetData(GL_STATIC_DRAW);
    vao.SetAttrib(0, 4, 4 * sizeof(float), (void*)0);
    vao.UnBind();
    vbo.UnBind();
}

void BackGround::Draw()
{
	shaders.use();
    SetMatrix();
    texture.BindActivate(0);
	vao.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void BackGround::SetMatrix()
{
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));  
    model = glm::scale(model, glm::vec3(size, 1.0f));
    shaders.setMatrix("model", model);
    shaders.setMatrix("projection", projection);
}