#include "Globals.h"

Globals::Globals(Window &window_ref)
{
    background = new BackGround;
    window = &window_ref;
    hero = new Hero;
}

Globals::~Globals()
{
    delete hero;
    delete background;
}