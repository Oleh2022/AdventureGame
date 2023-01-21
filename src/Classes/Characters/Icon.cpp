#include "Icon.h"

Icon::Icon()
{
    icon.Bind();
    icon.SetParameters();
    icon.LoadTexture("data/images/Icon.png", false);
    icon.UnBind();

    images[0].height = icon.GetHeight();
    images[0].pixels = icon.GetPixels();
    images[0].width = icon.GetWidth();
}