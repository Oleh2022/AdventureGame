#pragma once
#include "Basics/Window.h"
#include "Characters/BackGround.h"
#include "Characters/Hero.h"
#include "glm/glm.hpp"

class Globals
{
private:

public:
    BackGround* background;
    Window* window;
    Hero* hero;    

    glm::dvec2 cursor_pos;

    glm::vec2 LastPixel;
    bool FirstPixel = true;

    glm::vec2 screen = glm::vec2(0.f, 0.f);
    float screen_zoom;

    float step = 6.4f;
    
    Globals(Window &window_ref);
    ~Globals(); 
};