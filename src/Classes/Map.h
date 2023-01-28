#pragma once
// #define STB_IMAGE_IMPLEMENTATION
// #include <stb_image/stb_image.h>
#include <vector>

class Map
{
private:
    int width = 1920, height = 1080;
    std::vector<unsigned char*> blocks;
public:
    Map();
};