#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

#include "asset.h"
#include <ibufferobject.h>

enum class MeshType {
    STATIC
};

class Mesh : public Asset, public IBufferObject
{
public:
    explicit Mesh(std::string name);
    virtual ~Mesh() {};

    void load();
    void unload();

    std::vector<float> getVertices() { return vertices; }
    std::vector<GLuint> getIndices() { return indices; }

    void setVertices(std::vector<float> _vertices);
    void setIndices(std::vector<GLuint> _indices);

    MeshType getMeshType() { return mesh_type; }
    void setMeshType(MeshType _type) { mesh_type = _type; }

    BufferObjectType getBufferObjectType();
    
protected:
    std::string name;
//    InputLayout layout;
//    Material mat;

    std::vector<float> vertices;
    std::vector<GLuint> indices;
    MeshType mesh_type;

    bool is_loaded; // Loaded at least once
    bool is_fresh; // If there has been a reload since last update

private:
    void destroy() {}
};

#endif
