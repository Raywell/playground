#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <list>
#include <string>

class Mesh
{
public:
    explicit Mesh(std::string name);

    virtual ~Mesh() { destroy(); };
    void release() { delete this; }

    void updateSelf();

protected:
    std::string name;
    GLuint VBO;
    GLuint IBO;
//    InputLayout layout;
//    Material mat;
    size_t startIndex;
    size_t numIndices;

private:
    void destroy() { }
};

#endif
