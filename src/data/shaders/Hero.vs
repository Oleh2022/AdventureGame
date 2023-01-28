#version 330 core
layout (location = 0) in vec2 position; 
layout (location = 1) in vec2 text_coords;

out vec2 TexCoords;

uniform mat4 transform;

void main()
{
    TexCoords = text_coords;
    gl_Position = transform * vec4(position.xy, 0.0, 1.0);
}