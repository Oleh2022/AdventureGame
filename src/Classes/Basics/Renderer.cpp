#include "Renderer.h"

void Renderer::StartRendering()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.f, 0.2f, 0.3f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::EndRendering(GLFWwindow* window)
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Renderer::Draw(const VAO &vao, const Shaders &shaders, const unsigned int &count) const
{
	shaders.Bind();
	vao.Bind();
	glDrawArrays(GL_TRIANGLES, 0, count);
}

void Renderer::Draw(const VAO &vao, const Shaders &shaders, const Texture2D &texture, const unsigned int &count) const
{	
	shaders.Bind();
	texture.Bind();
	vao.Bind();
	glDrawArrays(GL_TRIANGLES, 0, count);
}

void Renderer::Draw(const VAO &vao, const Shaders &shaders, const EBO &ebo, const unsigned int &count) const
{
	shaders.Bind();
	vao.Bind();
	ebo.Bind();
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

void Renderer::Draw(const VAO &vao, const Shaders &shaders, const Texture2D &texture, const EBO &ebo, const unsigned int &count) const 
{
	shaders.Bind();
	texture.Bind();
	vao.Bind();
	ebo.Bind();
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

void Renderer::Draw(const VAO &vao, const Shaders &shaders, const Sprite2D &sprite, const unsigned int &count) const
{
	shaders.Bind();
	sprite.BindTexture();
	vao.Bind();
	glDrawArrays(GL_TRIANGLES, 0, count);
}

void Renderer::Draw(const VAO &vao, const Shaders &shaders, const Sprite2D &sprite, const EBO &ebo, const unsigned int &count) const
{
	shaders.Bind();
	sprite.BindTexture();
	vao.Bind();
	ebo.Bind();
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}