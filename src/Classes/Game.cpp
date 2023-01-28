#include "Game.h"
#include "Characters/Hero.h"
#include <math.h>

#include <iostream>

#include "Globals.h"

Globals* globals;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if ((float)yoffset > 0.f) 
    {
        globals->screen_zoom -= globals->step;
        // float step_x = /* (background->GetPosition().x - */ cursor_pos.x / (screen_zoom / step);
        // float step_y = /* (background->GetPosition().y - */ cursor_pos.y / (screen_zoom / step);
        // background->AddToPosition(glm::vec2(step_x, step_y));  
    }
    else
    { 
        globals->screen_zoom += globals->step;
        if (globals->screen_zoom >= -80.f && globals->screen_zoom <= 0.f)
        {        
            float step_x = globals->background->GetTransform().GetPosition().x / (globals->screen_zoom / globals->step);
            float step_y = globals->background->GetTransform().GetPosition().y / (globals->screen_zoom / globals->step);

            if (globals->screen_zoom > -1.f && globals->screen_zoom < 1.f)
            {
                globals->background->GetTransform().SetPosition(glm::vec2(0.f, 0.f));
                globals->hero->GetTransform().SetPosition(glm::vec2(0.f, 0.f));
            }
            else
            {
                globals->background->GetTransform().AddToPosition(glm::vec2(step_x, step_y));
                globals->hero->GetTransform().AddToPosition(glm::vec2(step_x, step_y));
            }
        }
    }

    if (globals->screen_zoom >= -80.f && globals->screen_zoom <= 0.f)
    {
        int pers_in_pix_x = (globals->window->get_width() * globals->screen_zoom) / 100.f;
        int pers_in_pix_y = (globals->window->get_height() * globals->screen_zoom) / 100.f;

        globals->screen.x = (pers_in_pix_x / 2);
        globals->screen.y = (pers_in_pix_y / 2);

        globals->background->GetTransform().SetProjection(glm::ortho(0.f - globals->screen.x, globals->window->get_width() + globals->screen.x, globals->window->get_height() + globals->screen.y, 0.f - globals->screen.y, -1.f, 1.f));
        globals->hero->GetTransform().SetProjection(glm::ortho(0.f - globals->screen.x, globals->window->get_width() + globals->screen.x, globals->window->get_height() + globals->screen.y, 0.f - globals->screen.y, -1.f, 1.f));
    }
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);
        if (globals->FirstPixel == true)
        {
            globals->LastPixel.x = xpos;
            globals->LastPixel.y = ypos;
            globals->FirstPixel = false;
        }
        glm::vec2 direction(xpos - globals->LastPixel.x, ypos - globals->LastPixel.y);
        globals->LastPixel.x = xpos;
        globals->LastPixel.y = ypos;

        glm::vec2 position(globals->background->GetTransform().GetPosition().x, globals->background->GetTransform().GetPosition().y);

        if (position.x + direction.x < globals->screen.x) direction.x = 0.f;
        else if (position.x + direction.x > -globals->screen.x) direction.x = 0.f;

        if (position.y + direction.y < globals->screen.y) direction.y = 0.f;
        else if (position.y + direction.y > -globals->screen.y) direction.y = 0.f; 

        globals->background->GetTransform().AddToPosition(direction / fabs(globals->screen_zoom / 18.f));
        globals->hero->GetTransform().AddToPosition(direction / fabs(globals->screen_zoom / 18.f));
    }
    else
    {
        globals->FirstPixel = true;
    }
}

Game::Game(Window &window_ref)
{
    globals = new Globals(window_ref);
    glfwSetWindowIcon(globals->window->get(), 1, icon.GetImages());
    glfwSetScrollCallback(globals->window->get(), scroll_callback);
    glfwSetCursorPosCallback(globals->window->get(), mouse_callback);

    this->DoOnce();
    this->GameLoop();
}

Game::~Game()
{   
    glfwTerminate();
}

void Game::GameLoop()
{
    while (!glfwWindowShouldClose(globals->window->get()))
    {        
        ProcessInput();
        EveryTick();

        renderer.StartRendering();
        renderer.Draw(globals->background->GetVAO(), globals->background->GetShaders(), globals->background->GetTexture(), 6);
        renderer.Draw(globals->hero->GetVAO(), globals->hero->GetShaders(), globals->hero->GetSprite(), globals->hero->GetEBO(), 6);
        renderer.EndRendering(globals->window->get());
    }
}

void Game::EveryTick()
{
    globals->background->ProcessData();
    globals->hero->ProcessData();

    glfwGetCursorPos(globals->window->get(), &globals->cursor_pos.x, &globals->cursor_pos.y); 
}

void Game::DoOnce()
{
    globals->LastPixel = glm::vec2(globals->window->get_width() / 2.f, globals->window->get_height() / 2.f);
    globals->background->GetTransform().CalculateProjection(globals->window->get_width(), globals->window->get_height());
    globals->hero->GetTransform().CalculateProjection(globals->window->get_width(), globals->window->get_height());
}

void Game::ProcessInput()
{
    if (glfwGetKey(globals->window->get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(globals->window->get(), true);

    if (glfwGetMouseButton(globals->window->get(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        globals->hero->MoveTo(globals->cursor_pos);
}