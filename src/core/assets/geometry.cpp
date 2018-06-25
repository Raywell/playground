#include "geometry.h"

Geometry::Geometry(std::string name) :
Asset(name)
{
}

void Geometry::load() {
    mesh->load();
}

void Geometry::unload() {
    mesh->unload();
}
