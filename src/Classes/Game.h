#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Basics/Window.h"
#include "Basics/Renderer.h"

#include "Characters/Icon.h"
#include "Characters/BackGround.h"

class Game
{
private:
    Icon icon;
    Renderer renderer;

public:
    Game(Window &window_ptr);
    ~Game();
    void GameLoop();
    void ProcessInput();
    void EveryTick();
    void DoOnce();
};
