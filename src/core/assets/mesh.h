#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

#include "asset.h"

class Mesh : public Asset, public IBufferObject
{
public:
    explicit Mesh(std::string name);
    virtual ~Mesh() {};

    void load();
    void unload();

    std::vector<float> getVertices() { return vertices; }
    void setVertices(std::vector<float> _vertices) { vertices = _vertices; }

    std::vector<GLuint> getIndices() { return indices; }
    void setIndices(std::vector<GLuint> _indices) { indices = _indices; }

protected:
    std::string name;
//    InputLayout layout;
//    Material mat;
    size_t startIndex;
    size_t numIndices;

    std::vector<float> vertices;
    std::vector<GLuint> indices;

private:
    void destroy() {}
};

#endif
