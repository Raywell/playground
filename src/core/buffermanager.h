#ifndef BufferMANAGER_H
#define BufferMANAGER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class BufferManager
{
public:

private:
    // First phase engine : one VAO + one VBO + one EBO
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
};
#endif
