#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>
#include "asset.h"
#include "mesh.h"

class Geometry : public Asset
{
public:
    explicit Geometry(std::string name);
    virtual ~Geometry() {}

    void load();
    void unload();

    void setMesh(Mesh *_mesh) { mesh = _mesh; }
    Mesh* getMesh() { return mesh; }

protected:
    Mesh* mesh;
private:
};

#endif
