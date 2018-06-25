#ifndef IBUFFEROBJECT_H
#define IBUFFEROBJECT_H

enum class BufferObjectType {
    MESH
};

class IBufferObject
{
public:
    virtual void load() = 0; // Loads into the buffer
    virtual BufferObjectType getBufferObjectType() = 0;
protected:
private:
    // Object data location in the corresponing buffer object
    GLuint buffer_start = 0;
    GLuint buffer_end = 0;
};

#endif
