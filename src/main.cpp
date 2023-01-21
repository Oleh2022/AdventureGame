#include "Game.h"
#include "Basics/Window.h"
#include "CallBack.h"

int main()
{
    My_GLFW_Init();
    Window window(1920, 1080, "Hero&Soldiers");
    My_GLAD_Init();
    Game game(window);

    return 0;
}