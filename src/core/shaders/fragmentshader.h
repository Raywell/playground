#ifndef FRAGMENTSHADER_H
#define FRAGMENTSHADER_H

#include "shader.h"

class FragmentShader : public Shader
{
public:
    static const char* getSource() {
        const char* source = R"fshader(
####################################################################################
#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
} 
####################################################################################
)fshader";
        return source;
    }
};

#endif

