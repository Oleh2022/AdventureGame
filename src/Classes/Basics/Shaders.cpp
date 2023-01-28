#include "Shaders.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Shaders::compile(const char* VertexPath, const char* FragmentPath)
{
    std::ifstream VertexFile;
    std::ifstream FragmentFile;
    std::stringstream VertexStream, FragmentStream;
    const char* VertexCode;
    const char* FragmentCode;
    std::string TempVertexCode;
    std::string TempFragmentCode;
    
    // ensure ifstream objects can throw exceptions:
    VertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    FragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    //Step 1: Read shader's code from files
    try
    {
        VertexFile.open(VertexPath);
        FragmentFile.open(FragmentPath);
        // read file’s buffer contents into streams
        VertexStream << VertexFile.rdbuf();
        FragmentStream << FragmentFile.rdbuf();
        // close files
        VertexFile.close();
        FragmentFile.close();
        // convert stream into string
        TempVertexCode = VertexStream.str();
        TempFragmentCode = FragmentStream.str();
    }
    catch(std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    VertexCode = TempVertexCode.c_str();
    FragmentCode = TempFragmentCode.c_str();

    //Step 2: Create shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];
    //Vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &VertexCode, NULL);
    glCompileShader(vertex);
    //Error log
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    //FragmentShader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &FragmentCode, NULL);
    glCompileShader(fragment);
    //Error log
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    //Step 3: Create ShaderProgram
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    //Error log
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    // delete shaders; they’re linked into our program and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shaders::Bind() const
{
    glUseProgram(this->ID);
}

void Shaders::setInt(const char* name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name), value);
}
void Shaders::setFloat(const char* name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name), value);
}
void Shaders::setMatrix(const char* name, glm::mat4 value) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
}