#include "Renderer.h"

void Renderer::Clear()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Display(GLFWwindow* window)
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}