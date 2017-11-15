#include <string>
#include "shadermanager.h"

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager() {
}

void ShaderManager::createProgram() {
    ID = glCreateProgram();
}

void ShaderManager::deleteProgram() {
    glDeleteProgram(ID);
}

void ShaderManager::compileShaders(std::map<ShaderType, std::vector<std::string>> shadersSrc) {
    unsigned int shader;
    std::string shaderType;
    std::vector<std::string> srcList;
    std::vector<unsigned int> usedShaders;

    for (std::map<ShaderType,std::vector<std::string>>::iterator sIt=shadersSrc.begin(); sIt!=shadersSrc.end(); ++sIt) {
        srcList = sIt->second;
        switch (sIt->first) {
            case ShaderType::V:
                shaderType = "VERTEX";
                shader = glCreateShader(GL_VERTEX_SHADER);
            break;
            case ShaderType::F:
                shaderType = "FRAGMENT";
                shader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
            case ShaderType::G:
                shaderType = "GEOMETRY";
                shader = glCreateShader(GL_GEOMETRY_SHADER);
            break;
        }

        std::vector<char*> cstrings;

        for(size_t i = 0; i < srcList.size(); ++i)
            cstrings.push_back(const_cast<char*>(srcList[i].c_str()));

        if(!cstrings.empty()) {
            glShaderSource(shader, cstrings.size(), &cstrings[0], NULL);
            glCompileShader(shader);
            checkCompileErrors(shader, shaderType);
        }

        glAttachShader(ID, shader);
        usedShaders.push_back(shader);
    }

    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    for (auto usedShader : usedShaders) {
        glDetachShader(ID, usedShader);
        glDeleteShader(usedShader);
    }
}

void ShaderManager::use() {
    glUseProgram(ID); 
}
