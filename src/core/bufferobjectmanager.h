#ifndef BUFFEROBJECTMANAGER_H
#define BUFFEROBJECTMANAGER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <ireleasable.h>
#include <ibufferobject.h>

class BufferObjectManager : public IReleasable
{
public:
    explicit BufferObjectManager();
    void init();
    void buffer(IBufferObject *object);

private:
    // First phase engine : one VAO + one VBO + one EBO
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
};
#endif
