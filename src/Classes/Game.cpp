#include "Game.h"

BackGround* background;

glm::vec2 LastPixel;
bool FirstPixel = true;
glm::vec2 zoom(1.92, 1.08);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if ((float)yoffset > 0.f) 
    { 
        zoom.x -= 3.84; 
        zoom.y -= 2.16; 
    }
    else 
    { 
        zoom.x += 3.84; 
        zoom.y += 2.16; 
    }

    if (zoom.x < -384.f) zoom.x = -384.f;
    else if (zoom.x > 384.f) zoom.x = 384.f;

    if (zoom.y < -216.f) zoom.y = -216.f;
    else if (zoom.y > 216.f) zoom.y = 216.f;

    background->SetProjection(glm::ortho(0.f - zoom.x, 1920.f + zoom.x, 1080.f + zoom.y, 0.f - zoom.y, -1.f, 1.f));
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);
        if (FirstPixel == true)
        {
            LastPixel.x = xpos;
            LastPixel.y = ypos;
            FirstPixel = false;
        }
        glm::vec2 direction(xpos - LastPixel.x, ypos - LastPixel.y);
        LastPixel.x = xpos;
        LastPixel.y = ypos;
        background->AddToPosition(direction);
    }
    else
    {
        FirstPixel = true;
    }
}

Game::Game(Window &window_ref)
{
    window_ptr = &window_ref;
    glfwSetWindowIcon(window_ptr->get(), 1, icon.GetImages());
    SetupCharacters();
    glfwSetScrollCallback(window_ptr->get(), scroll_callback);
    glfwSetCursorPosCallback(window_ptr->get(), mouse_callback);

    this->Render();
}

void Game::SetupCharacters()
{
    background = new BackGround;
    LastPixel = glm::vec2(window_ptr->get_width() / 2.f, window_ptr->get_height() / 2.f);
}

Game::~Game()
{   
    delete background;
    glfwTerminate();
}



void Game::Render()
{
    while (!glfwWindowShouldClose(window_ptr->get()))
    {        
        ProcessInput();

        glfwGetCursorPos(window_ptr->get(), &cursor_pos.x, &cursor_pos.y);

        renderer.Clear();
        background->Draw();
        renderer.Display(window_ptr->get());
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
    if (glfwGetKey(window_ptr->get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window_ptr->get(), true);
}