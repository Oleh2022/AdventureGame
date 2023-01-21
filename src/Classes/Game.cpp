#include "Game.h"
#include <iostream>

Game::Game(Window &window_ref)
{
    window_ptr = &window_ref;
    glfwSetWindowIcon(window_ptr->get(), 1, icon.GetImages());
    SetupCharacters();
    this->Render();
}

Game::~Game()
{
    glfwTerminate();
}

void Game::SetupCharacters()
{
}

void Game::Render()
{
    while (!glfwWindowShouldClose(window_ptr->get()))
    {        
        ProcessInput();

        

        AnimationLogic();
        GameLogic();

        glfwSwapBuffers(window_ptr->get());
        glfwPollEvents();
    }
}

void Game::AnimationLogic()
{
}

void Game::GameLogic()
{
    glfwGetCursorPos(window_ptr->get(), &cursor_pos.x, &cursor_pos.y);
}

void Game::ProcessInput()
{
    if(glfwGetKey(window_ptr->get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window_ptr->get(), true);
}