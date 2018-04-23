#include "mesh.h"

Mesh::Mesh(std::string name) :
Asset(name)
{
}

Mesh::load() {
    // (!) Different geometries could load the same mesh
}

Mesh::unload() {
    // (!) Different geometries could unload the same mesh
}
