#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>
#include "asset.h"
#include "mesh.h"

class Geometry : Asset
{
public:
    explicit Geometry(std::string name);
    virtual ~Geometry() { destroy(); }

    void setMesh(Mesh *_mesh) { mesh = _mesh; }
    Mesh* getMesh() { return mesh; }

protected:
    Mesh* mesh;
private:
    void destroy() {
    }
};

#endif
