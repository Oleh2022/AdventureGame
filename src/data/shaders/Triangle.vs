#version 330 core
layout (location = 0) in vec3 InputPosition;
layout (location = 1) in vec2 TextureCoord;

out vec2 TexCoord;

void main()
{
    gl_Position = vec4(InputPosition.x, InputPosition.y, InputPosition.z, 1.f);
    TexCoord = TextureCoord;
}