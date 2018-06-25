#include <string>
#include "bufferobjectmanager.h"
#include "assets/mesh.h"

BufferObjectManager::BufferObjectManager()
{
}

void BufferObjectManager::init() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
}

void BufferObjectManager::buffer(IBufferObject *object) {
    switch (object->getBufferObjectType()) {
        case BufferObjectType::MESH:
            Mesh *m_object = static_cast<Mesh*>(object);
            // TODO Set different VBO depending on mesh type
            auto vertices = m_object->getVertices();
            auto indices = m_object->getIndices();
            GLsizeiptr vertSize = vertices.size() * sizeof(vertices[0]);
            GLsizeiptr indSize = indices.size() * sizeof(indices[0]);

            // TODO BufferSubData
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, vertSize, &vertices[0], GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indSize, &indices[0], GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            printf("BINDING %ld vertices and %ld indices\n", vertices.size(), indices.size());
            break;
    }
}
