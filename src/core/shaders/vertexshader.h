#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H

#include "shader.h"

class VertexShader : public Shader
{
public:
    static const char* getSource() {
        const char* source = R"vshader(
####################################################################################
#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
####################################################################################
)vshader";
        return source;
    }
};

#endif

