#include "geometry.h"

Geometry::Geometry(std::string name) :
Asset(name)
{
}

Geometry::load() {
    mesh->load();
}

Geometry::unload() {
    mesh->unload();
}
