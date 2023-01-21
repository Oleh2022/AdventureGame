#pragma once 

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

    void BindActivate(int TextureUnit);
    void Bind();
    void UnBind();

    void SetParameters();
    void LoadTexture(const char* path,  bool flip = true);

    int GetHeight() { return this->height; };
    int GetWidth() { return this->width; };
    unsigned char* GetPixels() { return this->data; };

    float* Calculate_Texture_Vertices(); // For future...
};