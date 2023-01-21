#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Basics/Window.h"
#include "Characters/Icon.h"

class Game
{
private:
    Window* window_ptr;
    Icon icon;

    glm::dvec2 cursor_pos;
public:
    Game(Window &window_ptr);
    ~Game();
    void Render();
    void ProcessInput();
    void SetupCharacters();
    void AnimationLogic();
    void GameLogic();
};