#include "mesh.h"
#include "../bufferobjectmanager.h"

extern BufferObjectManager *bufferObjectM;

Mesh::Mesh(std::string name) :
Asset(name),
is_loaded(false),
is_fresh(false)
{
}

void Mesh::load() {
    // (!) Different geometries could load the same mesh
    if (!is_loaded || !is_fresh) {
        bufferObjectM->buffer(this);
    }
}

void Mesh::unload() {
    // (!) Different geometries could unload the same mesh
    if (is_loaded) {
        // TODO
    }
}

BufferObjectType Mesh::getBufferObjectType() {
    return BufferObjectType::MESH;
}

void Mesh::setVertices(std::vector<float> _vertices) {
    vertices = _vertices;
    is_fresh = false;
}

void Mesh::setIndices(std::vector<GLuint> _indices) {
    indices = _indices;
    is_fresh = false;
}
