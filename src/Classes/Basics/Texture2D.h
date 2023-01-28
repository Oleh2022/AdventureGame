#pragma once 
#include <glm/glm.hpp>

class Texture2D
{
private:
    unsigned int ID;
    unsigned char* data;
    int width, height, nrChannels;
    // int currentbind; // Current max binded texture
    
public:
    Texture2D();
    ~Texture2D();

    void BindActivate(int TextureUnit) const;
    void Bind() const;
    void UnBind() const;

    void SetParameters();
    void LoadTexture(const char* path,  bool flip = true);

    int GetHeight() { return this->height; };
    int GetWidth() { return this->width; };
    glm::vec2 GetSize() { return glm::vec2(width, height); }
    void SetSize(const glm::vec2 &size) { this->width = size.x; this->height = size.y; }
    unsigned char* GetPixels() { return this->data; };

    // float* Calculate_Texture_Vertices(); // For future...
};